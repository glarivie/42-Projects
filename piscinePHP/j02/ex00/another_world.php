#!/usr/bin/php
<?php

	define("ERROR", "\n");

	$ret = array();

	function	ft_split($str)
	{
		if(isset($str) && is_string($str))
		{
			$tab = preg_split("/[ \t]/", $str);
			$tab = array_diff($tab, array(''));
			$tab = array_splice($tab, 0);
			return ($tab);
		}
	}

	if (isset($argv[1]))
	{
		$ret = ft_split($argv[1]);
		foreach ($ret as $elem)
			echo (($elem === end($ret)) ? $elem . "\n" : $elem . " ");
	}
	else
		echo (ERROR);
?>
