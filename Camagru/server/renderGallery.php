<?php

session_start();

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/validateAccount.php');
require_once($rootDIR . '/config/database.php');

function renderGallery() {
	if (isRegisteredUser($_SESSION['login'])) {
		global $bdd;
		// render menu
		$data = [
			'app'		=>	FALSE,
			'gallery'	=>	TRUE,
			'user'		=>	FALSE,
			'poweroff'	=>	FALSE,
		];
		renderTemplate('nav.php', $data);
		$data = NULL;

		$result = $bdd->query('SELECT img_id AS id, img_base64 as img, img_likes AS likes, img_comments_nb AS comments FROM camagru_img ORDER BY img_date DESC');
		while ($line = $result->fetch())
			$data[] = $line;
			
		// render Gallery
		renderTemplate('gallery.php', $data);

		// render Footer
		renderTemplate('footer.php', null);
	} else
		renderTemplate('error.php', null);
}

?>
