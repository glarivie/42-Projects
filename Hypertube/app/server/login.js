/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   login.js                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 10:41:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var login = function(req, res, next) {
	//console.log(req.session);
	res.render('login', {
		isApp : false,
		title : 'Hypertube - Login'
	});
};

module.exports = login;
