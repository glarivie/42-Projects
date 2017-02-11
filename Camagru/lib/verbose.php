<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/getRequestURI.php');

$verbose = false;

if ($verbose) {
	echo '<br />';echo '<br />';
	echo '<strong>Request Method =</strong> ' . $_SERVER['REQUEST_METHOD'] . '<br />';		// GET
	// echo $_SERVER['REQUEST_URI'] . '<br />'; 		// /Camagru/user/34567890
	// echo $_SERVER['SCRIPT_NAME'] . '<br />';		// /Camagru/index.php

	echo '<br />';
	$rootURI = getRootURI();
	$requestURI = getRequestURI(getRootURI());

	echo '<strong>rootURI = </strong>' . $rootURI . '<br />';
	echo '<strong>Request URI = </strong>' . $requestURI . '<br />';

	$requestData = getRequestData($requestURI);
	print_r($requestData);
	echo '<br />';
}

?>
