<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');

function renderSuccess() {

	// render login home
	renderTemplate('success.php', null);
}

?>
