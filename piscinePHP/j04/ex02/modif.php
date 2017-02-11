<?php

	$private = 'private/passwd';

	if ($_POST['login'] && $_POST['newpw'] && $_POST['oldpw'] && $_POST['submit'] === "OK") {
		if (file_exists($private)) {
			$file = unserialize(file_get_contents($private));
			if ($file) {
				foreach ($file as $user) {
					if ($user['login'] === $_POST['login']) {
						if ($user['passwd'] === hash('whirlpool', $_POST['oldpw'], FALSE)) {
							$user['passwd'] = hash('whirlpool', $_POST['newpw'], FALSE);
							if (file_put_contents($private, serialize($file)) !== FALSE) {
								echo "OK\n";
								return ;
							}
						}
					}
				}
			}
		}
	}

	echo "ERROR\n";
	return ;
?>
