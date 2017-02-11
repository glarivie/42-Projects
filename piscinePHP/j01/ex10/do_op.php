#!/usr/bin/php
<?php

define("ERROR", "Incorrect Parameters\n");

function	ft_epur($str)
{
	if (isset ($str))
	{
		$str = preg_replace("[ ]", "", $str);
		if (is_numeric($str) || ereg("[+%/*-]", $str))
			return ((is_numeric($str)) ? intval($str) : $str);
		else
		{
			echo (ERROR);
			exit();
		}
	}
}

function	ft_math($arg1, $arg2, $op)
{
	if (isset($arg1) && isset($arg2) && isset($op))
	{
		if ($op == '+')
			echo ($arg1 + $arg2) . "\n";
		else if ($op == '-')
			echo ($arg1 - $arg2) . "\n";
		else if ($op == '*')
			echo ($arg1 * $arg2) . "\n";
		else if ($op == '/' && $arg2 > 0)
			echo ($arg1 / $arg2) . "\n";
		else if ($op == '%' && $arg2 > 0)
			echo ($arg1 % $arg2) . "\n";
		else
			echo (ERROR);
	}
}

if ($argc != 4)
	echo (ERROR);
else
{
	if (isset($argv[1]) && isset($argv[2]) && isset($argv[3]))
		ft_math(ft_epur($argv[1]), ft_epur($argv[3]), ft_epur($argv[2]));
}

?>
