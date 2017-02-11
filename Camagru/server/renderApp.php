<?php

session_start();

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/validateAccount.php');

function renderApp() {
	if (isRegisteredUser($_SESSION['login'])) {
		global $bdd;
		// render menu
		$data = [
			'app'		=>	TRUE,
			'gallery'	=>	FALSE,
			'user'		=>	FALSE,
			'poweroff'	=>	FALSE,
		];
		renderTemplate('nav.php', $data);

		$data = NULL;
		$result = $bdd->query('SELECT img_id AS id, img_base64 as img FROM camagru_img ORDER BY img_date DESC');
		while ($line = $result->fetch())
			$data[] = $line;

		// render App
		renderTemplate('app.php', $data);

		// render Footer
		renderTemplate('footer.php', null);
	} else
		renderTemplate('error.php', null);
}

?>
