<?php
class Lannister{
		public function islannister($l)
		{
			if (get_class($l) == "Cersei" || get_class($l) == "Jaimie" || get_class($l) == "Tyrion")
				return true;
			else
				return false;
		}
}
?>
