<?php
class Matrix {
	public static $verbose = FALSE;

	const IDENTITY = "IDENTITY";
	const SCALE = "SCALE";
	const RX = "Ox ROTATION";
	const RY = "Oy ROTATION";
	const RZ = "Oz ROTATION";
	const TRANSLATION = "TRANSLATION";
	const PROJECTION = "PROJECTION";

	private $_vtcX;
	private $_vtcY;
	private $_vtcZ;
	private $_vtx0;

	public function doc() {
		return (file_get_contents('Matrix.doc.txt'));
	}
	public function getVtcX($att) {
		return ($this->_vtcX[$att]);
	}
	public function getVtcY($att) {
		return ($this->_vtcY[$att]);
	}
	public function getVtcZ($att) {
		return ($this->_vtcZ[$att]);
	}
	public function getVtx0($att) {
		return ($this->_vtx0[$att]);
	}

	public function identity() {
		$this->_vtcX['x'] = 1;
		$this->_vtcX['y'] = 0;
		$this->_vtcX['z'] = 0;
		$this->_vtcX['w'] = 0;
		$this->_vtcY['x'] = 0;
		$this->_vtcY['y'] = 1;
		$this->_vtcY['z'] = 0;
		$this->_vtcY['w'] = 0;
		$this->_vtcZ['x'] = 0;
		$this->_vtcZ['y'] = 0;
		$this->_vtcZ['z'] = 1;
		$this->_vtcZ['w'] = 0;
		$this->_vtx0['x'] = 0;
		$this->_vtx0['y'] = 0;
		$this->_vtx0['z'] = 0;
		$this->_vtx0['w'] = 1;
	}

	public function translation(array $trans) {
		$tab = (array)$trans['vtc'];
		$index = 0;
		foreach($tab as $key => $value)
			$new[$index++] = $value;
		$this->identity();
		$this->_vtx0['x'] = $new[0];
		$this->_vtx0['y'] = $new[1];
		$this->_vtx0['z'] = $new[2];
	}

	public function scale($scale) {
		$this->identity();
		$this->_vtcX['x'] = $this->getVtcX('x') * $scale;
		$this->_vtcY['y'] = $this->getVtcY('y') * $scale;
		$this->_vtcZ['z'] = $this->getVtcZ('z') * $scale;
	}

	public function rx($angle) {
		$this->identity();
		$this->_vtcY['y'] = cos($angle);
		$this->_vtcY['z'] = sin($angle);
		$this->_vtcZ['y'] = -sin($angle);
		$this->_vtcZ['z'] = cos($angle);
	}

	public function ry($angle) {
		$this->identity();
		$this->_vtcX['x'] = cos($angle);
		$this->_vtcX['z'] = -sin($angle);
		$this->_vtcZ['x'] = sin($angle);
		$this->_vtcZ['z'] = cos($angle);
	}

	public function rz($angle) {
		$this->identity();
		$this->_vtcX['x'] = cos($angle);
		$this->_vtcX['y'] = sin($angle);
		$this->_vtcY['x'] = -sin($angle);
		$this->_vtcY['y'] = cos($angle);
	}

	private function projection( $fov, $ratio, $near, $far) {
		$scale = tan(deg2rad($fov * 0.5)) * $near;
		$right = $ratio * $scale;
		$left = -$right;
		$top = $scale;
		$bottom = -$top;
		self::frustrum($left, $right, $bottom, $top, $near, $far);
	}

	private function frustrum($left, $right, $bottom, $top, $near, $far) {
		$this->_vtcX['x'] = (2 * $near) / ($right - $left);
		$this->_vtcY['x'] = 0;
		$this->_vtcZ['x'] = ($right + $left) / ($right - $left);
		$this->_vtx0['x'] = 0;

		$this->_vtcX['y'] = 0;
		$this->_vtcY['y'] = (2 * $near) / ($top - $bottom);
		$this->_vtcZ['y'] = ($top + $bottom) / ($top - $bottom);
		$this->_vtx0['y'] = 0;

		$this->_vtcX['z'] = 0;
		$this->_vtcY['z'] = 0;
		$this->_vtcZ['z'] = -(($far + $near) / ($far - $near));
		$this->_vtx0['z'] = -((2 * $far * $near) / ($far - $near));

		$this->_vtcX['w'] = 0;
		$this->_vtcY['w'] = 0;
		$this->_vtcZ['w'] = -1;
		$this->_vtx0['w'] = 0;
	}

	public function mult($rhs) {
		$old_verbose = Matrix::$verbose;
		Matrix::$verbose = FALSE;
		$result = new Matrix([
			'preset' => Matrix::IDENTITY
		]);
		Matrix::$verbose = $old_verbose;
		$tab = (array)$rhs;
		$index = 0;
		foreach($tab as $key => $value)
			$new[$index++] = $value;

		$result->_vtcX['x'] = ($this->getVtcX('x') * $new[0]['x']) + ($this->getVtcY('x') * $new[0]['y']) +
		($this->getVtcZ('x') * $new[0]['z']) + ($this->getVtx0('x') * $new[0]['w']);
		$result->_vtcX['y'] = ($this->getVtcX('y') * $new[0]['x']) + ($this->getVtcY('y') * $new[0]['y']) +
		($this->getVtcZ('y') * $new[0]['z']) + ($this->getVtx0('y') * $new[0]['w']);
		$result->_vtcX['z'] = ($this->getVtcX('z') * $new[0]['x']) + ($this->getVtcY('z') * $new[0]['y']) +
		($this->getVtcZ('z') * $new[0]['z']) + ($this->getVtx0('z') * $new[0]['w']);
		$result->_vtcX['w'] = ($this->getVtcX('w') * $new[0]['x']) + ($this->getVtcY('w') * $new[0]['y']) +
		($this->getVtcZ('w') * $new[0]['z']) + ($this->getVtx0('w') * $new[0]['w']);

		$result->_vtcY['x'] = ($this->getVtcX('x') * $new[1]['x']) + ($this->getVtcY('x') * $new[1]['y']) +
		($this->getVtcZ('x') * $new[1]['z']) + ($this->getVtx0('x') * $new[1]['w']);
		$result->_vtcY['y'] = ($this->getVtcX('y') * $new[1]['x']) + ($this->getVtcY('y') * $new[1]['y']) +
		($this->getVtcZ('y') * $new[1]['z']) + ($this->getVtx0('y') * $new[1]['w']);
		$result->_vtcY['z'] = ($this->getVtcX('z') * $new[1]['x']) + ($this->getVtcY('z') * $new[1]['y']) +
		($this->getVtcZ('z') * $new[1]['z']) + ($this->getVtx0('z') * $new[1]['w']);
		$result->_vtcY['w'] = ($this->getVtcX('w') * $new[1]['x']) + ($this->getVtcY('w') * $new[1]['y']) +
		($this->getVtcZ('w') * $new[1]['z']) + ($this->getVtx0('w') * $new[1]['w']);

		$result->_vtcZ['x'] = ($this->getVtcX('x') * $new[2]['x']) + ($this->getVtcY('x') * $new[2]['y']) +
		($this->getVtcZ('x') * $new[2]['z']) + ($this->getVtx0('x') * $new[2]['w']);
		$result->_vtcZ['y'] = ($this->getVtcX('y') * $new[2]['x']) + ($this->getVtcY('y') * $new[2]['y']) +
		($this->getVtcZ('y') * $new[2]['z']) + ($this->getVtx0('y') * $new[2]['w']);
		$result->_vtcZ['z'] = ($this->getVtcX('z') * $new[2]['x']) + ($this->getVtcY('z') * $new[2]['y']) +
		($this->getVtcZ('z') * $new[2]['z']) + ($this->getVtx0('z') * $new[2]['w']);
		$result->_vtcZ['w'] = ($this->getVtcX('w') * $new[2]['x']) + ($this->getVtcY('w') * $new[2]['y']) +
		($this->getVtcZ('w') * $new[2]['z']) + ($this->getVtx0('w') * $new[2]['w']);

		$result->_vtx0['x'] = ($this->getVtcX('x') * $new[3]['x']) + ($this->getVtcY('x') * $new[3]['y']) +
		($this->getVtcZ('x') * $new[3]['z']) + ($this->getVtx0('x') * $new[3]['w']);
		$result->_vtx0['y'] = ($this->getVtcX('y') * $new[3]['x']) + ($this->getVtcY('y') * $new[3]['y']) +
		($this->getVtcZ('y') * $new[3]['z']) + ($this->getVtx0('y') * $new[3]['w']);
		$result->_vtx0['z'] = ($this->getVtcX('z') * $new[3]['x']) + ($this->getVtcY('z') * $new[3]['y']) +
		($this->getVtcZ('z') * $new[3]['z']) + ($this->getVtx0('z') * $new[3]['w']);
		$result->_vtx0['w'] = ($this->getVtcX('w') * $new[3]['x']) + ($this->getVtcY('w') * $new[3]['y']) +
		($this->getVtcZ('w') * $new[3]['z']) + ($this->getVtx0('w') * $new[3]['w']);
		return ($result);
	}

	public function transformVertex($vtx) {
		$x = $vtx->getX() * $this->getVtcX('x') + $vtx->getY() * $this->getVtcY('x') + $vtx->getZ() * $this->getVtcZ('x') + $this->getVtx0('x');
		$y = $vtx->getX() * $this->getVtcX('y') + $vtx->getY() * $this->getVtcY('y') + $vtx->getZ() * $this->getVtcZ('y') + $this->getVtx0('y');
		$z = $vtx->getX() * $this->getVtcX('z') + $vtx->getY() * $this->getVtcY('z') + $vtx->getZ() * $this->getVtcZ('z') + $this->getVtx0('z');
		$w = $vtx->getX() * $this->getVtcX('w') + $vtx->getY() * $this->getVtcY('w') + $vtx->getZ() * $this->getVtcZ('w') + $this->getVtx0('w');
		return (new Vertex([
			'x' => $x / $w,
			'y' => $y / $w,
			'z' => $z / $w
		]));
	}

	public function __construct(array $kwargs) {
		if ($kwargs['preset'] === self::IDENTITY)
			$this->identity();
		if ($kwargs['preset'] === self::TRANSLATION)
			$this->translation($kwargs);
		if ($kwargs['preset'] === self::SCALE)
			$this->scale($kwargs['scale']);
		if ($kwargs['preset'] === self::RX)
			$this->rx($kwargs['angle']);
		if ($kwargs['preset'] === self::RY)
			$this->ry($kwargs['angle']);
		if ($kwargs['preset'] === self::RZ)
			$this->rz($kwargs['angle']);
		if ($kwargs['preset'] === self::PROJECTION)
			$this->projection($kwargs['fov'], $kwargs['ratio'],$kwargs['near'], $kwargs['far']);
		if (self::$verbose === True)
			echo 'Matrix '.$kwargs['preset'].' instance constructed'.PHP_EOL;
		return;
	}

	public function __destruct() {
		if (self::$verbose === True)
			echo 'Matrix instance destructed'.PHP_EOL;
		return;
	}

	public function __toString() {
		return
			('M | vtcX | vtcY | vtcZ | vtx0'."\n".'-----------------------------'."\n".'x | '
				.number_format($this->getVtcX('x'),2).' | '.number_format($this->getVtcY('x'),2).' | '
				.number_format($this->getVtcZ('x'),2).' | '.number_format($this->getVtx0('x'),2)."\n"
				.'y | '
				.number_format($this->getVtcX('y'),2).' | '.number_format($this->getVtcY('y'),2).' | '
				.number_format($this->getVtcZ('y'),2).' | '.number_format($this->getVtx0('y'),2)."\n"
				.'z | '
				.number_format($this->getVtcX('z'),2).' | '.number_format($this->getVtcY('z'),2).' | '
				.number_format($this->getVtcZ('z'),2).' | '.number_format($this->getVtx0('z'),2)."\n"
				.'w | '
				.number_format($this->getVtcX('w'),2).' | '.number_format($this->getVtcY('w'),2).' | '
				.number_format($this->getVtcZ('w'),2).' | '.number_format($this->getVtx0('w'),2));
	}
}
?>
