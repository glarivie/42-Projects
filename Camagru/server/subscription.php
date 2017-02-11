<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');
require_once($rootDIR . '/lib/formCheck.php');
require_once($rootDIR . '/lib/redirect.php');
require_once($rootDIR . '/lib/sendMail.php');

session_start();

$_SESSION['errors'] = 0;

if (isset($_POST['login'])) {
	if (!checkLogin(trim($_POST['login'])))
		$_SESSION['errors']++;
	else
		$_SESSION['login'] = trim($_POST['login']);
}

if (isset($_POST['password']) && isset($_POST['password-check'])) {
	if (!checkPasswdMatches(trim($_POST['password']), trim($_POST['password-check'])))
		$_SESSION['errors']++;
	else
		$_SESSION['password'] = trim($_POST['password']);
}

if (isset($_POST['email'])) {
	if (!checkMail(trim($_POST['email'])))
		$_SESSION['errors']++;
	else
		$_SESSION['email'] = trim($_POST['email']);
}

if ($_SESSION['errors'] === 0 && isset($_POST['login']) && isset($_POST['password']) && isset($_POST['password-check']) && isset($_POST['email'])) {
	unset($_SESSION['errors']);
	$bdd->query('INSERT INTO camagru_users VALUES (NULL, ' . $bdd->quote($_POST["login"]) . ', ' . $bdd->quote(hash("whirlpool", $_POST["password"])) . ', ' . $bdd->quote($_POST["email"]) . ', 0, 0)');
	sendSubscriptionMail($_SESSION['login'], $_SESSION['email']);
	redirect('/success', 0);
} else
	redirect('/', 0);

?>
