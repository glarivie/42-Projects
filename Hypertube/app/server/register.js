/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/06 10:30:32 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var register = function(req, res, next) {
	//console.log(req.session);
	res.render('register', {
		isApp : false,
		title : 'Hypertube - Register'
	});
};

module.exports = register;
