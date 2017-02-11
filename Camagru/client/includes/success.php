<?php session_start(); ?>

<article class="success">
	<h2><i class="fa fa-thumbs-up" aria-hidden="true"></i> SUCCESS !</h2>
	<p>Congratulations <strong><?php echo $_SESSION['login']; ?></strong>.</p>
	<p>Your registration is complete !</p>
	<p>Take a look at your mail (<em><?php echo $_SESSION['email']; ?></em>) to <u>validate your account</u> and start using our application.</p>
</article>
