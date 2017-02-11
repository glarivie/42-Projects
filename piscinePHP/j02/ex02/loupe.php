#!/usr/bin/php
<?php
	function loupe($page)
	{
		$page = preg_replace_callback(
			'/>([^<]*)</si',
			function ($arr) {
				return strtoupper($arr[0]);
			},
			$page
		);
		$page = preg_replace_callback(
			'/(=")([^"]*)("*)/si',
			function ($arr) {
				return $arr[1] . strtoupper($arr[2]) . $arr[3];
			},
			$page
		);
		return $page;
	}
	if ($argc != 2)
		exit;
	echo loupe(file_get_contents($argv[1]));
?>
