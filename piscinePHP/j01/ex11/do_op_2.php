#!/usr/bin/php
<?php

define("ERROR_PARAMS", "Incorrect Parameters\n");
define("ERROR_SYNTAX", "Syntax Error\n");

function	ft_check($arg1, $arg2, $op)
{
	if (isset($arg1) && isset($arg2) && isset($op))
	{
		if (is_numeric($arg1) && is_numeric($arg2) && ereg("[+%/*-]", $op))
			return (TRUE);
		else
			return (FALSE);
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
			echo (ERROR_SYNTAX);
	}
}

if ($argc != 2)
	echo (ERROR_PARAMS);
else
{
	list($arg1, $op, $arg2) = sscanf($argv[1], "%d %c %d");
	if (ft_check($arg1, $arg2, $op))
		ft_math($arg1, $arg2, $op);
	else
		echo (ERROR_SYNTAX);
}
?>
