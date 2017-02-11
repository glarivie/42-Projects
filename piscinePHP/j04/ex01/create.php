<?php

	if (!$_POST['login'] || !$_POST['passwd'] || $_POST['submit'] !== "OK") {
		echo "ERROR\n";
		return ;
	}

	if ($_POST['login'] && $_POST['passwd'] && $_POST['submit'] === "OK") {
		$private = 'private/passwd';
		$passwd = hash('whirlpool', $_POST['passwd'], FALSE);

		if (file_exists($private)) {
			$file = unserialize(file_get_contents($private));
			foreach ($file as $user) {
				foreach ($user as $key => $value) {
					if ($key === 'login' && $value === $_POST['login']) {
						echo "ERROR\n";
						return ;
					}
				}
			}
		} else
			mkdir('private');

		$file[] = [
			'login'		=>	$_POST['login'],
			'passwd'	=>	$passwd,
		];

		if (file_put_contents($private, serialize($file)) !== FALSE)
			echo "OK\n";
	}
?>
