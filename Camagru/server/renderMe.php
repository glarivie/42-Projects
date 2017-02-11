<?php

session_start();

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/validateAccount.php');
require_once($rootDIR . '/config/database.php');

function renderMe() {
	if (isRegisteredUser($_SESSION['login'])) {
		global $bdd;
		// render menu
		$data = [
			'app'		=>	FALSE,
			'gallery'	=>	FALSE,
			'user'		=>	TRUE,
			'poweroff'	=>	FALSE,
		];
		renderTemplate('nav.php', $data);

		$data = NULL;
		$authorID = $bdd->query('SELECT user_id AS id FROM camagru_users WHERE user_login = ' . $bdd->quote($_SESSION['login']));
		$authorID = ($authorID->fetch())['id'];
		$result = $bdd->query('SELECT img_id AS id, img_base64 as img FROM camagru_img WHERE author_id = ' . intval($authorID) . ' ORDER BY img_date DESC');
		while ($line = $result->fetch())
			$data[] = $line;

		// render Gallery
		renderTemplate('user.php', $data);

		// render Footer
		renderTemplate('footer.php', null);
	} else
		renderTemplate('error.php', null);
}

?>
