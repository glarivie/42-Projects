/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setNewPassword.js                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 19:26:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mhash = require('mhash'),
	mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	_ = require('../../lib/mylib');

var setNewPassword = function(req, res, next) {
	if (_.isValidPassword(_.protectEntry(req.body.password))) {
		User.findOne({ username : req.body.username }, function(err, user) {
			if (!err && user) {
				if (req.body.token === user.password) {
					User.update({ username : user.username }, { $set : { password : mhash('whirlpool', _.protectEntry(req.body.password)) } }, function() {
						res.send({ state : 'success' });
						console.log('New password set for : ', req.body.username);
					});
				} else {
					res.send({ state : 'bad token' });
					console.log('ERROR : Bad token');
				}
			} else {
				res.send({ state : 'bad username' });
				console.log('ERROR : Bad username');
			}
		});
	} else {
		res.send({ state : 'wrong password' });
		console.log('ERROR : Wrong password provided');
	}
};

module.exports = setNewPassword;
