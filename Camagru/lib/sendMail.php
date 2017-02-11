<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');

function sendSubscriptionMail($login, $to) {
	global $bdd;
	$requestURI = array_slice(explode('/', $_SERVER['SCRIPT_NAME']), 0, -1);
	$result = $bdd->query('SELECT user_password AS pwd FROM camagru_users WHERE user_login =' . $bdd->quote($login));
	$result = $result->fetch();
	$validateURL = 'http://' . $_SERVER['HTTP_HOST'] . '/' . $requestURI[1] . '/validate/' . $login . '/' . $result['pwd'];

	$subject = 'Camagru - Validez votre inscription';
	$message = '<html><head><title>Camagru - Validez votre inscription</title></head>
		<body><h4>Bonjour, <strong>' . $login . '</strong>.</h4>
			<p>Bienvenue sur Camagru ! Pour valider votre inscription, cliquez <a href="' . $validateURL . '" target="_blank">ici</a>.</p>
		</body>
	</html>';
	$headers  = 'MIME-Version: 1.0' . "\r\n";
	$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
	$headers .= 'To: ' . $login . ' <' . $email . '>' . "\r\n";
	$headers .= 'From: Camagru App <noreply@camagru.app>' . "\r\n";

	mail($to, $subject, $message, $headers);
}

function sendRecoverMail($login, $to) {
	global $bdd;
	$requestURI = array_slice(explode('/', $_SERVER['SCRIPT_NAME']), 0, -1);
	$result = $bdd->query('SELECT user_password AS pwd FROM camagru_users WHERE user_login =' . $bdd->quote($login));
	$result = $result->fetch();
	$validateURL = 'http://' . $_SERVER['HTTP_HOST'] . '/' . $requestURI[1] . '/change-password/' . $login . '/' . $result['pwd'];
	$subject = 'Camagru - Modifiez votre mot de passe';
	$message = '<html><head><title>Camagru - Modifiez votre mot de passe</title></head>
		<body><h4>Bonjour, <strong>' . $login . '</strong>.</h4>
			<p>Pour changer votre mot de passe, cliquez <a href="' . $validateURL . '" target="_blank">ici</a>.</p>
		</body>
	</html>';
	$headers  = 'MIME-Version: 1.0' . "\r\n";
	$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
	$headers .= 'To: ' . $login . ' <' . $email . '>' . "\r\n";
	$headers .= 'From: Camagru App <noreply@camagru.app>' . "\r\n";

	mail($to, $subject, $message, $headers);
}

?>
