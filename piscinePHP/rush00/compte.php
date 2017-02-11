<?php
	$projectName = "ft_minishop";
	$pageTitle = $projectName . " - Login";
	session_start();

	if (!$_POST['oldpwd'] OR !$_POST['newpwd'] OR !$_POST['login'])
	{
		echo "VEUILLEZ REMPLIR TOUS LES CHAMPS\n";
		return;
	}
	$database = file_get_contents("../private/user.json");
	$old_data = json_decode($database, true);
	$hash_oldpwd = hash("whirlpool", $_POST['oldpwd']);
	$hash_newpwd = hash("whirlpool", $_POST['newpwd']);
	$i = 0;
	foreach ($old_data as $login)
	{
		if (($_POST['login'] == $login['login']) AND ($hash_oldpwd != $login['passwd']))
		{
			echo "MAUVAIS MOT DE PASSE\n";
			return;
		}
		if (($_POST['login'] == $login['login']) AND ($hash_oldpwd == $login['passwd']))
		{
			$i = 1;
			$login['passwd'] = $hash_newpwd;
			$mod_data['user'] = $login;
		}
		else if ($_POST['login'] != $login['login'])
			$mod_data['user'] = $login;
	}
	if ($i == 0)
	{
		echo "UTILISATEUR INCONNU\n";
		return;
	}
	$new_data['user'][] = json_encode($mod_data, true);
	file_put_contents("../private/passwd", $new_data);
	echo "MOT DE PASSE MODIFIE\n";
?>





<!DOCTYPE html>
<html lang="fr">
	<?php include_once('views/head.php'); ?>
	<body>
		<?php include_once('views/nav.php'); ?>

			<form method="post" action="compte.php">

				<label for="login">Login</label>
				<input id="login" type="text" name="login" value="" placeholder="Login" required>

				<label for="password">Ancien password</label>
				<input id="password" type="oldpwd" name="oldpwd" value="" placeholder="oldpwd" required>

				<label for="password">Nouveau password</label>
				<input id="password" type="newpwd" name="newpwd" value="" placeholder="newpwd" required>

				<button type="submit" name="button">Modifierer</button>


		<?php include_once('views/footer.html'); ?>
	</body>
</html>
