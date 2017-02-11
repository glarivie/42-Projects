<?php

function renderTemplate($templateName, $data) {
	$rootDIR = dirname(__DIR__, 1);
	$viewsDIR = $rootDIR . '/client/views/';
	$includeDIR = $rootDIR . '/client/includes/';
	if (file_exists($viewsDIR . $templateName))
		$templateFullPath = $viewsDIR . $templateName;
	if (file_exists($includeDIR . $templateName))
		$templateFullPath = $includeDIR . $templateName;
	// echo $templateFullPath;

	ob_start();
	include($templateFullPath);
	$out = ob_get_contents();
	ob_end_clean();
	echo $out;
}

?>
