(function() {
	var state = {
		hasValidPassword : false,
		hasValidEmail : false,
		hasValidFirstname : false,
		hasValidLastname : false,
		hasValidAvatar : false
	};

	var userData = {
		password : "",
		mail : $('#mail').val(),
		firstname : $('#firstname').val(),
		lastname : $('#lastname').val(),
		avatar : $('.avatar-field').data('avatar')
	};

	$('div.password-field > input#password').on('change keyup input', function(e) {
		if (lib.isValidPassword(lib.protectEntry(e.target.value))) {
			$('div.password-field').removeClass('has-error').addClass('has-success');
			state.hasValidPassword = true;
			$('button#profile-btn').removeAttr('disabled');
			userData.password = lib.protectEntry(e.target.value);
		} else {
			$('div.password-field').removeClass('has-success').addClass('has-error');
			state.hasValidPassword = false;
			$('button#profile-btn').attr('disabled', true);
		}
	});

	$('div.mail-field > input#mail').on('change keyup input', function(e) {
		$('#public-mail').html(lib.protectEntry(e.target.value));
		if (lib.isValidEmail(lib.protectEntry(e.target.value))) {
			$('div.mail-field').removeClass('has-error').addClass('has-success');
			state.hasValidEmail = true;
			$('button#profile-btn').removeAttr('disabled');
			userData.mail = lib.protectEntry(e.target.value);
		} else {
			$('div.mail-field').removeClass('has-success').addClass('has-error');
			state.hasValidEmail = false;
			$('button#profile-btn').attr('disabled', true);
		}
	});

	$('div.firstname-field > input#firstname').on('change keyup input', function(e) {
		$('#public-firstname').html(lib.protectEntry(e.target.value));
		$('#nav-username').html(lib.protectEntry(e.target.value));
		if (lib.isValidName(lib.protectEntry(e.target.value))) {
			$('div.firstname-field').removeClass('has-error').addClass('has-success');
			state.hasValidFirstname = true;
			$('button#profile-btn').removeAttr('disabled');
			userData.firstname = lib.protectEntry(e.target.value);
		} else {
			$('div.firstname-field').removeClass('has-success').addClass('has-error');
			state.hasValidFirstname = false;
			$('button#profile-btn').attr('disabled', true);
		}
	});

	$('div.lastname-field > input#lastname').on('change keyup input', function(e) {
		$('#public-lastname').html(lib.protectEntry(e.target.value));
		if (lib.isValidName(lib.protectEntry(e.target.value))) {
			$('div.lastname-field').removeClass('has-error').addClass('has-success');
			state.hasValidLastname = true;
			$('button#profile-btn').removeAttr('disabled');
			userData.lastname = lib.protectEntry(e.target.value);
		} else {
			$('div.lastname-field').removeClass('has-success').addClass('has-error');
			state.hasValidLastname = false;
			$('button#profile-btn').attr('disabled', true);
		}
	});

	$('.avatar-field :file').on('change', function() {
		var file = $('#avatar')[0].files[0];

		if (lib.hasValidExtension(file)) {
			$('div.avatar-field').removeClass('has-error').addClass('has-success');
			state.hasValidAvatar = true;
			$('button#profile-btn').removeAttr('disabled');

			var reader = new FileReader();
			$(reader).on('load', function() {
				$('#public-avatar').css('background-image', 'url(' + reader.result + ')');
				userData.avatar = reader.result;
			});
			reader.readAsDataURL(file);
		} else {
			$('div.avatar-field').removeClass('has-success').addClass('has-error');
			state.hasValidAvatar = false;
			$('button#profile-btn').attr('disabled', true);
		}
	});

	$('.edit-info-icon').on('click', function() {
		$('.edit-infos').toggleClass('hidden');
		$('.player-block').toggleClass('top-modif');
	});

	$('button#profile-btn').on('click', function() {
		console.log(userData);
		console.log(state);
		var self = this;
		$(self).html('<i class="fa fa-refresh" aria-hidden="true"></i> Loading...');
		$.post('/api/user/edit', {
			user : userData,
			state : state
		}).done(function(data) {
			if (data.state === 'success')
				$(self).html('<i class="fa fa-check" aria-hidden="true"></i> Informations updated');
			else if (data.state !== 'success') {
				$(self).html('<i class="fa fa-sign-in" aria-hidden="true"></i> Submit my new details');
				$('div.username-field').removeClass('has-success').addClass('has-error');
				state.hasValidUsername = false;
				$('div.mail-field').removeClass('has-success').addClass('has-error');
				state.hasValidEmail = false;
				$(self).attr('disabled', true);
			}
		});
	});
})();
