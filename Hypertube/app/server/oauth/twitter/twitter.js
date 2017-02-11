/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twitter.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:46:24 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/13 18:15:19 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var axios = require('axios'),
	request = require('request'),
	qs = require('querystring'),
	mongoose = require('../../../mongoose'),
	User = require('../../../user_schema');

//URL To obtain Request Token from Twitter
var requestTokenUrl = 'https://api.twitter.com/oauth/request_token';

//To be obtained from the app created on Twitter
var CONSUMER_KEY = 'Kww80MJ5HDjhq6OaipjSHzrU2';
var CONSUMER_SECRET = 'QveNodydrrTXUvvz573dXOeuJDpPzv1Er07cqqCKGkiS2HzpmW';

//Oauth Object to be used to obtain Request token from Twitter
var oauth = {
	callback : 'http://localhost:3000/users/signin/twitter',
	consumer_key  : CONSUMER_KEY,
	consumer_secret : CONSUMER_SECRET
};

var oauthToken = '';
var oauthTokenSecret = '';

exports.requestToken = function(req, res) {
	request.post({
		url : requestTokenUrl,
		oauth : oauth
	}, function (e, r, body) {
		//Parsing the Query String containing the oauth_token and oauth_secret.
		var reqData = qs.parse(body);
		oauthToken = reqData.oauth_token;
		oauthTokenSecret = reqData.oauth_token_secret;
		//Step-2 Redirecting the user by creating a link and allowing the user to click the link
		var uri = 'https://api.twitter.com/oauth/authenticate' + '?' + qs.stringify({ oauth_token : oauthToken });
		res.redirect(uri);
	});
};

exports.accessToken = function(req, res) {
	if (req.query) {
		var authReqData = req.query;
		oauth.token = authReqData.oauth_token;
		oauth.token_secret = oauthTokenSecret;
		oauth.verifier = authReqData.oauth_verifier;

		var accessTokenUrl = 'https://api.twitter.com/oauth/access_token';
		//Step-3 Converting the request token to an access token
		request.post({
			url : accessTokenUrl,
			oauth : oauth
		}, function(e, r, body) {
			var authenticatedData = qs.parse(body),
				access = {
					oauth_token : authenticatedData.oauth_token,
					oauth_token_secret : authenticatedData.oauth_token_secret,
					user_id : authenticatedData.user_id,
					screen_name : authenticatedData.screen_name
				},
				userShowUrl = 'https://api.twitter.com/1.1/users/show.json' + '?' + qs.stringify({ user_id : authenticatedData.user_id, screen_name : authenticatedData.screen_name, include_entities : false });

			var authenticationData = {
				consumer_key : CONSUMER_KEY,
				consumer_secret : CONSUMER_SECRET,
				token : authenticatedData.oauth_token,
				token_secret : authenticatedData.oauth_token_secret
			};
			//Step-4 retreive user data
			request.get({
				url : userShowUrl,
				oauth: authenticationData,
				json:true
			}, function(e, r, body) {
				var newUser = {
					token_twitter : authenticatedData.oauth_token,
					token_secret_twitter : authenticatedData.oauth_token_secret,
					username : body.screen_name,
					password : 'hypertube1234',
					mail : 'mail@hypertube.com',
					firstname : 'firstname',
					lastname : 'lastname',
					avatar : body.profile_image_url
				};
				axios.post('http://localhost:3000/api/user/new', {
					user : newUser
				}).then(function(resp) {
					if (resp.data.state === 'success')
						res.redirect('/app/library');
					if (resp.data.state === 'user already exist') {
						User.findOne({ username : newUser.username }, function(err, user) {
							if (!err && user) {
								req.session.id = user._id;
								req.session.username = user.username;
								req.session.mail = user.mail;
								req.session.firstname = user.firstname;
								req.session.lastname = user.lastname;
								req.session.language = user.language;

								res.redirect('/app/library');
							} else {
								console.log(err);
								res.redirect('/');
							}
						});
					} else {
						console.log('ERROR : ', resp.data.state);
						res.redirect('/users/register');
					}
				});
			});
		});
	}
};
