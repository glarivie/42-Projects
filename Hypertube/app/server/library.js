/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 20:04:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../mongoose'),
	User = require('../user_schema'),
	Movie = require('../movie_schema'),
	_ = require('lodash');

var library = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {

			res.render('library', {
				isApp : true,
				title : 'Hypertube - Library',
				isLibrary : true,
				language : user.language,
				firstname : _.capitalize(user.firstname)
			});

		} else {
			console.log('User not found or not logged in, redirect to home page');
			res.redirect('/');
		}
	});
};

module.exports = library;
