<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');

function checkLogin($login) {
	global $bdd;
	if ($login == '' || strlen($login) < 3 || strlen($login) > 32)
		return (FALSE);
	$result = $bdd->query("SELECT COUNT(*) AS login FROM camagru_users WHERE user_login = " . $bdd->quote($login));
	$result = $result->fetch();
	if ($result['login'] > 0)
		return (FALSE);
	return (TRUE);
}

function isUserExist($login) {
	global $bdd;
	$result = $bdd->query("SELECT COUNT(*) AS login FROM camagru_users WHERE user_login = " . $bdd->quote($login));
	$result = $result->fetch();
	if ($result['login'] > 0)
		return (TRUE);
	return (FALSE);
}

function checkPasswd($passwd) {
	if ($passwd == '' || strlen($passwd) < 4 || strlen($passwd) > 50)
		return (FALSE);
	return (TRUE);
}

function checkPasswdMatches($passwd, $passwd2) {
	if ($passwd != $passwd2 && $passwd != '' && $passwd2 != '')
		return (FALSE);
	return checkPasswd($passwd);
}

function checkMail($email) {
	global $bdd;
	if ($email == '' || !preg_match('#^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$#is', $email))
		return (FALSE);
	$result = $bdd->query("SELECT COUNT(*) AS mail FROM camagru_users WHERE user_email = " . $bdd->quote($email));
	$result = $result->fetch();
	if ($result['mail'] > 0)
		return (FALSE);
	return (TRUE);
}

function clearSession() {
	foreach($_SESSION as $key => $value)
		unset($_SESSION[$key]);
}

?>
