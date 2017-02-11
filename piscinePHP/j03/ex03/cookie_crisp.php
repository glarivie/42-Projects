<?php

	if ($_GET['action'] === 'set' && isset($_GET['name'])) {
		if (!setcookie($_GET['name'], $_GET['value'], time() + 3600, '/'))
			echo "Cookie creation failed\n";
	}
	if ($_GET['action'] === 'get' && isset($_GET['name']) && $_COOKIE[$_GET['name']])
		echo $_COOKIE[$_GET['name']] . "\n";
	if ($_GET['action'] === 'del' && isset($_GET['name'])) {
		unset($_COOKIE[$_GET['name']]);
		setcookie($_GET['name'], '', time() - 3600);
	}

?>
