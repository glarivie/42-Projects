<?php

session_start();
$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/formCheck.php');
require_once($rootDIR . '/lib/redirect.php');

if ($_SESSION['login']) {
	clearSession();
	session_destroy();
	redirect('/', 0);
}

?>
