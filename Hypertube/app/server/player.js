/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:06:36 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/11 17:39:30 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../mongoose'),
	User = require('../user_schema'),
	Movie = require('../movie_schema'),
	_ = require('lodash');

var player = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			Movie.findOne({ _id : req.params.id }, function(err, movie) {
				if (!err && movie) {
					movie.director = movie.director ? movie.director : 'N/A';
					movie.runtime = movie.runtime ? movie.runtime : 'N/A';
					movie.actors = movie.actors ? movie.actors.join(', ') : 'N/A';
					movie.genres = movie.genres ? movie.genres.join(' | ') : 'N/A';
					movie.rated = movie.rated ? movie.rated : 'N/A';

					for (var j = 0; j < movie.resolutions.length; j++) {
						if (movie.resolutions[j].resolution !== req.params.resolution) {
							movie.resolutions[j].link = '/player/html5/' + movie._id + '/' + movie.resolutions[j].resolution;
							if (movie.resolutions[j].resolution === 'undefined')
								movie.resolutions[j].resolution = 'N/A';
						}
					}

					res.render('player', {
						isApp : true,
						title : 'Hypertube - Player',
						firstname : _.capitalize(user.firstname),
						language : user.language,
						movie : movie,
						params : {
							id : req.params.id,
							resolution : req.params.resolution
						}
					});
				} else {
					console.log('Movie not found at this url');
					res.redirect('/app/library');
				}
			});
		} else {
			console.log('User not found or not logged in, redirect to home page');
			res.redirect('/');
		}
	});
};

module.exports = player;
