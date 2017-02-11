<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.php                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:51:30 by glarivie          #+#    #+#             */
/*   Updated: 2016/04/14 10:50:42 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	if (!file_exists('list.csv')) {
		file_put_contents('list.csv', null);
	}

	if (filesize('list.csv') !== 0) {
		$fd = fopen('list.csv', 'r');
		for ($index = 0; $line = fgetcsv($fd, FALSE, ';'); $index++) {
			$data['todos'][$index]['id'] = $line[0];
			$data['todos'][$index]['todo'] = $line[1];
		}
		$json = json_encode($data);
		fclose($fd);
		echo ($json);
	} else
		return ;
?>
