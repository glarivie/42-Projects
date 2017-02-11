#!/usr/bin/php
<?php

$epur = array();
$count = 0;

function	ft_split($str)
{
	if(isset($str) && is_string($str))
	{
		$tab = explode(" ", $str);
		$tab = array_diff($tab, array(''));
		$tab = array_slice($tab, 0);
		return ($tab);
	}
}

if (isset($argv[1]) && $argc == 2)
{
	$epur = ft_split($argv[1]);
	$count = count($epur);
	for ($index = 0; $index < $count; $index++)
	{
		if($index != ($count - 1))
			echo $epur[$index] . " ";
		else
			echo $epur[$index] . "\n";
	}
}

?>
