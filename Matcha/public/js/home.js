(function() {
  var form = {
    birthdate : false,
    email : false,
    username : false,
    firstname : false,
    lastname : false,
    password : false
  };

  var signinForm = {
    login : false,
    pwd: false
  };

  $('#bgvid').on('ended', function() {
    console.log('video ended');
    $(this).play();
  });

  $('#join-us').on('click', function() {
    $('.lead').addClass('hidden');
    $('#home-login').addClass('hidden');
    $('#home-forgot').addClass('hidden');
    $('#home-subscribe').removeClass('hidden');
    $('.jumbotron').css('margin-top', '3%');
  });

  $('#members').on('click', function() {
    $('.lead').addClass('hidden');
    $('#home-subscribe').addClass('hidden');
    $('#home-forgot').addClass('hidden');
    $('#home-login').removeClass('hidden');
    $('.jumbotron').css('margin-top', '6%');
  });

  $('#signin-forgot').on('click', function() {
    $('.lead').addClass('hidden');
    $('#home-subscribe').addClass('hidden');
    $('#home-login').addClass('hidden');
    $('#home-forgot').removeClass('hidden');
    $('.jumbotron').css('margin-top', '5%');
  });

  function checkBirthDate(dateToCheck){
    var arr_dateText = dateToCheck.split('/'),
      day = arr_dateText[0],
      month = arr_dateText[1],
      year = arr_dateText[2];

    var mydate = new Date();
    mydate.setFullYear(year, month - 1, day);
    var maxDate = new Date();
    maxDate.setYear(maxDate.getYear() - 18);

    if (maxDate < mydate)
      return false;
    return true;
  }

  function birthdateIsOk() {
    var currentBirthdate = $('#birthdate');
    if (currentBirthdate.val().length === 10) {
      if (checkBirthDate(currentBirthdate.val())) {
        $('#form-birthdate')
          .removeClass('has-error')
          .addClass('has-success');
        $('.form-sub').removeClass('hidden');
        form.birthdate = true;
        checkForm(form);
      } else {
        $('#form-birthdate')
          .removeClass('has-success')
          .addClass('has-error');
        $('.form-sub').addClass('hidden');
        form.birthdate = false;
      }
    }
  }

  function protectEntry(message) {
    message = message.replace(/&/g, '&amp;');
    message = message.replace(/</g, '&lt;');
    message = message.replace(/>/g, '&gt;');
    return (message);
  }

  function validateEmail(email) {
    var regex =   /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return regex.test(email);
  }

  function validateUsername(login) {
    var regex = /^([a-zA-Z\-0-9_]{4,17})$/;
    return regex.test(login);
  }

  function validateUser(name) {
    var regex = /^([a-zA-Z\-0-9èêéàôîïùñ]{4,17})$/;
    return regex.test(name);
  }

  function validatePassword(pwd) {
    var lowercase = /^(?=.*[a-z]).+$/,
      number = /^(?=.*[0-9]).+$/;

    if (pwd.length > 4 && pwd.length < 17 && number.test(pwd) && lowercase.test(pwd)) {
      return (true);
    }
    return (false);
  }

  function checkForm(form) {
    var count = 0;
    $.each(form, function(key, value) {
      if (value === false)
        count++;
    });
    if (count === 0)
      $('button.form-sub').removeAttr('disabled');
    else
      $('button.form-sub').attr('disabled', true);
  }

  function checkForm2(form) {
    var count = 0;
    $.each(signinForm, function(key, value) {
      if (value === false)
        count++;
    });
    if (count === 0)
      $('button#signin-button').removeAttr('disabled');
    else
      $('button#signin-button').attr('disabled', true);
  }


  $('#datetimepicker')
    .datetimepicker({
      format: 'L',
      locale: 'fr',
    })
    .on('dp.change', birthdateIsOk);

  $('#birthdate').on('keyup', birthdateIsOk);

  $('#email').on('change input keyup', function() {
    if ($(this).val().length > 6) {
      if (validateEmail($(this).val())) {
        $(this).closest('.form-sub')
          .removeClass('has-error')
          .addClass('has-success');
        $('.email-error').addClass('hidden');
        form.email = true;
        checkForm(form);
      } else {
        $(this).closest('.form-sub')
          .removeClass('has-success')
          .addClass('has-error');
        form.email = false;
        checkForm(form);
      }
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      form.email = false;
      checkForm(form);
    }
  });

  $('#email2').on('change input keyup', function() {
    if ($(this).val().length > 6) {
      if (validateEmail($(this).val())) {
        $(this).closest('.form-group')
          .removeClass('has-error')
          .addClass('has-success');
        $('button#forgot-button').removeAttr('disabled');
      } else {
        $(this).closest('.form-group')
          .removeClass('has-success')
          .addClass('has-error');
        $('button#forgot-button').attr('disabled', true);
      }
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      $('button#forgot-button').attr('disabled', true);
    }
  });

  $('#newPassword').on('change input keyup', function() {
    if (validatePassword($(this).val())) {
      $(this).closest('.form-group')
        .addClass('has-success')
        .removeClass('has-error');
      $('button#reset-button').removeAttr('disabled');
    } else {
      $(this).closest('.form-group')
        .removeClass('has-success')
        .addClass('has-error');
      $('button#reset-button').attr('disabled', true);
    }
  });

  $('#forgot-button').on('click', function() {
    if (validateEmail($('#email2').val())) {
      $.get('/send-reset-email/' + protectEntry($('#email2').val()))
        .done(function(data) {
          if (data.done === 'success')
            $('#forgot-button').html('<span class="glyphicon glyphicon-ok" aria-hidden="true"></span>&nbsp; Message sent, check your email !');
        });
    }
  });

  $('#reset-button').on('click', function() {
    if ($('#newPassword').val().length > 4 && $('#newPassword').val().length < 17) {
      $.get('/reset-my-password/' + $('#home-forgot').data('id') + '/' + $('#newPassword').val()).done(function(data) {
          if (data.done === 'success')
            $('#reset-button').html('<span class="glyphicon glyphicon-ok" aria-hidden="true"></span>&nbsp; Password changed, redirect...');
            $(location).attr('href', '/');
        });
    }
  });

  $('#login').on('change input keyup', function() {
    if ($(this).val().length > 3) {
      if (validateUsername($(this).val())) {
        $(this).closest('.form-sub')
          .removeClass('has-error')
          .addClass('has-success');
        $('.login-error').addClass('hidden');
        form.username = true;
        checkForm(form);
      } else {
        $(this).closest('.form-sub')
          .removeClass('has-success')
          .addClass('has-error');
        form.username = false;
        checkForm(form);
      }
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      form.username = false;
      checkForm(form);
    }
  });

  $('#firstname').on('change input keyup', function() {
    if ($(this).val().length > 2) {
      if (validateUser($(this).val())) {
        $(this).closest('.form-sub')
          .removeClass('has-error')
          .addClass('has-success');
        form.firstname = true;
        checkForm(form);
      } else {
        $(this).closest('.form-sub')
          .removeClass('has-success')
          .addClass('has-error');
        form.firstname = false;
        checkForm(form);
      }
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      form.firstname = false;
      checkForm(form);
    }
  });

  $('#lastname').on('change input keyup', function() {
    if ($(this).val().length > 2) {
      if (validateUser($(this).val())) {
        $(this).closest('.form-sub')
          .removeClass('has-error')
          .addClass('has-success');
        form.lastname = true;
        checkForm(form);
      } else {
        $(this).closest('.form-sub')
          .removeClass('has-success')
          .addClass('has-error');
        form.lastname = false;
        checkForm(form);
      }
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      form.lastname = false;
      checkForm(form);
    }
  });

  $('#password').on('change input keyup', function() {
    if (validatePassword($(this).val())) {
      $(this).closest('.form-sub')
        .removeClass('has-error')
        .addClass('has-success');
      form.password = true;
      checkForm(form);
    } else {
      $(this).closest('.form-sub')
        .removeClass('has-success')
        .addClass('has-error');
      form.password = false;
      checkForm(form);
    }
  });

  $('#login2').on('change input keyup', function() {
    if ($(this).val().length > 3) {
      if (validateUsername($(this).val())) {
        $(this).closest('.form-group')
          .removeClass('has-error')
          .addClass('has-success');
        $('.login2-error').addClass('hidden');
        signinForm.login = true;
        checkForm2(signinForm);
      } else {
        $(this).closest('.form-group')
          .removeClass('has-success')
          .addClass('has-error');
        signinForm.login = false;
        checkForm2(signinForm);
      }
    } else {
      $(this).closest('.form-group')
        .removeClass('has-success')
        .addClass('has-error');
      signinForm.login = false;
      checkForm2(signinForm);
    }
  });

  $('#password2').on('change input keyup', function() {
    if (validatePassword($(this).val())) {
      $(this).closest('.form-group')
        .removeClass('has-error')
        .addClass('has-success');
      $('.password2-error').addClass('hidden');
      signinForm.pwd = true;
      checkForm2(signinForm);
    } else {
      $(this).closest('.form-group')
        .removeClass('has-success')
        .addClass('has-error');
      signinForm.pwd = false;
      checkForm2(signinForm);
    }
  });

  $('button.form-sub').on('submit click', function(e) {
    e.preventDefault();
    var newUser = {
      username : protectEntry($('#login').val()),
      password : $('#password').val(),
      mail : protectEntry($('#email').val()),
      firstname : protectEntry($('#firstname').val()),
      lastname : protectEntry($('#lastname').val()),
      birthdate : protectEntry($('#birthdate').val())
    };

    $.post('/user/add', newUser)
      .done(function(data) {
        console.log('Data sent successfully !', data);
        if (typeof data.redirect == 'string')
          window.location = data.redirect;
        if (data.error === 'login') {
          $('#login').closest('.form-sub')
            .removeClass('has-success')
            .addClass('has-error');
          $('.login-error').removeClass('hidden');
          form.username = false;
          checkForm(form);
        } else if (data.error === 'mail') {
          $('#email').closest('.form-sub')
            .removeClass('has-success')
            .addClass('has-error');
          $('.email-error').removeClass('hidden');
          form.email = false;
          checkForm(form);
        }
      }).fail(function() {
        console.log('Failed to create new user...');
      });
  });

  $('button#signin-button').on('submit click', function(e) {
    e.preventDefault();
    var user = {
      username : protectEntry($('#login2').val()),
      password : $('#password2').val()
    };

    $.post('/user/login', user)
      .done(function(data) {
        console.log('User connection detected');
        if (typeof data.redirect == 'string')
          window.location = data.redirect;
        if (data.error === 'login') {
          $('#login2').closest('.form-group')
            .removeClass('has-success')
            .addClass('has-error');
          $('.login2-error').removeClass('hidden');
          signinForm.login = false;
          checkForm2(signinForm);
        } else if (data.error === 'password') {
          $('#password2').closest('.form-group')
            .removeClass('has-success')
            .addClass('has-error');
          $('.password2-error').removeClass('hidden');
          signinForm.pwd = false;
          checkForm2(signinForm);
        }
      }).fail(function() {
        console.log('Failed to find user...');
      });
  });
})();
