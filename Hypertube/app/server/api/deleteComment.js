/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteComment.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/08 11:25:11 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var mhash = require('mhash'),
	mongoose = require('../../mongoose'),
	User = require('../../user_schema'),
	Movie = require('../../movie_schema'),
	_ = require('lodash');

var deleteComment = function(req, res, next) {
	User.findOne({ username : req.session.username }, function(err, user) {
		if (!err && user) {
			Movie.findOne({ _id : req.body.movieID }, function(err, movie) {
				if (!err && movie) {
					var comments = movie.comments,
						isDelete = false;

					for (var index = 0; index < comments.length; index++) {
						if (comments[index].id === req.body.commentID && comments[index].user.id == user._id) {
							comments.splice(index, 1);
							isDelete = true;
						}
					}

					if (isDelete) {
						Movie.update(
							{ _id : req.body.movieID },
							{ $set : { comments : comments } },
							function() {
								console.log('SUCCESS : comment has been deleted');
								res.send({ state : 'success' });
							}
						);
					} else {
						console.log('ERROR : comment not found');
						res.send({ state : 'comment not found' });
					}
				} else {
					console.log('ERROR : comment not posted, movie not found');
					res.send({ state : 'movie not found' });
				}
			});
		}
	});
};

module.exports = deleteComment;
