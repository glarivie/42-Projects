/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeSearch.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/11 16:14:45 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../mongoose'),
	User = require('../user_schema'),
	Movie = require('../movie_schema'),
	promise = require('promise'),
	search = require('./api/search'),
	_ = require('lodash');

var makeSearch = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			search(req).then(function(movies) {
				for (var i = 0; i < movies.length; i++) {
					movies[i].director = movies[i].director ? movies[i].director.split(', ')[0] : 'N/A';
					movies[i].runtime = movies[i].runtime ? movies[i].runtime : 'N/A';
					movies[i].actors = movies[i].actors ? movies[i].actors.slice(2).join(', ') : 'N/A';
					if (movies[i].plot)
						movies[i].plot = movies[i].plot.length > 105 ? movies[i].plot.substring(0, 105) + '[...]' : movies[i].plot;
					movies[i].genres = movies[i].genres ? movies[i].genres.join(' | ') : 'N/A';
					movies[i].rated = movies[i].rated ? movies[i].rated : 'N/A';

					for (var j = 0; j < movies[i].resolutions.length; j++) {
						movies[i].resolutions[j].link = '/player/html5/' + movies[i]._id + '/' + movies[i].resolutions[j].resolution;
						if (j === 0)
							movies[i].defaultLink = '/player/html5/' + movies[i]._id + '/' + movies[i].resolutions[j].resolution;
						if (movies[i].resolutions[j].resolution === 'undefined')
							movies[i].resolutions[j].resolution = 'N/A';
					}


				}

				res.render('search', {
					isApp : true,
					title : 'Hypertube - Search',
					firstname : _.capitalize(user.firstname),
					language : user.language,
					movies : movies
				});
			}, function(err) {
				if (err)
					console.log('Movie search error : ', err);
			});
		} else {
			console.log('User not found or not logged in, redirect to home page');
			res.redirect('/');
		}
	});
};

module.exports = makeSearch;
