<?php

$rootDIR = dirname(__DIR__, 2);
require_once($rootDIR . '/lib/getRequestURI.php');

?>

<article class="success">
	<h2 style="color:#333;">Something's wrong here</h2>
	<p>
		<a href="<?php echo getRootURI(); ?>">Go back to home page</a>
	</p>
</article>
