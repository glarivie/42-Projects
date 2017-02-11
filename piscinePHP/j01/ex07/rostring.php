#!/usr/bin/php
<?php

	$rot = array();
	$count = 0;

	function	ft_split($str)
	{
		if(isset($str) && is_string($str))
		{
			$tab = explode(" ", $str);
			$tab = array_diff($tab, array(''));
			$tab = array_splice($tab, 0);
			return ($tab);
		}
	}

	if (isset($argv[1]))
	{
		$rot = ft_split($argv[1]);
		$count = count($rot);
		for ($index = 1; $index <= $count; $index++)
		{
			if($index != $count)
				echo $rot[$index] . " ";
			else
				echo $rot[0] . "\n";
		}
	}
?>
