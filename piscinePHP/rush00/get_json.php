<?php

function get_json() {
	if (file_exists('data/products.json')) {
		$file = file_get_contents('data/products.json');
		$json = json_decode($file, true);
	} else {
		echo 'Erreur : imposible d\'ouvrir le fichier \'data/products.json\' <br />';
	}
	return ($json);
}

?>
