<?php
	session_start();

	require_once(__DIR__ . '/lib/verbose.php');
	require_once(__DIR__ . '/lib/define.php');
	require_once(__DIR__ . '/config/database.php');
	require_once(__DIR__ . '/lib/getRequestURI.php');
	require_once(__DIR__ . '/lib/renderTemplate.php');

	$rootURI = getRootURI();
	$requestData = getRequestData(getRequestURI($rootURI));
?>

<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>CAMAGRU</title>
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/reset.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/main.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/home.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/nav.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/app.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/gallery.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/single.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/filter.css'; ?>" media="screen" />
		<link rel="stylesheet" type="text/css" href="<?php echo $rootURI . 'public/css/mobile.css'; ?>" media="screen" />
		<link rel="icon" type="text/css" href="<?php echo $rootURI . 'public/img/favicon.png'; ?>" type="image/png" />
		<link rel="stylesheet" type="text/css" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.6.1/css/font-awesome.min.css">
	<body>
		<?php

			require_once(__DIR__ . '/server/renderHome.php');
			getURI('/', renderHome);

			require_once(__DIR__ . '/server/renderApp.php');
			getURI('/app', renderApp);

			require_once(__DIR__ . '/server/renderSuccess.php');
			getURI('/success', renderSuccess);

			require_once(__DIR__ . '/lib/validateAccount.php');
			if ($requestData[0] === 'validate') {
				validateAccount($requestData[1], $requestData[2]);
			}

			require_once(__DIR__ . '/server/renderGallery.php');
			getURI('/gallery', renderGallery);

			require_once(__DIR__ . '/server/renderSingle.php');
			if ($requestData[0] === 'single') {
				renderSingle($requestData[1]);
			}

			require_once(__DIR__ . '/server/renderForgot.php');
			getURI('/forgot-password', renderForgot);

			if ($requestData[0] === 'change-password') {
				$data['login'] = $requestData[1];
				$data['whirlpool'] = $requestData[2];
				renderTemplate('password-change.php', $data);
			}

			require_once(__DIR__ . '/server/renderMe.php');
			getURI('/user', renderMe);

		?>
	</body>
</html>
