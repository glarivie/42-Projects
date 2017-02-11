/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMovies.js                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:47:17 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 20:23:18 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../../mongoose'),
	Movie = require('../../movie_schema');

var getMovies = function(req, res, next) {
	Movie.find()
		.skip(req.body.skip)
		.limit(req.body.limit)
		.sort({ [req.body.sort] : req.body.order })
		.exec(function(err, movies) {
			if (!err && movies && movies.length > 0) {
				for (var i = 0; i < movies.length; i++) {
					movies[i].director = movies[i].director ? movies[i].director.split(', ')[0] : 'N/A';
					movies[i].runtime = movies[i].runtime ? movies[i].runtime : 'N/A';
					movies[i].actors = movies[i].actors ? movies[i].actors.slice(2).join(', ') : 'N/A';
					if (movies[i].plot)
						movies[i].plot = movies[i].plot.length > 105 ? movies[i].plot.substring(0, 105) + '[...]' : movies[i].plot;
					movies[i].genres = movies[i].genres ? movies[i].genres.join(' | ') : 'N/A';
					movies[i].rated = movies[i].rated ? movies[i].rated : 'N/A';
				}
				res.send({ state : 'success', movies : movies });
			} else {
				console.log('No movies found, infinite scroll stop.')
				res.send({ state : 'No movies found' });
			}
		});
};

module.exports = getMovies;
