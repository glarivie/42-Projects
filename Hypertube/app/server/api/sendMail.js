/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendMail.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 17:45:16 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	_ = require('../../lib/mylib'),
	nodemailer = require('nodemailer'),
	sendmailTransport = require('nodemailer-sendmail-transport'),
	transporter = nodemailer.createTransport(sendmailTransport({ path : '/usr/sbin/sendmail' }));

var sendMail = function(req, res, next) {
	if (_.isValidEmail(_.protectEntry(req.body.mail))) {
		User.findOne({ mail : req.body.mail }, function(err, user) {
			if (!err && user) {
				var magicLink = 'http://localhost:3000/users/reset-password/' + user.username + '/' + user.password,
					options = {
					from : '"Hypertube App" <noreply@hypertube-app.42.fr>',
					to : req.body.mail,
					subject : '✔ Let\'s reset your password',
					html : '<p>Follow <a href="' + magicLink + '" target="_blank">this link</a> to reset your password</p>'
				};

				transporter.sendMail(options, function(err, info) {
					if (err)
						console.log(err);
					else {
						res.send({ state : 'success' });
						console.log('Reset password asked by : ', user.username);
					}
				});
			} else {
				res.send({ state : 'user not found' });
				console.log('ERROR : Password reset not sent, user not found.');
			}
		});
	} else {
		res.send({ state : 'invalid email' });
		console.log('ERROR : Mail address provided is invalid : ', req.body.mail);
	}
};

module.exports = sendMail;
