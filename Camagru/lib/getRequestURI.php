<?php

// Get root path before client request uri
function getRootURI() {
	return (implode('/', array_slice(explode('/', $_SERVER['SCRIPT_NAME']), 0, -1)) . '/');
}

// Deduce client request uri by removing root path string from full server request uri
function getRequestURI($rootURI) {
	return (substr($_SERVER['REQUEST_URI'], strlen($rootURI)));
}

// Return an array from client request uri
function getRequestData($requestURI) {
	return (explode('/', $requestURI));
}


function getURI($path, callable $callback) {
	$requestURI = getRequestURI(getRootURI());
	$requestData = getRequestData($requestURI);

	if ($path === '/' . $requestURI) {
		$callback();
	}
}

?>
