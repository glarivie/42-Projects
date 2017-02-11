<?php

	function render($templateUri, $dataArray) {
		$uri = file_get_contents($templateUri);
		$ret = preg_replace_callback(
				'/(?:{{ |{{)([a-zA-Z]*)(?: }}|}})/',
				function($matches) use($dataArray) {
					foreach ($dataArray as $key => $value) {
						if ($key === $matches[1]) {
							$matches[0] = $value;
							return $matches[0];
						}
					}
				},
				$uri
		);
		return $ret;
	}
?>
