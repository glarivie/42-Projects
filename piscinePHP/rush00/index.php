<?php
	include_once('install.php');
	$projectName = "ft_minishop";
	$pageTitle = $projectName . " - Accueil";

 ?>

<!DOCTYPE html>
<html lang="fr">
	<?php include_once('views/head.php'); ?>
	<body>
		<?php include_once('views/nav.php'); ?>

		<div class="connect">
			<h2>Se connecter: </h2>
			<form method="post" action="login.php">

				<label for="login">Login</label>
				<input id="login" type="text" name="login" value="" placeholder="Login" required>

				<label for="password">Password</label>
				<input id="password" type="password" name="passwd" value="" placeholder="password" required>

				<button type="submit" name="button">Se connecter</button>

			</form>
		</div>

		<div class="create">
			<h2>S'enregistrer: </h2>
			<form method="post" action="create.php">

				<label for="login">Login</label>
				<input id="login" type="text" name="login" value="" placeholder="Login" required>

				<label for="password">Password</label>
				<input id="password" type="password" name="passwd" value="" placeholder="password" required>

				<button type="submit" name="button">Créer un compte</button>

			</form>
		</div>


		<?php include_once('views/footer.html'); ?>
	</body>
</html>
