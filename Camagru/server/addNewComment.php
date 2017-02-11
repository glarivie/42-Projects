<?php

	session_start();
	$rootDIR = dirname(__DIR__, 1);
	require_once($rootDIR . '/config/database.php');
	require_once($rootDIR . '/lib/redirect.php');

	if (isset($_POST['comment']) && isset($_POST['img_id'])) {
		$comment = $_POST['comment']; // from textarea
		if(get_magic_quotes_gpc()){
		  $comment = stripslashes($comment);
		  // strip off the slashes if they are magically added.
		}
		$comment = htmlentities($comment);
		$author = $bdd->query('SELECT user_id AS id, user_email AS email FROM camagru_users WHERE user_login = ' . $bdd->quote($_SESSION['login']));
		$author = $author->fetch();
		$bdd->query('INSERT INTO camagru_comments VALUES (NULL, ' . intval($_POST["img_id"]) . ', ' . intval($author["id"]) . ', ' . $bdd->quote($author["email"]) . ', DEFAULT, ' . $bdd->quote($comment) . ', NULL)');

		$comments = $bdd->query('SELECT img_comments_nb AS nb FROM camagru_img WHERE img_id = ' . intval($_POST["img_id"]));
		$comments = intval(($comments->fetch())['nb']);
		$comments++;
		$bdd->query('UPDATE camagru_img SET img_comments_nb = ' . $comments . ' WHERE img_id = ' . intval($_POST["img_id"]));


		redirect('/single/' . $_POST['img_id'], 0);
	}

?>
