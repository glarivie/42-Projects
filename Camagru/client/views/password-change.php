<article class="success forgot">
	<div class="default">
		<h3 style="color:#333;">Hi <?php echo $data['login'];?>, here you can change your password :</h3>
		<form class="password-change" action="../../server/passwordChange.php" method="POST">
			<input type="password" name="password" value="" placeholder="Enter your new password">
			<input type="password" name="password-check" value="" placeholder="Verifiy your password">
			<input class="hidden" type="text" name="login" value="<?php echo $data['login'] ?>">
			<input class="hidden" type="text" name="oldpwd" value="<?php echo $data['whirlpool'] ?>">
			<button class="btn disabled" type="submit" name="button" disabled>Submit</button>
		</form>
	</div>
	<div class="hidden message">
		<p>SUCCESS !</p>
	</div>

</article>

<script type="text/javascript" src="../../public/js/change.js"></script>
