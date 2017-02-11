<?php
class UnholyFactory {
	private $_army = array();
	public function absorb($class){
		if ($class instanceof Fighter)
		{
			if (in_array($class, $this->_army))
				print "(Factory already absorbed a fighter of type ".$class->name.")\n";
			else
				print "(Factory absorbed a fighter of type ".$class->name.")\n";
			$this->_army[] = $class;
		}
		else
			print "(Factory can't absorb this, it's not a fighter)\n";
	}
	public function fabricate($fighter){
		foreach ($this->_army as $elem)
		{
			if ($fighter == $elem->name)
			{
				print "(Factory fabricates a fighter of type ".$fighter.")\n";
				return $elem;
			}
		}
			print "(Factory hasn't absorbed any fighter of type ".$fighter.")\n";
			return NULL;
	}
}
?>
