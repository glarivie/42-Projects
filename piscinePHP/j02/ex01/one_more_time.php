#!/usr/bin/php
<?php

	define("ERROR", "Wrong Format\n");
	date_default_timezone_set('Europe/Paris');

	$days = [
		"lundi",
		"mardi",
		"mercredi",
		"jeudi",
		"vendredi",
		"samedi",
		"dimanche"
	];
	$months = [
		"janvier",
		"fevrier",
		"mars",
		"avril",
		"mai",
		"juin",
		"juillet",
		"aout",
		"septembre",
		"octobre",
		"novembre",
		"decembre"
	];

	function	get_info($str)
	{
		$tab = array();
		$hms = array();
		$index = 0;

		if (isset($str) && preg_match_all("/[ ]/", $str) === 4)
		{
			$tab = preg_split("/[ ]/", $str);
			$hms = preg_split("/[:]/", $tab[4]);
			$tab[4] = $hms[0];
			$tab[5] = $hms[1];
			$tab[6] = $hms[2];
			$tab[0] = strtolower($tab[0]);
			$tab[2] = strtolower($tab[2]);
			return ($tab);
		}
	}

	function	check_tab($tab, $days, $months)
	{
		$match = [
			"day"	=>	0,
			"date"	=>	0,
			"month"	=>	0,
			"year"	=>	0,
			"hour"	=>	0,
			"min"	=>	0,
			"sec"	=> 	0
		];

		if (isset($tab) && count($tab) == 7)
		{
			foreach ($days as $day)
				$match["day"] += ($tab[0] == $day) ? 1 : 0;
			$match["date"] = (is_numeric($tab[1]) && $tab[1] > 0 && $tab[1] <= 31) ? 1 : 0;
			foreach ($months as $month)
				$match["month"] += ($tab[2] == $month) ? 1 : 0;
			$match["year"] = (is_numeric($tab[3]) && $tab[3] > 1969 && $tab[3] < 9999) ? 1 : 0;
			$match["hour"] = (is_numeric($tab[4]) && $tab[4] >= 0 && $tab[4] < 25) ? 1 : 0;
			$match["min"] = (is_numeric($tab[5]) && $tab[5] >= 0 && $tab[5] < 60) ? 1 : 0;
			$match["sec"] = (is_numeric($tab[6]) && $tab[6] >= 0 && $tab[6] < 60) ? 1 : 0;
			return (array_sum($match) == 7) ? TRUE : FALSE;
		}
		return FALSE;
	}

	function	get_timestamp($tab, $months)
	{
		$index = 0;

		if (isset($tab))
		{
			for ($index = 0; $index < count($months); $index++)
			{
				if ($tab[2] == $months[$index])
					$tab[2] = $index + 1;
			}
			return (mktime((int)$tab[4], (int)$tab[5], (int)$tab[6], $tab[2], (int)$tab[1], (int)$tab[3]));
		}
		else
			return (-1);
	}

	if (isset($argv[1]) && $argc == 2)
	{
		$ret = array();
		$time = 0;

		$ret = get_info($argv[1]);
		if (check_tab($ret, $days, $months))
		{
			$time = get_timestamp($ret, $months);
			echo $time . "\n";

		}
		else
		 	echo (ERROR);
	}
	else
		echo "\n";

?>
