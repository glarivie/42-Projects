/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetPassword.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 19:04:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var resetPassword = function(req, res, next) {
	//console.log(req.session);
	res.render('reset-password', {
		isApp : false,
		title : 'Hypertube - Reset Password',
		username : req.params.username,
		token : req.params.token
	});
};

module.exports = resetPassword;
