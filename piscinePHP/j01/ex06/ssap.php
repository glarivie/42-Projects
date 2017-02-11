#!/usr/bin/php
<?php

$result = "";
$count = 0;

function	ft_split($str)
{
	if(isset($str) && is_string($str))
	{
		$tab = explode(" ", $str);
		$tab = array_diff($tab, array(''));
		$tab = array_slice($tab, 0);
		sort($tab);
		return ($tab);
	}
}

if ($argc > 1)
{
	unset($argv[0]);
	$count = count($argv);
	for ($index = 0; $index <= $count; $index++)
		$result = $result . " " . $argv[$index];
	$result = ft_split($result);
	foreach ($result as $element)
		echo $element . "\n";
}

?>
