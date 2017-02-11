#!/usr/bin/php
<?php
	date_default_timezone_set('Europe/Paris');
	$fd = fopen("/var/run/utmpx", "r");

	for ($index = 0; $ret = fread($fd, 628); $index++) {
		$pack = unpack("a256x/a4/a32y/i/i/i2z/@", $ret);
		if (!strncmp($pack["x"], get_current_user(), strlen(get_current_user()))) {
			$tab[$index]["y"] = $pack["y"];
			$tab[$index]["x"] = $pack["x"];
			$tab[$index]["z"] = strftime("%b %e %H:%M",$pack["z1"]);
		}
	}
	fclose($fd);
	foreach ($tab as $index) {
		echo $index["x"]." ".$index["y"]."  ".$index["z"]."\n";
	}

?>
