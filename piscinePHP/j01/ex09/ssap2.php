#!/usr/bin/php
<?php

$let = "";
$num = array();
$spe = "";
$epur = array();
$ret = array();

function	ft_split($str)
{
	if(isset($str) && is_string($str))
	{
		$tab = explode(" ", $str);
		$tab = array_diff($tab, array(''));
		$tab = array_slice($tab, 0);
		natcasesort($tab);
		return ($tab);
	}
}

function	is_alpha($char)
{
	if (isset ($char))
		return ((ereg("^[a-zA-Z]*$", $char)) ? TRUE : FALSE);
}

if ($argc > 1)
{
	unset($argv[0]);
	foreach ($argv as $element)
		$epur = array_merge($epur, ft_split($element));
	for ($index = 0; $index <= count($epur); $index++)
	{
		if (is_alpha($epur[$index][0]))
			$let = $let . " " . $epur[$index];
		else if (is_numeric($epur[$index][0]))
			$num[] = $epur[$index];
		else
			$spe = $spe . " " . $epur[$index];
	}
	array_multisort($num, SORT_ASC, SORT_STRING);
	$ret = array_merge(ft_split($let), $num, ft_split($spe));
	foreach ($ret as $element)
		echo $element . "\n";
}
?>
