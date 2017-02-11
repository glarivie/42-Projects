#!/usr/bin/php
<?php
if (isset($argv[1]) && isset($argv[2])) {
	if (($fd = @fopen($argv[1], 'r')) !== FALSE) {
		for ($index = 0; $csv = fgetcsv($fd, 1000, ";"); $index++) {
			if ($index > 0) {
				if ($argv[2] === 'nom') {
					$nom[$csv[0]] = $csv[0];
					$prenom[$csv[0]] = $csv[1];
					$mail[$csv[0]] = $csv[2];
					$IP[$csv[0]] = $csv[3];
					$pseudo[$csv[0]] = $csv[4];
				} else if ($argv[2] === 'prenom') {
					$nom[$csv[1]] = $csv[0];
					$prenom[$csv[1]] = $csv[1];
					$mail[$csv[1]] = $csv[2];
					$IP[$csv[1]] = $csv[3];
					$pseudo[$csv[1]] = $csv[4];
				} else if ($argv[2] === 'mail') {
					$nom[$csv[2]] = $csv[0];
					$prenom[$csv[2]] = $csv[1];
					$mail[$csv[2]] = $csv[2];
					$IP[$csv[2]] = $csv[3];
					$pseudo[$csv[2]] = $csv[4];
				} else if ($argv[2] === 'IP') {
					$nom[$csv[3]] = $csv[0];
					$prenom[$csv[3]] = $csv[1];
					$mail[$csv[3]] = $csv[2];
					$IP[$csv[3]] = $csv[3];
					$pseudo[$csv[3]] = $csv[4];
				} else if ($argv[2] === 'pseudo') {
					$nom[$csv[4]] = $csv[0];
					$prenom[$csv[4]] = $csv[1];
					$mail[$csv[4]] = $csv[2];
					$IP[$csv[4]] = $csv[3];
					$pseudo[$csv[4]] = $csv[4];
				} else {
					exit();
				}
			}
		}
	} else {
		exit();
	}
	while (42) {
		$val = '';
		echo "Entrez votre commande: ";
		if (fscanf(STDIN, "%[^\n]s", $val)) {
			if (isset($val)) {
				eval($val);
			}
		}
		else {
			echo "\n";
			exit();
		}
	}
}
?>
