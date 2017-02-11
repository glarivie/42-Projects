/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editUser.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/09 15:53:41 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mhash = require('mhash'),
	mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	_ = require('../../lib/mylib');

var editUser = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			if (req.body.state.hasValidPassword === "true" && _.isValidPassword(_.protectEntry(req.body.user.password))) {

				User.update(
					{ username : req.session.username },
					{ $set : { password : mhash('whirlpool', _.protectEntry(req.body.user.password)) } },
					function() {
						console.log('Password updated for user : ', req.session.username);
					}
				);
			}
			if (req.body.state.hasValidEmail === "true" && _.isValidEmail(_.protectEntry(req.body.user.mail))) {

				User.update(
					{ username : req.session.username },
					{ $set : { mail : _.protectEntry(req.body.user.mail) } },
					function() {
						console.log('Email updated for user : ', req.session.username);
						req.session.mail = req.body.user.mail;
					}
				);
			}
			if (req.body.state.hasValidFirstname === "true" && _.isValidName(_.protectEntry(req.body.user.firstname))) {

				User.update(
					{ username : req.session.username },
					{ $set : { firstname : _.protectEntry(req.body.user.firstname) } },
					function() {
						console.log('Firstname updated for user : ', req.session.username);
						req.session.firstname = req.body.user.firstname;
					}
				);
			}
			if (req.body.state.hasValidLastname === "true" && _.isValidName(_.protectEntry(req.body.user.lastname))) {

				User.update(
					{ username : req.session.username },
					{ $set : { lastname : _.protectEntry(req.body.user.lastname) } },
					function() {
						console.log('Lastname updated for user : ', req.session.username);
						req.session.lastname = req.body.user.lastname;
					}
				);
			}
			if (req.body.state.hasValidAvatar === "true") {

				User.update(
					{ username : req.session.username },
					{ $set : { avatar : req.body.user.avatar } },
					function() {
						console.log('Avatar updated for user : ', req.session.username);
					}
				);
			}

			res.send({ state : 'success' });
		} else {
			console.log('User infos not updated, user not found');
			res.send({ state : 'user not found '});
		}
	});
};

module.exports = editUser;
