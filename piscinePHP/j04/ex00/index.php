<?php
	session_start();
	// var_dump($_SESSION);

	if ($_GET['login'] && $_GET['passwd'] && isset($_GET['submit']))
	{
		$_SESSION['login'] = $_GET['login'];
		$_SESSION['passwd'] = $_GET['passwd'];
	}
?>


<html>
	<head>
		<meta charset="utf-8" />
		<title>LOGIN/PASSWD</title>
		<style>
			body {
				font-family: sans-serif;
			}
		</style>
	</head>
		<body>

			<form method="get" action="index.php">
				<label for="login">Login : </label>
				<input type="text" name="login" id="login" value="<?PHP echo $_SESSION['login'] ?>" />

				<label for="passwd">Password : </label>
				<input type="password" name="passwd" id="passwd" value="<?php echo $_SESSION['passwd'] ?>" />

				<input type="submit" name="submit" value="OK"/>
			</form>

		</body>
</html>
