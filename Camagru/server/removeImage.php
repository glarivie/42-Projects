<?php

	session_start();
	$rootDIR = dirname(__DIR__, 1);
	require_once($rootDIR . '/config/database.php');

	$imgID = intval(file_get_contents('php://input'));

	$bdd->query('DELETE FROM camagru_img WHERE img_id = ' . intval($imgID));

?>
