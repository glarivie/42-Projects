<?php
class Vector {
	public static $verbose = FALSE;

	private $_x = 0.00;
	private $_y = 0.00;
	private $_z = 0.00;
	private $_w = 0.00;

	public function doc() {
		return (file_get_contents('Vector.doc.txt'));
	}
	public function getX() {
		return ($this->_x);
	}
	public function getY() {
		return ($this->_y);
	}
	public function getZ() {
		return ($this->_z);
	}
	public function getW() {
		return ($this->_w);
	}

	public function magnitude() {
		return (sqrt(pow($this->getX(), 2) + pow($this->getY(), 2) + pow($this->getZ(), 2)));
	}
	public function normalize() {
		$magnitude = $this->magnitude();
		if ($magnitude == 1) {
			$tab['x'] = $this->getX();
			$tab['y'] = $this->getY();
			$tab['z'] = $this->getZ();
			$tab['w'] = $this->getW();
			return (new Vector([
				'dest' => $tab
			]));
		}
		$x = (($this->getX()) / $magnitude);
		$y = (($this->getY()) / $magnitude);
		$z = (($this->getZ()) / $magnitude);
		$tab['x'] = $x;
		$tab['y'] = $y;
		$tab['z'] = $z;
		$tab['w'] = 0;
		return (new Vector([
			'dest' => $tab
		]));
	}
	public function add($rhs) {
		$tab = get_object_vars($rhs);
		return (new Vector([
			'orig' => $this,
			'dest' => $tab
		]));
	}
	public function sub($rhs) {
		$tab = get_object_vars($rhs);
		if ($tab['_x'] < 0)
			$new['x'] = (abs($tab['_x']) - abs($this->getX()));
		if ($tab['_x'] > 0)
			$new['x'] = -(abs($tab['_x']) - abs($this->getX()));
		if ($tab['_y'] < 0)
			$new['y'] = (abs($tab['_y']) - abs($this->getY()));
		if ($tab['_y'] > 0)
			$new['y'] = -(abs($tab['_y']) - abs($this->getY()));
		if ($tab['_z'] < 0)
			$new['z'] = (abs($tab['_z']) - abs($this->getZ()));
		if ($tab['_z'] > 0)
			$new['z'] = -(abs($tab['_z']) - abs($this->getZ()));
		$new['w'] = 0;
		return (new Vector([
			'dest' => $new
		]));
	}
	public function opposite() {
		if ($this->getX() < 0)
			$tab['x'] = abs($this->getX());
		if ($this->getX() > 0)
			$tab['x'] = -($this->getX());
		if ($this->getY() < 0)
			$tab['y'] = abs($this->getY());
		if ($this->getY() > 0)
			$tab['y'] = -($this->getY());
		if ($this->getZ() < 0)
			$tab['z'] = abs($this->getZ());
		if ($this->getZ() > 0)
			$tab['z'] = -($this->getZ());
		$tab['w'] = 0;
		return (new Vector([
			'dest' => $tab
		]));
	}
	public function scalarProduct($k) {
		$tab['x'] = ($this->getX() * $k);
		$tab['y'] = ($this->getY() * $k);
		$tab['z'] = ($this->getZ() * $k);
		$tab['w'] = 0;
		return (new Vector([
			'dest' => $tab
		]));
	}
	public function dotProduct($rhs) {
		$tab = get_object_vars($rhs);
		$x = ($this->getX() * $tab['_x']);
		$y = ($this->getY() * $tab['_y']);
		$z = ($this->getZ() * $tab['_z']);
		return ($x + $y + $z);
	}
	public function cos($rhs) {
		$tab = get_object_vars($rhs);
		$cos = (($this->dotProduct($rhs)) / sqrt((pow($this->getX(),2) + pow($this->getY(),2) + pow($this->getZ(),2)) * (pow($tab['_x'],2) + pow($tab['_y'],2) + pow($tab['_z'],2))));
		return ($cos);
	}

	public function crossProduct($rhs) {
		$tab = get_object_vars($rhs);
		$yz = ($this->getY() * $tab['_z']);
		$zy = ($this->getZ() * $tab['_y']);
		$zx = ($this->getZ() * $tab['_x']);
		$xz = ($this->getX() * $tab['_z']);
		$xy = ($this->getX() * $tab['_y']);
		$yx = ($this->getY() * $tab['_x']);
		$new['x'] = ($yz - $zy);
		$new['y'] = ($zx - $xz);
		$new['z'] = ($xy - $yx);
		$new['w'] = 0;
		return (new Vector([
			'dest' => $new
		]));
	}

	public function __construct(array $kwargs) {
		$orig_x = 0;
		$orig_y = 0;
		$orig_z = 0;
		$orig_w = 0;
		if (!isset($kwargs['orig'])) {
			$kwargs['orig'] = new Vertex([
				'x'=>0.0,
				'y'=>0.0,
				'z'=>0.0,
				'w'=>1.0
			]);
		} else {
			$orig = (array)($kwargs['orig']);
			$index = 0;
			foreach ($orig as $key => $val) {
				$tab[$index] = $val;
				$index++;
			}
			$orig_x = $tab[0];
			$orig_y = $tab[1];
			$orig_z = $tab[2];
			$orig_w = $tab[3];
		}
		$dest = (array)($kwargs['dest']);
		$index = 0;
		foreach ($dest as $key => $val) {
			$tab[$index] = $val;
			$index++;
		}
		$dest_x = $tab[0];
		$dest_y = $tab[1];
		$dest_z = $tab[2];
		$dest_w = $tab[3];
		if ($dest_x > 0)
			$this->_x = (abs($orig_x) + abs($dest_x));
		else if ($dest_x < 0)
			$this->_x = -(abs($orig_x) + abs($dest_x));
		if ($dest_y > 0)
			$this->_y = (abs($orig_y) + abs($dest_y));
		else if ($dest_y < 0)
			$this->_y = -(abs($orig_y) + abs($dest_y));
		if ($dest_z > 0)
			$this->_z = (abs($orig_z) + abs($dest_z));
		else if ($dest_z < 0)
			$this->_z = -(abs($orig_z) + abs($dest_z));
		if (self::$verbose === True)
			echo 'Vector( x: '.number_format($this->getX(),2).', y: '.number_format($this->getY(),2).', z: '.number_format($this->getZ(),2).', w: '.number_format($this->getW(),2).' ) constructed'.PHP_EOL;
		return ;
	}

	public function __destruct() {
		if (self::$verbose === True)
			echo 'Vector( x: '.number_format($this->getX(),2).', y: '.number_format($this->getY(),2).', z: '.number_format($this->getZ(),2).', w: '.number_format($this->getW(),2).' ) destructed'.PHP_EOL;
		return ;
	}
	public function __toString() {
		return 'Vector( x: '.number_format($this->getX(),2).', y: '.number_format($this->getY(),2).', z: '.number_format($this->getZ(),2).', w: '.number_format($this->getW(),2).' )';
	}
}
?>
