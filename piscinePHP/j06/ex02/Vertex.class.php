<?php

Class Vertex {
	public static $verbose = FALSE;

	private $_x = 0.00;
	private $_y = 0.00;
	private $_z = 0.00;
	private $_w = 1.00;
	private $_color;

	public function getX() {
		return ($this->_x);
	}
	public function setX($value) {
		return ($this->_x = $value);
	}
	public function getY() {
		return ($this->_y);
	}
	public function setY($value) {
		return ($this->_y = $value);
	}
	public function getZ() {
		return ($this->_z);
	}
	public function setZ($value) {
		return ($this->_z = $value);
	}
	public function getW() {
		return ($this->_w);
	}
	public function setW($value) {
		return ($this->_w = $value);
	}
	public function getColor() {
		return ($this->_color);
	}
	public function setColor($value) {
		return ($this->_color = $value);
	}

	public function __construct(array $kwargs) {
		if (isset($kwargs)) {
			// Default Color is set to black
			$this->_color = $this->setColor(new Color([
				'rgb' => 0x000000
			]));
			if (isset($kwargs['x']))
				$this->_x = $this->setX(number_format($kwargs['x'], 2));
			if (isset($kwargs['y']))
				$this->_y = $this->setY(number_format($kwargs['y'], 2));
			if (isset($kwargs['z']))
				$this->_z = $this->setZ(number_format($kwargs['z'], 2));
			if (isset($kwargs['w']))
				$this->_w = $this->setW(number_format($kwargs['w'], 2));
			if (isset($kwargs['color']))
				$this->_color = $this->setColor($kwargs['color']);
			if (self::$verbose)
				echo 'Vertex( x: ' . $this->getX() . ', y: ' . $this->getY() . ', z: ' . $this->getZ() . ', w: ' . number_format(($this->getW()), 2) . ', ' . $this->getColor() . ' ) constructed' . PHP_EOL;
		} else {
			if (self::$verbose)
				echo 'ERROR : Bad arguments, can\'t construct the Class ' . get_class($this) . PHP_EOL;
		}
		return ;
	}

	public function __destruct() {
		if (self::$verbose)
			echo 'Vertex( x: ' . $this->getX() . ', y: ' . $this->getY() . ', z: ' . $this->getZ() . ', w: ' . number_format(($this->getW()), 2) . ', ' . $this->getColor() . ' ) destructed' . PHP_EOL;
		return ;
	}

	public static function doc() {
		return (file_get_contents('Vertex.doc.txt'));
	}

	public function __toString() {
		return ('Current Vertex Object : Vertex( x: ' . $this->getX() . ', y: ' . $this->getY() . ', z: ' . $this->getZ() . ', w: ' . number_format(($this->getW()), 2) . ', ' . $this->getColor() . ' )');
	}
}

?>
