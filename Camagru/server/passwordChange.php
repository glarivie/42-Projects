<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');
require_once($rootDIR . '/lib/redirect.php');
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/formCheck.php');

if (isset($_POST['password']) && isset($_POST['password-check']) && isset($_POST['login']) && isset($_POST['oldpwd'])) {
	if (isUserExist($_POST['login']) && checkPasswdMatches($_POST['password'], $_POST['password-check'])) {
		$checkOldPwd = $bdd->query('SELECT user_password AS whirlpool FROM camagru_users WHERE user_login = ' . $bdd->quote($_POST['login']));
		$checkOldPwd = ($checkOldPwd->fetch())['whirlpool'];
		if ($checkOldPwd == $_POST['oldpwd']) {
			$bdd->query('UPDATE camagru_users SET user_password = ' . $bdd->quote(hash('whirlpool', $_POST['password'])) . ' WHERE user_login = ' . $bdd->quote($_POST['login']));
			redirect('/', 0);
		} else
			renderTemplate('error.php', null);
	} else
		renderTemplate('error.php', null);
} else
	renderTemplate('error.php', null);

?>
