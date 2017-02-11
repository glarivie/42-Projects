<?php

for ($col = 0; $col < 10; $col++) {
	for ($line = 0; $line < 15; $line++) {
		$tab[$col][$line] = rand(0, 9) ? 0 : 1;
	}
}

function displayHTMLMap($tab) {
	echo '<table>';
	for ($col = 0; $col < count($tab); $col++) {
		for ($line = 0; $line < count($tab[$col]); $line++) {

		}
	}
}

?>
