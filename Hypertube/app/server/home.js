/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/05 23:43:48 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var home = function(req, res, next) {
	//console.log(req.session);
	res.render('home', {
		isApp : false,
		title : 'Hypertube - Home'
	});
};

module.exports = home;
