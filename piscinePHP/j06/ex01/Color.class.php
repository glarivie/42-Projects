<?php

Class Color {
	public static $verbose = FALSE;

	public $red = 0;
	public $green = 0;
	public $blue = 0;

	public static function hex2rgb ($hexa) {
		if (strlen($hexa) === 3) {
			$R = hexdec(substr($hexa, 0, 1).substr($hexa, 0, 1));
			$G = hexdec(substr($hexa, 1, 1).substr($hexa, 1, 1));
			$B = hexdec(substr($hexa, 2, 1).substr($hexa, 2, 1));
		} else {
			$R = hexdec(substr($hexa, 0, 2));
			$G = hexdec(substr($hexa, 2, 2));
			$B = hexdec(substr($hexa, 4, 2));
		}
		return ([$R, $G, $B]);
	}

	public function __construct(array $kwargs) {
		if (isset($kwargs)) {
			if (count($kwargs) === 1 && array_key_exists('rgb', $kwargs)) {
				$kwargs['rgb'] = dechex(intval($kwargs['rgb']));
				$rgb = '';
				for ($index = 0; $index < (6 - strlen($kwargs['rgb'])); $index++)
					$rgb = $rgb . '0';
				$rgb = self::hex2rgb($rgb . $kwargs['rgb']);
				$this->red = $rgb[0];
				$this->green = $rgb[1];
				$this->blue = $rgb[2];
				if (self::$verbose)
					echo 'Color Object created : [' . $this->red . ', ' . $this->green . ', ' . $this->blue . ']' . PHP_EOL;
			} else if (count($kwargs) === 3 && array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs)) {
				$this->red = intval($kwargs['red']);
				$this->green = intval($kwargs['green']);
				$this->blue = intval($kwargs['blue']);
				if (self::$verbose)
					echo 'Color Object created : [' . $this->red . ', ' . $this->green . ', ' . $this->blue . ']' . PHP_EOL;
			} else {
				if (self::$verbose)
					echo 'ERROR : Bad arguments, can\'t construct the Class ' . get_class($this) . PHP_EOL;
			}
		}
		return ;
	}

	public function add($instance) {
		$tab = get_object_vars($instance);
		return (new Color([
			'red' => ($this->red + $tab['red']),
			'green' => ($this->green + $tab['green']),
			'blue' => ($this->blue + $tab['blue'])
		]));
	}
	public function sub($instance) {
		$tab = get_object_vars($instance);
		return (new Color([
			'red' => ($this->red - $tab['red']),
			'green' => ($this->green - $tab['green']),
			'blue' => ($this->blue - $tab['blue'])
		]));
	}
	public function mult($factor) {
		return (new Color([
			'red' => ($this->red * $factor),
			'green' => ($this->green * $factor),
			'blue' => ($this->blue * $factor)
		]));
	}

	public function __destruct() {
		if (self::$verbose)
			echo get_class($this) . ' Object [' . $this->red . ', ' . $this->green . ', ' . $this->blue . '] destroyed.' . PHP_EOL;
		return ;
	}

	public static function doc() {
		return (file_get_contents('Color.doc.txt'));
	}

	public function __toString() {
		return ('Current Color Object : [' . $this->red . ', ' . $this->green . ', ' . $this->blue . ']');
	}
}

?>
