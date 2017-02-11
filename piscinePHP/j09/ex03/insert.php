<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.php                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:51:13 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/14 09:51:26 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	$json = json_decode(file_get_contents('php://input'), true);
	if ($json) {
		$fd = fopen('list.csv', 'w');

		foreach ($json['todos'] as $todo) {
			fputcsv($fd, $todo, ';');
		}

		fclose($fd);
	} else {
		echo 'error'. PHP_EOL;
	}
?>
