<?php

	$private = 'private/passwd';

	function auth($login, $passwd) {
		$file = unserialize(file_get_contents($private));
		if ($file) {
			foreach ($file as $user) {
				if ($user['login'] === $login && $user['passwd'] === hash('whirlpool', $passwd, FALSE)) {
					return (TRUE);
				}
			}
		}
	}

?>
