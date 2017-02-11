(function() {
	var state = {
		hasValidMail : false
	};

	var userData = {
		mail : ""
	};

	$('div.mail-field > input#mail').on('change keyup input', function(e) {
		if (lib.isValidEmail(lib.protectEntry(e.target.value))) {
			$('div.mail-field').removeClass('has-error').addClass('has-success');
			state.hasValidMail = true;
			$('button#forgot-btn').trigger('forgot-success');
			userData.mail = lib.protectEntry(e.target.value);
		} else {
			$('div.mail-field').removeClass('has-success').addClass('has-error');
			state.hasValidMail = false;
			$('button#forgot-btn').trigger('forgot-error');
		}
	});

	$('button#forgot-btn').on({
		'forgot-success' : function() {
			if (state.hasValidMail)
				$(this).removeAttr('disabled');
		},
		'forgot-error' : function() {
			$(this).attr('disabled', true);
		},
		'click' : function() {
			var self = this;
			$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
			$.post('/api/user/send-mail', { mail : userData.mail })
				.done(function(data) {
					if (data.state === 'success') {
						$(self).html('<i class="fa fa-check" aria-hidden="true"></i> Mail sent ! Check it');
						$(self).attr('disabled', true);
					} else if (data.state !== 'success') {
						$(self).html('<i class="fa fa-envelope" aria-hidden="true"></i> Send me instructions');
						$('div.mail-field').removeClass('has-success').addClass('has-error');
						state.hasValidMail = false;
						$(self).trigger('forgot-error');
					}
			});
		}
	});
})();
