(function() {
	var state = {
		hasValidUsername : false,
		hasValidPassword : false,
		hasValidEmail : false,
		hasValidFirstname : false,
		hasValidLastname : false,
		hasValidAvatar : false
	};

	var userData = {
		username : "",
		password : "",
		mail : "",
		firstname : "",
		lastname : "",
		avatar : ""
	};

	$('div.username-field > input#username').on('change keyup input', function(e) {
		if (lib.isValidUsername(lib.protectEntry(e.target.value))) {
			$('div.username-field').removeClass('has-error').addClass('has-success');
			state.hasValidUsername = true;
			$('button#register-btn').trigger('register-success');
			userData.username = lib.protectEntry(e.target.value);
		} else {
			$('div.username-field').removeClass('has-success').addClass('has-error');
			state.hasValidUsername = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('div.password-field > input#password').on('change keyup input', function(e) {
		if (lib.isValidPassword(lib.protectEntry(e.target.value))) {
			$('div.password-field').removeClass('has-error').addClass('has-success');
			state.hasValidPassword = true;
			$('button#register-btn').trigger('register-success');
			userData.password = lib.protectEntry(e.target.value);
		} else {
			$('div.password-field').removeClass('has-success').addClass('has-error');
			state.hasValidPassword = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('div.mail-field > input#mail').on('change keyup input', function(e) {
		if (lib.isValidEmail(lib.protectEntry(e.target.value))) {
			$('div.mail-field').removeClass('has-error').addClass('has-success');
			state.hasValidEmail = true;
			$('button#register-btn').trigger('register-success');
			userData.mail = lib.protectEntry(e.target.value);
		} else {
			$('div.mail-field').removeClass('has-success').addClass('has-error');
			state.hasValidEmail = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('div.firstname-field > input#firstname').on('change keyup input', function(e) {
		if (lib.isValidName(lib.protectEntry(e.target.value))) {
			$('div.firstname-field').removeClass('has-error').addClass('has-success');
			state.hasValidFirstname = true;
			$('button#register-btn').trigger('register-success');
			userData.firstname = lib.protectEntry(e.target.value);
		} else {
			$('div.firstname-field').removeClass('has-success').addClass('has-error');
			state.hasValidFirstname = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('div.lastname-field > input#lastname').on('change keyup input', function(e) {
		if (lib.isValidName(lib.protectEntry(e.target.value))) {
			$('div.lastname-field').removeClass('has-error').addClass('has-success');
			state.hasValidLastname = true;
			$('button#register-btn').trigger('register-success');
			userData.lastname = lib.protectEntry(e.target.value);
		} else {
			$('div.lastname-field').removeClass('has-success').addClass('has-error');
			state.hasValidLastname = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('.avatar-field :file').on('change', function() {
		var file = $('#avatar')[0].files[0];

		if (lib.hasValidExtension(file)) {
			$('div.avatar-field').removeClass('has-error').addClass('has-success');
			state.hasValidAvatar = true;
			$('button#register-btn').trigger('register-success');

			var reader = new FileReader();
			$(reader).on('load', function() {
				userData.avatar = reader.result;
			});
			reader.readAsDataURL(file);
		} else {
			$('div.avatar-field').removeClass('has-success').addClass('has-error');
			state.hasValidAvatar = false;
			$('button#register-btn').trigger('register-error');
		}
	});

	$('button#register-btn').on({
		'register-success' : function() {
			if (state.hasValidUsername && state.hasValidPassword && state.hasValidEmail && state.hasValidFirstname && state.hasValidLastname && state.hasValidAvatar)
				$(this).removeAttr('disabled');
		},
		'register-error' : function() {
			$(this).attr('disabled', true);
		},
		'click' : function() {
			var self = this;
			$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
			$.post('/api/user/new', { user : userData }).done(function(data) {
				if (data.state === 'success')
					window.location = '/app/library';
				else if (data.state === 'user already exist') {
					$(self).html('<i class="fa fa-sign-in" aria-hidden="true"></i> Register');
					$('div.username-field').removeClass('has-success').addClass('has-error');
					state.hasValidUsername = false;
					$('div.mail-field').removeClass('has-success').addClass('has-error');
					state.hasValidEmail = false;
					$(self).trigger('register-error');
				}
			});
		}
	});

})();
