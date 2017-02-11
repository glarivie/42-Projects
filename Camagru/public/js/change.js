(function() {
	var defaut = document.querySelector('.forgot .default'),
		message = document.querySelector('.forgot .message'),
		pwd = document.querySelector('.forgot .default input[name="password"]'),
		pwdCheck = document.querySelector('.forgot .default input[name="password-check"]'),
		button = document.querySelector('.forgot .default button'),
		form = document.querySelector('.forgot .default .password-change');

	pwd.addEventListener('keyup', function(e) {
		if (e.target.value.length >= 4 && e.target.value.length <= 50)
			e.target.style.borderColor = '#4090db';
		else
			e.target.style.borderColor = 'red';
		if (e.target.value !== pwdCheck.value)
			pwdCheck.style.borderColor = 'red';
		else
			pwdCheck.style.borderColor = '#4090db';
	}, false);

	pwdCheck.addEventListener('keyup', function(e) {
		if (e.target.value !== pwd.value)
			e.target.style.borderColor = 'red';
		else {
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
