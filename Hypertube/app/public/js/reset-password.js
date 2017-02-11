(function() {
	var state = {
		hasValidPassword : false
	};

	var userData = {
		password : "",
		username : $('form').data('username'),
		token : $('form').data('token')
	};

	$('div.password-field > input#password').on('change keyup input', function(e) {
		if (lib.isValidPassword(lib.protectEntry(e.target.value))) {
			$('div.password-field').removeClass('has-error').addClass('has-success');
			state.hasValidPassword = true;
			$('button#reset-btn').trigger('reset-success');
			userData.password = lib.protectEntry(e.target.value);
		} else {
			$('div.password-field').removeClass('has-success').addClass('has-error');
			state.hasValidPassword = false;
			$('button#forgot-btn').trigger('reset-error');
		}
	});

	$('button#reset-btn').on({
		'reset-success' : function() {
			if (state.hasValidPassword)
				$(this).removeAttr('disabled');
		},
		'reset-error' : function() {
			$(this).attr('disabled', true);
		},
		'click' : function() {
			var self = this;
			$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
			$.post('/api/user/password/set', userData)
				.done(function(data) {
					if (data.state === 'success') {
						window.location = '/users/login';
					} else if (data.state !== 'success') {
						$(self).html('<i class="fa fa-lock" aria-hidden="true"></i> Set new password');
						$('div.password-field').removeClass('has-success').addClass('has-error');
						state.hasValidPassword = false;
						$(self).trigger('reset-error');
					}
			});
		}
	});
})();
