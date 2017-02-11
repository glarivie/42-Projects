<?php

function	ft_split($str)
{
	if(isset($str) && is_string($str))
	{
		$tab = explode(" ", $str);
		sort($tab);
		$tab = array_diff($tab, array(''));
		$tab = array_slice($tab, 0);
		return ($tab);
	}
}

?>
