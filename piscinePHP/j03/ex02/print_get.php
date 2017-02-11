<?php

	if (isset($_GET))
	{
		foreach ($_GET as $key => $element)
			echo $key . ": " . $element . "\n";
	}

?>
