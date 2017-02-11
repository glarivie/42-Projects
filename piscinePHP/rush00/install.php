<?php

	if (!file_exists('data/products.json')) {
		$fixtures = file_get_contents('data/fixtures.json');
		file_put_contents('data/products.json', $fixtures);
	}

?>
