<?php

session_start();

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/validateAccount.php');
require_once($rootDIR . '/config/database.php');

function renderSingle($imgID) {
	if (isRegisteredUser($_SESSION['login'])) {
		global $bdd;
		$data = [
			'app'		=>	FALSE,
			'gallery'	=>	TRUE,
			'user'		=>	FALSE,
			'poweroff'	=>	FALSE,
		];
		// render menu
		renderTemplate('nav.php', $data);

		$data = NULL;
		$result = $bdd->query('SELECT img_base64 as img, author_id as author, img_likes AS likes, img_comments_nb AS nb, img_date AS img_date FROM camagru_img WHERE img_id = ' . intval($imgID));
		$data = $result->fetch();
		$author = $bdd->query('SELECT user_login AS login FROM camagru_users WHERE user_id = ' . intval($data['author']));
		$author = $author->fetch();
		$data['id'] = $imgID;
		$data['login'] = $author['login'];
		$comments = $bdd->query('SELECT author_id AS author_id, author_email AS mail, comment_date AS comment_date, comment_content AS content FROM camagru_comments WHERE img_id = ' . $imgID);
		while ($line = $comments->fetch()) {
			$auteur = $bdd->query('SELECT user_login AS login FROM camagru_users WHERE user_id = ' . intval($line['author_id']));
			$auteur = $auteur->fetch();
			$line['author_login'] = $auteur['login'];
			$com[] = $line;
		}

		$data['comments'] = $com;
		// render Gallery
		renderTemplate('single.php', $data);

		// render Footer
		renderTemplate('footer.php', null);
	} else
		renderTemplate('error.php', null);
}

?>
