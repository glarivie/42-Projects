<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');
require_once($rootDIR . '/lib/formCheck.php');
require_once($rootDIR . '/lib/redirect.php');

session_start();

if (isset($_POST['login']) && isset($_POST['password'])) {
	if (isUserExist(trim($_POST['login']))) {
		$result = $bdd->query('SELECT user_password AS pwd FROM camagru_users WHERE user_login =' . $bdd->quote(trim($_POST['login'])));
		$result = $result->fetch();
		$submitPWD = hash('whirlpool', trim($_POST['password']));
		if ($submitPWD === $result['pwd']) {
			$_SESSION['login'] = trim($_POST['login']);
			$_SESSION['is_connected'] = TRUE;
			redirect('/app', 0);
		} else
			redirect('/', 0);
	} else
		redirect('/', 0);
} else
	redirect('/', 0);

?>
