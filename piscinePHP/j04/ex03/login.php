<?php

	session_start();
	include_once('auth.php');
	$loggued_on_user = "";

	if ($_GET['login'] && $_GET['passwd']) {
		if (auth($_GET['login'], $_GET['passwd'])) {
			$loggued_on_user = $_GET['login'];
			echo "OK\n";
		} else
			echo "ERROR\n";
	}

	$_SESSION['login'] = $loggued_on_user;

?>
