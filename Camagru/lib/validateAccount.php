<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');
require_once($rootDIR . '/lib/redirect.php');
require_once($rootDIR . '/lib/getRequestURI.php');
require_once($rootDIR . '/lib/renderTemplate.php');


function validateAccount($login, $validationCode) {
	global $bdd;
	$result = $bdd->query('SELECT user_password AS pwd FROM camagru_users WHERE user_login = ' . $bdd->quote($login));
	$result = $result->fetch();
	if ($validationCode === $result['pwd']) {
		$bdd->query('UPDATE camagru_users SET user_registered = 1 WHERE user_login = ' . $bdd->quote($login));
		$_SESSION['login'] = $login;
		redirect('/app', 0);
	} else
		renderTemplate('error.php', null);
}

function isRegisteredUser($login) {
	global $bdd;
	$result = $bdd->query('SELECT user_registered AS ok FROM camagru_users WHERE user_login = ' . $bdd->quote($login));
	$result = $result->fetch();
	if ($result['ok'] == 1)
		return (TRUE);
	return (FALSE);
}

?>
