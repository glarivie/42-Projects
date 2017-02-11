/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addNewUser.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 18:14:14 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mhash = require('mhash'),
	mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	_ = require('../../lib/mylib');

function isValidUserInfos(user) {
	if (_.isValidUsername(_.protectEntry(user.username)) && _.isValidPassword(_.protectEntry(user.password)) && _.isValidEmail(_.protectEntry(user.mail)) && _.isValidName(_.protectEntry(user.firstname)) && _.isValidName(_.protectEntry(user.lastname)))
		return (true);
	return (false);
}

var addNewUser = function(req, res, next) {
	if (isValidUserInfos(req.body.user)) {
		//console.log('Valid informations provided - OK !');
		User.findOne({ $or : [{ username : req.body.user.username }, { mail : req.body.user.mail }]}, function(err, user) {
			if (user) {
				res.send({ state : 'user already exist' });
			} else {
				var user = new User({
					token_twitter : req.body.user.token_twitter ? req.body.user.token_twitter : '',
					token_secret_twitter : req.body.user.token_secret_twitter ? req.body.user.token_secret_twitter : '',
					access_token_42 : req.body.user.access_token_42 ? req.body.user.access_token_42 : '',
					refresh_token_42 : req.body.user.refresh_token_42 ? req.body.user.refresh_token_42 : '',
					username : _.protectEntry(req.body.user.username),
					password : mhash('whirlpool', _.protectEntry(req.body.user.password)),
					mail : _.protectEntry(req.body.user.mail),
					firstname : _.protectEntry(req.body.user.firstname),
					lastname : _.protectEntry(req.body.user.lastname),
					avatar : req.body.user.avatar,
					language : 'EN'
				});

				user.save(function(err, user) {
					if (err)
						console.log('User save error : ', err);
					else {
						console.log('New user registered : ', user.username);
						req.session.id = user._id;
						req.session.username = user.username;
						req.session.mail = user.mail;
						req.session.firstname = user.firstname;
						req.session.lastname = user.lastname;
						req.session.language = user.language;
						console.log('session', req.session);

						res.send({ state : 'success' });
					}
				});
			}
		});
	} else
		res.redirect('/users/register');
};

module.exports = addNewUser;
