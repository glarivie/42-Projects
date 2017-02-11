/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getSubtitles.js                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:06:36 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 19:25:43 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	Movie = require('../../movie_schema'),
	OpenSubtitles = require('opensubtitles-api'),
	fs = require('fs'),
	request = require('request'),
	zlib = require('zlib'),
	srt2vtt = require('srt2vtt'),
	OS = new OpenSubtitles('OSTestUserAgent'),
	appRoot = require('app-root-path');

var getSubtitles = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			Movie.findOne({ _id : req.body.movieID }, function(err, movie) {
				if (!err && movie) {
					console.log('---------------------------------------------');
					console.log('Movie : ', movie.title);

					var filename,
						lang = user.language.toLowerCase();

					for (var index = 0; index < movie.resolutions.length; index++) {
						if (movie.resolutions[index].resolution === req.body.movieResolution)
							filename = movie.resolutions[index].data.name;
					}
					console.log('File : ', filename);

					OS.search({
						filename : filename,
						//imdbid: 'tt0314979',
						extensions : ['srt'],
						gzip : true
					}).then(function (subtitles) {
						if (subtitles[lang] && subtitles[lang].encoding.toLowerCase() !== 'cp1252') {
							console.log('Subtitles found: ', lang.toUpperCase(), subtitles[lang].encoding);

							request({
								url : subtitles[lang].url,
								encoding : null,
								gzip : true
							}, function (err, response, data) {
								if (err) console.log(err);
								zlib.unzip(data, function (err, buffer) {
									if (err) console.log(err);
									fs.open(appRoot.path + '/public/sub/sub.vtt', 'a+', function(err, fd) {
										if (err) console.log(err);
										srt2vtt(buffer, function(err, vttData) {
											if (err) console.log(err);
											fs.writeFile(fd, vttData, function(err) {
												if (err) console.log(err);
												fs.close(fd, function() {
													console.log('File descriptor closed, VTT file written');
													res.send({ state : 'success' });
												});
											});
										});
									});
								});
							});
						} else
							throw 'No subtitles found in your language : ' + lang.toUpperCase();
					}).catch(function (error) {
						console.error('Subtitles error : ', error);
					});
					console.log('---------------------------------------------');
				} else {
					console.log('Movie not found at this url');
					res.send({ state : 'movie not found' });
				}
			});
		} else {
			console.log('User not found or not logged in, redirect to home page');
			res.send({ state : 'user not found' });
		}
	});
};

module.exports = getSubtitles;
