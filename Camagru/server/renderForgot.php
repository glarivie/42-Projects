<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');

function renderForgot() {
	// render forgot password page
	renderTemplate('forgot.php', null);

	// render Footer
	renderTemplate('footer.php', null);
}

?>
