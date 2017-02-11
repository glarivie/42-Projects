(function() {
	var defaut = document.querySelector('.forgot .default'),
		message = document.querySelector('.forgot .message'),
		inputEmail = document.querySelector('.forgot .default input'),
		button = document.querySelector('.forgot .default button'),
		form = document.querySelector('.forgot .default .forgot-password');

	function validateEmail(email) {
		var regex = 	/^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
		return regex.test(email);
	}

	inputEmail.addEventListener('keyup', function(e) {
		if (!validateEmail(e.target.value)) {
			e.target.style.borderColor = 'red';
			button.disabled = true;
			button.classList.add('disabled');
		} else {
			e.target.style.borderColor = '#4090db';
			button.disabled = false;
			button.classList.remove('disabled');
		}
	}, false);

	form.addEventListener('submit', function() {
		defaut.classList.add('hidden');
		message.classList.remove('hidden');
	}, false);
})();
