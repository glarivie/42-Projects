/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addNewVisit.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/11 18:21:19 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	Movie = require('../../movie_schema'),
	_ = require('lodash');

var addNewVisit = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			var history = user.history ? user.history : [];

			Movie.findOne({ _id : req.body.movieID }, function(err, movie) {
				if (!err && movie) {
					var alreadyVisited = false;

					for (var i = 0; i < history.length; i++) {
						if (history[i].title === movie.title)
							alreadyVisited = true;
					}

					if (!alreadyVisited) {
						var movie_copy = {
							id : movie._id,
							title : movie.title,
							poster : movie.poster,
							resolution : movie.resolutions[0].resolution,
							link : '/player/html5/' + movie._id + '/' + movie.resolutions[0].resolution
						};

						history.unshift(movie_copy);
						history.splice(4);

						User.update(
							{ username : req.session.username },
							{ $set : { history : history } },
							function() {
								console.log(history[0].defaultLink);
								console.log('SUCCESS : New movie added to user history');
								res.send({ state : 'success' });
							}
						);
					} else
						res.send({ state : 'already visited' });
				} else {
					console.log('ERROR : history not updated, movie not found');
					res.send({ state : 'movie not found' });
				}
			});
		} else {
			console.log('ERROR : history not updated, user not found');
			res.send({ state : 'user not found' });
		}
	});
};

module.exports = addNewVisit;
