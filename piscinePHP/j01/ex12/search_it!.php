#!/usr/bin/php
<?php

function	get_keys($argv)
{
	if (isset($argv))
	{
		$dict = array();

		foreach ($argv as $elem)
		{
			$tmp = explode(":", $elem);
			$dict = array_merge($dict, array($tmp[0] => $tmp[1]));
		}
	}
	return ($dict);
}

if ($argv > 1)
{
	unset($argv[0]);
	$search = $argv[1];
	unset($argv[1]);
	$dict = get_keys($argv);

	if (array_key_exists($search, $dict))
	{
		foreach ($dict as $key => $value)
		{
			if ($key == $search)
				echo $value . "\n";
		}
	}
}

?>
