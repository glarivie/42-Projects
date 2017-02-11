<?php

	session_start();
	$rootDIR = dirname(__DIR__, 1);
	require_once($rootDIR . '/config/database.php');

	$imgID = intval(file_get_contents('php://input'));

	$likes = $bdd->query('SELECT img_likes AS nb FROM camagru_img WHERE img_id = ' . $imgID);
	$likes = $likes->fetch();
	$likes = intval($likes['nb']);
	$likes++;
	$bdd->query('UPDATE camagru_img SET img_likes = ' . $likes . ' WHERE img_id = ' . $imgID);

	echo $likes;

?>
