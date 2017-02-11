<?php

function	ft_is_sort($tab)
{
	if (isset($tab))
	{
		$test = 0;
		$tab_test = $tab;

		sort($tab_test);
		for($index = 0; $index < count($tab) ; $index++)
		{
			if ($tab_test[$index] == $tab[$index])
				$test++;
		}
		return ($test == count($tab) ? TRUE : FALSE);
	}
}

?>
