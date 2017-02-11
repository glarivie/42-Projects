<?php
	$projectName = "ft_minishop";
	$pageTitle = $projectName . " - Login";

?>

<!DOCTYPE html>
<html lang="fr">
	<?php include_once('views/head.php'); ?>
	<body>
		<?php include_once('views/nav.php'); ?>

			<form method="post" action="login.php">

				<label for="login">Login</label>
				<input id="login" type="text" name="login" value="" placeholder="Login" required>

				<label for="password">Password</label>
				<input id="password" type="password" name="password" value="" placeholder="password" required>

				<button type="submit" name="button">Se connecter</button>

			</form>

		<?php include_once('views/footer.html'); ?>
	</body>
</html>
