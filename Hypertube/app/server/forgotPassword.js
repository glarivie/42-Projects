/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forgotPassword.js                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 16:59:32 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var forgotPassword = function(req, res, next) {
	//console.log(req.session);
	res.render('forgot-password', {
		isApp : false,
		title : 'Hypertube - Forgot Password'
	});
};

module.exports = forgotPassword;
