<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/getRequestURI.php');

function redirect($url, $delay) {
	$requestData = array_slice(explode('/', $_SERVER['SCRIPT_NAME']), 0, -1);
	echo '<META HTTP-EQUIV="Refresh" Content="' . $delay . '; URL=/' . $requestData[1] . $url . '">';
}

?>
