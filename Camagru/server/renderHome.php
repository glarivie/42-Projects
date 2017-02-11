<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/lib/renderTemplate.php');
require_once($rootDIR . '/lib/formCheck.php');



function renderHome() {
	// render login home
	renderTemplate('home.php', null);

	// render Footer
	renderTemplate('footer.php', null);
}

?>
