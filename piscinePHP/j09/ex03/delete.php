<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.php                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:51:35 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/14 09:51:38 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	$json = json_decode(file_get_contents('php://input'), true);
	$fd = fopen('list.csv', 'w');

	foreach ($json['todos'] as $todo) {
		fputcsv($fd, $todo, ';');
	}

	fclose($fd);
?>
