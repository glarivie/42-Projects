/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginApi42.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 10:24:04 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 17:57:46 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var axios = require('axios'),
	mongoose = require('../../../mongoose'),
	User = require('../../../user_schema');

var loginApi42 = function(req, res, next) {
	//console.log('QUERY : ', req.query);
	if (req.query && req.query.error) {
		console.log('ERROR : ', req.query.error);
		res.redirect('/users/register');
	} else if (req.query && req.query.code) {
		//console.log('CODE : ', req.query.code);
		axios.post('https://api.intra.42.fr/oauth/token', {
			grant_type : 'authorization_code',
			client_id : '592306c98554ede4bbefe02ae74260c297c9c793583eef689a0420af1b21cece',
			client_secret : '25351452b561e4eddf9e0d7b30cd91c5a9d53b5a7b247ce58e7d9a3a34cee7df',
			code : req.query.code,
			redirect_uri : 'http://localhost:3000/users/login/42'
		}).then(function (response) {
			//console.log('Asking for auth token');
			axios.get('https://api.intra.42.fr/v2/me', {
				headers : { 'Authorization' : response.data.token_type + ' ' + response.data.access_token }
			}).then(function (user) {
				//console.log('Get user infos from 42 Api');
				User.findOne({ access_token_42 : response.data.access_token }, function(err, user) {
					if (!err && user) {
						//console.log('User found, login !');
						console.log('A user try to login : ', user.username);
						req.session.id = user._id;
						req.session.username = user.username;
						req.session.mail = user.mail;
						req.session.firstname = user.firstname;
						req.session.lastname = user.lastname;
						req.session.language = user.language;

						res.redirect('/app/library');
					} else {
						console.log('Invalid request token : User not found or not registered');
						res.redirect('/users/login');
					}
				});
			}).catch(function (response) {
				console.log('error', response);
			});
		}).catch(function (response) {
			console.log('error ?');
		});

	}
};

module.exports = loginApi42;
