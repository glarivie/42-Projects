(function() {
	var state = {
		hasValidUsername : false,
		hasValidPassword : false
	};

	var userData = {
		username : "",
		password : ""
	};

	$('div.login-field > input#login').on('change keyup input', function(e) {
		if (lib.isValidUsername(lib.protectEntry(e.target.value))) {
			$('div.login-field').removeClass('has-error').addClass('has-success');
			state.hasValidUsername = true;
			$('button#login-btn').trigger('login-success');
			userData.username = lib.protectEntry(e.target.value);
		} else {
			$('div.login-field').removeClass('has-success').addClass('has-error');
			state.hasValidUsername = false;
			$('button#login-btn').trigger('login-error');
		}
	});

	$('div.pwd-field > input#pwd').on('change keyup input', function(e) {
		if (lib.isValidPassword(lib.protectEntry(e.target.value))) {
			$('div.pwd-field').removeClass('has-error').addClass('has-success');
			state.hasValidPassword = true;
			$('button#login-btn').trigger('login-success');
			userData.password = lib.protectEntry(e.target.value);
		} else {
			$('div.pwd-field').removeClass('has-success').addClass('has-error');
			state.hasValidPassword = false;
			$('button#login-btn').trigger('login-error');
		}
	});

	$('button#login-btn').on({
		'login-success' : function() {
			if (state.hasValidUsername && state.hasValidPassword)
				$(this).removeAttr('disabled');
		},
		'login-error' : function() {
			$(this).attr('disabled', true);
		},
		'click' : function() {
			var self = this;
			$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
			$.post('/api/user/signin', { user : userData }).done(function(data) {
				if (data.state === 'success')
					window.location = '/app/library';
				else if (data.state === 'wrong password') {
					$(self).html('<i class="fa fa-sign-in" aria-hidden="true"></i> Sign-in');
					$('div.pwd-field').removeClass('has-success').addClass('has-error');
					state.hasValidPassword = false;
					$(self).trigger('login-error');
				} else if (data.state === 'user not found') {
					$(self).html('<i class="fa fa-sign-in" aria-hidden="true"></i> Sign-in');
					$('div.login-field').removeClass('has-success').addClass('has-error');
					state.hasValidUsername = false;
					$(self).trigger('login-error');
				}
			});
		}
	});
})();
