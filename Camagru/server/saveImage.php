<?php

	session_start();
	$rootDIR = dirname(__DIR__, 1);
	require_once($rootDIR . '/config/database.php');
	require_once($rootDIR . '/lib/imageLib.php');

	$json = json_decode(file_get_contents('php://input'));
	$moustachePath = '/public/img/moustache.png';
	$lunettesPath = '/public/img/lunettes.png';
	$hatPath = '/public/img/hat.png';

	$base64 = explode(',', $json->data[0]->img)[1];
	$webcam = imagecreatefromstring(base64_decode($base64));

	if ($json->data[0]->moustache) {
		$moustache = imagecreatefrompng($rootDIR . $moustachePath);
		$miniMoustache = miniaturePNG($moustache, $json->data[0]->moustache->width, $json->data[0]->moustache->height);
		imagesMerge($webcam, $miniMoustache, intval($json->data[0]->moustache->x), intval($json->data[0]->moustache->y), 0, 0, intval($json->data[0]->size->width), intval($json->data[0]->size->height), 100);
		imagedestroy($moustache);
		imagedestroy($miniMoustache);
	}
	if ($json->data[0]->lunettes) {
		$lunettes = imagecreatefrompng($rootDIR . $lunettesPath);
		$miniLunettes = miniaturePNG($lunettes, $json->data[0]->lunettes->width, $json->data[0]->lunettes->height);
		imagesMerge($webcam, $miniLunettes, intval($json->data[0]->lunettes->x), intval($json->data[0]->lunettes->y), 0, 0, intval($json->data[0]->size->width), intval($json->data[0]->size->height), 100);
		imagedestroy($lunettes);
		imagedestroy($miniLunettes);
	}
	if ($json->data[0]->hat) {
		$hat = imagecreatefrompng($rootDIR . $hatPath);
		$miniHat = miniaturePNG($hat, $json->data[0]->hat->width, $json->data[0]->hat->height);
		imagesMerge($webcam, $miniHat, intval($json->data[0]->hat->x), intval($json->data[0]->hat->y), 0, 0, intval($json->data[0]->size->width), intval($json->data[0]->size->height), 100);
		imagedestroy($hat);
		imagedestroy($miniHat);
	}

	ob_start();
	imagejpeg($webcam);
	$imageData = ob_get_contents();
	ob_end_clean();
	$base64 = "data:image/jpeg;base64," . base64_encode($imageData);
	echo $base64;
	imagedestroy($webcam);

	$author_id = $bdd->query('SELECT user_id AS id FROM camagru_users WHERE user_login = ' . $bdd->quote($_SESSION['login']));
	$author_id = $author_id->fetch();
	$author_id = $author_id['id'];
	$bdd->query('INSERT INTO camagru_img VALUES (NULL, ' . $bdd->quote($base64) . ', ' . intval($author_id) . ', DEFAULT, DEFAULT, DEFAULT)');

?>
