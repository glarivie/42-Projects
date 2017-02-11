<article class="success forgot">
	<div class="default">
		<h2 style="color:#333;">Enter your email address below and check your emails</h2>
		<form class="forgot-password" action="./server/changePassword.php" method="POST">
			<input type="email" name="email" value="" placeholder="Enter your account e-mail...">
			<button class="btn disabled" type="submit" name="button" disabled>Submit</button>
		</form>
	</div>
	<div class="hidden message">
		<p>SUCCESS ! Check your mails !</p>
	</div>

</article>

<script type="text/javascript" src="./public/js/forgot.js"></script>
