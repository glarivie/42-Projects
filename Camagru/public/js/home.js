(function() {
	var sub = document.querySelector('#subscription'),
		connect = document.querySelector('#connection'),
		hlogin = document.querySelector('#home-login'),
		hsignup = document.querySelector('#home-signup'),
		hloga = document.querySelector('#home-login a'),
		hsigna = document.querySelector('#home-signup a'),
		left = document.querySelector('.home .home-right'),
		signupEmail = document.getElementById('signup-email'),
		signupLogin = document.getElementById('signup-login'),
		signupPasswd = document.getElementById('signup-passwd'),
		signupCheck = document.getElementById('signup-check-passwd'),
		loginLogin = document.getElementById('login-login'),
		loginPasswd = document.getElementById('login-passwd'),
		signupButton = document.getElementById('signup-button'),
		loginButton = document.getElementById('login-button');

	connect.style.display = 'none';
	hsignup.style.display = 'none';

	hloga.addEventListener('click', function(e) {
		e.preventDefault();
		sub.style.display = 'none';
		hlogin.style.display = 'none';
		connect.style.display = 'block';
		hsignup.style.display = 'block';
		left.style.marginTop = '70px';
	},false);

	hsigna.addEventListener('click', function(e) {
		e.preventDefault();
		connect.style.display = 'none';
		hsignup.style.display = 'none';
		sub.style.display = 'block';
		hlogin.style.display = 'block';
		left.style.marginTop = '0';
	},false);

	function validateEmail(email) {
		var regex = 	/^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
		return regex.test(email);
	}

	signupEmail.addEventListener('keyup', function(e) {
		if (!validateEmail(e.target.value))
			e.target.style.borderColor = 'red';
		else
			e.target.style.borderColor = '#4090db';
	}, false);

	signupPasswd.addEventListener('keyup', function(e) {
		if (e.target.value.length >= 4 && e.target.value.length <= 50)
			e.target.style.borderColor = '#4090db';
		else
			e.target.style.borderColor = 'red';
		if (e.target.value !== signupCheck.value)
			signupCheck.style.borderColor = 'red';
		else
			signupCheck.style.borderColor = '#4090db';
	}, false);

	signupLogin.addEventListener('keyup', function(e) {
		if (e.target.value.length >= 3 && e.target.value.length <= 32)
			e.target.style.borderColor = '#4090db';
		else
			e.target.style.borderColor = 'red';
	}, false);

	signupCheck.addEventListener('keyup', function(e) {
		if (e.target.value !== signupPasswd.value)
			e.target.style.borderColor = 'red';
		else
			e.target.style.borderColor = '#4090db';
	}, false);

	sub.addEventListener('submit', function(e) {
		if (!validateEmail(signupEmail.value) || signupPasswd.value !== signupCheck.value || !signupLogin.value) {
			e.preventDefault();
		}
	}, false);

})();
