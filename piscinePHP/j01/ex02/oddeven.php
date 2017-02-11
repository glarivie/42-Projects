#!/usr/bin/php
<?php

	while (42)
	{
		$val = '';
		echo "Entrez un nombre: ";
		if (fscanf(STDIN, "%s\n", $val))
		{
			if (isset($val) && is_numeric($val))
			{
				if (intval($val) % 2 == 0)
					echo "Le chiffre " . $val . " est Pair\n";
				else
					echo "Le chiffre " . $val . " est Impair\n";
			}
			else
				echo "'" . $val . "' n'est pas un chiffre\n";
		}
		else
		{
			echo "\n";
			exit();
		}
	}
?>
