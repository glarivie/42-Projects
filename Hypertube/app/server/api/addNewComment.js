/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addNewComment.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/11 18:09:39 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	Movie = require('../../movie_schema'),
	shortid = require('shortid'),
	_ = require('lodash');

var addNewComment = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			Movie.findOne({ _id : req.body.id }, function(err, movie) {
				if (!err && movie) {
					var comments = movie.comments,
						comment = {
							id : shortid.generate(),
							date : Date.now(),
							text : _.escape(req.body.comment),
							user : {
								id : user._id,
								firstname : _.capitalize(user.firstname),
								lastname : _.upperCase(user.lastname),
								avatar : user.avatar
							}
						};
						
					comments.unshift(comment);

					Movie.update(
						{ _id : req.body.id },
						{ $set : { comments : comments } },
						function() {
							console.log('SUCCESS : comment has been posted');
							res.send({
								state : 'success',
								comment : comment
							});
						}
					);
				} else {
					console.log('ERROR : comment not posted, movie not found');
					res.send({ state : 'movie not found' });
				}
			});
		} else {
			console.log('ERROR : comment not posted, user not found');
			res.send({ state : 'user not found' });
		}
	});
};

module.exports = addNewComment;
