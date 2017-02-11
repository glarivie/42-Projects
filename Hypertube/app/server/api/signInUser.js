/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signInUser.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 16:34:00 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mhash = require('mhash'),
	mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	_ = require('../../lib/mylib');

function isValidUserInfos(user) {
	if (_.isValidUsername(_.protectEntry(user.username)) && _.isValidPassword(_.protectEntry(user.password)))
		return (true);
	return (false);
}

var signInUser = function(req, res, next) {
	if (isValidUserInfos(req.body.user)) {
		User.findOne({ username : req.body.user.username }, function(err, user) {
			if (!err && user) {
				if (user.password === mhash('whirlpool', _.protectEntry(req.body.user.password))) {
					console.log('A user try to login : ', user.username);
					req.session.id = user._id;
					req.session.username = user.username;
					req.session.mail = user.mail;
					req.session.firstname = user.firstname;
					req.session.lastname = user.lastname;
					req.session.language = user.language;

					res.send({ state : 'success' });
				} else {
					res.send({ state : 'wrong password' });
					console.log('Wrong password : ', req.body.user.username);
				}
			} else {
				res.send({ state : 'user not found' });
				console.log('User not found : ', req.body.user.username);
			}
		});
	} else
		res.redirect('/users/login');
};

module.exports = signInUser;
