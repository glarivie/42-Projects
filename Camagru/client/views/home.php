<div class="home">
	<div class="left img-home">
		<img src="./public/img/home-monkey.png" alt="home monkey" />
	</div>
	<div class="right home-right">
		<div class="form">
			<!-- <img class="logo" src="" alt="" /> -->
			<h1>CAMA<span class="bold gray">GRU</span></h1>

			<!-- Subscription form -->
			<form id="subscription" method="post" action="./server/subscription.php">
				<h4>Sign up to see photos and videos from your friends.</h4>
				<button type="button" name="facebook connect"><i class="fa fa-facebook-official" aria-hidden="true"></i> Log in with Facebook</button>

				<span class="hr"><p class="or">OR</p></span>

				<input id="signup-email" type="email" name="email" value="" placeholder="Email" autocomplete="off">
				<input id="signup-login" type="text" name="login" value="" placeholder="Username (3 - 32)" autocomplete="off">
				<input id="signup-passwd" type="password" name="password" value="" placeholder="Password (4 - 50)" autocomplete="off">
				<input id="signup-check-passwd" type="password" name="password-check" value="" placeholder="Type your password again" autocomplete="off">
				<button id="signup-button" type="submit" name="subscribe"><i class="fa fa-sign-in" aria-hidden="true"></i> Sign up</button>
			</form>

			<!-- Connection form -->
			<form id="connection" method="post" action="./server/login.php">
				<h4>Sign-in to see photos and videos from your friends.</h4>
				<input id="login-login" type="text" name="login" value="" placeholder="Username" autocomplete="off">
				<input id="login-passwd" type="password" name="password" value="" placeholder="Password" autocomplete="off">
				<span id="forgot"><a href="forgot-password">Forgot ?</a></span>
				<button id="login-button" type="submit" name="connect"><i class="fa fa-sign-in" aria-hidden="true"></i> Log in</button>
			</form>

			<p>By signing up, you agree to our Terms & Privacy Policy.</p>
		</div>
		<div class="choice">
			<p id="home-login">Have an account? <a href="#">Log in</a></p>
			<p id="home-signup">Don't have an account? <a href="#">Sign up</a></p>
		</div>
	</div>
</div>

<script type="text/javascript" src="./public/js/home.js"></script>
