/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logout.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 23:17:56 by glarivie          #+#    #+#             */
/*   Updated: 2016/06/09 18:24:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

var logout = function(req, res, next) {
	req.session.destroy(function(err) {
		if (!err)
			res.redirect('/');
	});
};

module.exports = logout;
