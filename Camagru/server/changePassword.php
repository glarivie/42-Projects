<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');
require_once($rootDIR . '/lib/redirect.php');
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/formCheck.php');
require_once($rootDIR . '/lib/sendMail.php');

if (isset($_POST['email'])) {
	if (checkMail(trim($_POST['email'])))
		renderTemplate('error.php', null);
	else {
		$result = $bdd->query('SELECT user_login AS login, user_password AS pwd FROM camagru_users WHERE user_email = ' . $bdd->quote(trim($_POST['email'])));
		$result = $result->fetch();
		sendRecoverMail($result['login'], trim($_POST['email']));
		redirect('/', 0);
	}
}

?>
