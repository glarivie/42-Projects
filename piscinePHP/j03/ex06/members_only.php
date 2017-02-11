<?php

	header('WWW-Authenticate: Basic realm="Espace membres"');
	header('HTTP/1.0 401 Unauthorized');

	if ($_SERVER['PHP_AUTH_USER'] === 'zaz' && $_SERVER['PHP_AUTH_PW'] === 'jaimelespetitsponeys') {
		$path = '../img/42.png';
		$type = 'png'; // pathinfo($path, PATHINFO_EXTENSION);
		$data = file_get_contents($path);
		$base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
		echo	'<html><body>
	Bonjour Zaz<br />
	<img src=\'' . $base64 . '\'>
	</body></html>';
	} else {
		echo '<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n';
	}

?>
