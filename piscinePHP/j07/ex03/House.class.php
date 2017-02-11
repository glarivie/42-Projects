<?php
Class House {
	public function introduce() {
		print("House ".$this->getHouseName());
		print(" of ".$this->getHouseSeat());
		print(" : ".$this->getHouseMotto()."\n");
	}
}
?>
