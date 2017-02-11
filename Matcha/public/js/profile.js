const userID = $('.actions > a').attr('href').split('/')[2];
const geoMap = $('#geo-map');
const lat = geoMap.data('latitude');
const lng = geoMap.data('longitude');
const apiKey = 'AIzaSyD3sBJxfVvWi7lTho6zvsaLm_-0zhCdDCI';

const initStaticMap = (lat, lng) =>
  `https://maps.googleapis.com/maps/api/staticmap?center=${lat},${lng}&size=330x280
  &markers=red:yellow%7Clabel:S%7C${lat},${lng}
  &key=${apiKey}&zoom=16`;

$(document).ready(() => {
  if (navigator.onLine) {
    $('#connected').html('<span class="glyphicon glyphicon-ok" aria-hidden="true"></span> Yes');
  }

  $.get('/set/connexion');

  if (lat && lng) {
    const url = initStaticMap(lat, lng);
    geoMap.attr('src', url).removeClass('hidden');
  }

  if (parseInt($('#like .badge').html(), 10) > 0) {
    $('#like .glyphicon')
      .removeClass('glyphicon-heart-empty')
      .addClass('glyphicon-heart');
  }

  $.get(`/user/new/visit/${userID}`).done((data) => {
    if (data.done === 'success')
      console.log('new visitor add');
    if (data.done === 'already')
      console.log('you have already seen this profile before');
  });

  $.get('/user/get/visits/' + userID).done(function(data) {
    if (data.done === 'success') {
      $.each(data.visits, function(index, value) {
        $('#visit' + index + ' .img').css('background-image', 'url(' + value.photo + ')');
        $('#visit' + index + ' h5').html(value.firstname);
        $('#visit' + index + ' .location').html(value.location);
        $('#visit' + index + ' > a').attr('href', '/user/' + value.id);
        $('#visit' + index).removeClass('hidden');
      });
    }
  });

  $.get('/user/get/likes/' + userID).done(function(data) {
    if (data.done === 'success') {
      $.each(data.likes, function(index, value) {
        $('#like' + index + ' .img').css('background-image', 'url(' + value.photo + ')');
        $('#like' + index + ' h5').html(value.firstname);
        $('#like' + index + ' .location').html(value.location);
        $('#like' + index + ' > a').attr('href', '/user/' + value.id);
        $('#like' + index).removeClass('hidden');
      });
    }
  });

  $.get('/popularity/' + userID).done(function(data) {
    if (typeof data.score !== 'undefined')
      $('#popularity').html(data.score + '%');
  });
});

function protectEntry(message) {
  message = message.replace(/&/g, '&amp;');
  message = message.replace(/</g, '&lt;');
  message = message.replace(/>/g, '&gt;');
  return (message);
}

$('#update-location').on('click', function() {
  $('#span-location').html('Please wait while we are fetching data...');
  $('#update-location').attr('disabled', true);
  $.geolocation.get()
    .done(function(position) {
			console.log('geolocation enabled');
      $.post('/location', position.coords)
        .done(function(data) {
					console.log(data.address);
          $('#span-location').html(data.address);
          $('#update-location').removeAttr('disabled');
          const url = initStaticMap(position.coords.latitude, position.coords.longitude);
          geoMap.attr('src', url).removeClass('hidden');
        });
    }).fail(function() {
      console.log('geolocation disabled');
      $.get('/location')
        .done(function(data) {
          $('#span-location').html(data.city + ', ' + data.country);
          $('#update-location').removeAttr('disabled');
          const url = initStaticMap(data.latitude, data.longitude);
          geoMap.attr('src', url).removeClass('hidden');
        });
    });
});

$('.thumbnail').on({
  'mouseover' : function() {
    $(this).find('.img').css({
      'filter' : 'grayscale(1) brightness(0.8)',
      '-webkit-filter' : 'grayscale(1) brightness(0.8)',
      '-moz-filter' : 'grayscale(1) brightness(0.8)',
      '-o-filter' : 'grayscale(1) brightness(0.8)',
      '-ms-filter' : 'grayscale(1) brightness(0.8)'
    });
    //$(this).find('.caption').removeClass('hidden');
  },
  'mouseout' : function() {
    $(this).find('.img').css({
      'filter' : 'grayscale(0) brightness(1)',
      '-webkit-filter' : 'grayscale(0) brightness(1)',
      '-moz-filter' : 'grayscale(0) brightness(1)',
      '-o-filter' : 'grayscale(0) brightness(1)',
      '-ms-filter' : 'grayscale(0) brightness(1)'
    });
    //$(this).find('.caption').addClass('hidden');
  }
});

$('#btn-edit-bio').on('click', function(){
  $(this).addClass('hidden');
  $('#span-bio').addClass('hidden');
  $('#bio-area-edit').removeClass('hidden');
});

$('#bio-area-button').on('click', function() {
  var biography = protectEntry($('#textarea-bio').val());

  $.post('/biography/update', { biography : biography })
    .done(function(data) {
      //console.log('post ' + data.done);
      $('#bio-area-edit').addClass('hidden');
      $('#btn-edit-bio').removeClass('hidden');
      $('#span-bio').html(biography).removeClass('hidden');
    }).fail(function() {
      console.log('post error');
    });
});

function validateUser(name) {
  var regex = /^([a-zA-Z\-0-9èêéàôîïùñ]{2,17})$/;
  return regex.test(name);
}

function validateEmail(email) {
  var regex =   /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return regex.test(email);
}

$('#edit-first-last').on('click', function() {
  $('#first-last').addClass('hidden');
  $('#form-first-last').removeClass('hidden');
});

$('#change-first-last').on('click', function() {
  var infos = {
    firstname: protectEntry($('#first-input').val()),
    lastname: protectEntry($('#last-input').val())
  };
  if (validateUser(infos.firstname) && validateUser(infos.lastname)) {
    $.post('/name/update', infos)
      .done(function(data) {
        if (data.done === 'success') {
          $('#user-first').html(infos.firstname);
          $('#user-last').html(infos.lastname);
          $('#form-first-last').addClass('hidden');
          $('#first-last').removeClass('hidden');
        } else
          $('#form-first-last').addClass('has-error');
      });
  } else
    $('#form-first-last').addClass('has-error');
});

$('#edit-mail').on('click', function() {
  $('#mail').addClass('hidden');
  $('#form-mail').removeClass('hidden');
});

$('#change-mail').on('click', function() {
  var infos = { mail : protectEntry($('#mail-input').val()) };

  if (validateEmail(infos.mail)) {
    $.post('/mail/update', infos)
      .done(function(data) {
        if (data.done === 'success') {
          $('#user-mail').html(infos.mail);
          $('#form-mail').addClass('hidden');
          $('#mail').removeClass('hidden');
        } else
          $('#form-mail').addClass('has-error');
      });
  } else
    $('#form-mail').addClass('has-error');
});

$('#edit-sex').on('click', function() {
  $('#sex').addClass('hidden');
  $('#form-sex').removeClass('hidden');
});

$('#select-sex').on('click', function() {
  if ($('.gender-input:checked').val()) {
    var data = {sex : $('.gender-input:checked').val()};
    if (data.sex === 'Male' || data.sex === 'Female' || data.sex === 'Other') {
      $.post('/sex/update', data)
        .done(function(data) {
          if (data.done === 'success') {
            $('#span-sex').html($('.gender-input:checked').val());
            $('#form-sex').addClass('hidden');
            $('#sex').removeClass('hidden');
          }
        });
    }
  }
});

$('#edit-orientation').on('click', function() {
  $('#orientation').addClass('hidden');
  $('#form-orientation').removeClass('hidden');
});

$('#select-orientation').on('click', function() {
  if ($('.orientation-input:checked').val()) {
    var data = {orientation : $('.orientation-input:checked').val()};
    if (data.orientation === 'Straight' || data.orientation === 'Gay' || data.orientation === 'Bisexual') {
      $.post('/orientation/update', data)
        .done(function(data) {
          if (data.done === 'success') {
            $('#span-orientation').html($('.orientation-input:checked').val());
            $('#form-orientation').addClass('hidden');
            $('#orientation').removeClass('hidden');
          }
        });
    }
  }
});

function supprBtnTag() {
  $('.btn-tag').on({
    'mouseover' : function() {
      $(this).find('span.glyphicon')
        .removeClass('glyphicon-tag')
        .addClass('glyphicon-minus-sign');
    }, 'mouseout' : function() {
      $(this).find('span.glyphicon')
        .removeClass('glyphicon-minus-sign')
        .addClass('glyphicon-tag');
    }, 'click' : function() {
      var current = $(this);
      $.post('/interest/delete', {delete : current.find('.span-interest').html()})
        .done(function(data) {
          if (data.done === 'success')
            current.remove();
        });
    }
  });
}

supprBtnTag();

function prepareInterests(interests) {
  var toPrint = '';
  $.each(interests, function(key, val) {
    toPrint += '<button type="button" class="btn btn-warning btn-xs btn-tag"><span class="glyphicon glyphicon-tag" aria-hidden="true"></span> <span class="span-interest">' + val + '</span></button> ';
  });
  return (toPrint);
}

function validateInterest(interest) {
  var regex = /^([a-zA-Z\-]{1,17})$/;
  return regex.test(interest);
}

$('#add-interest').on('click', function() {
  $('.input-interest').val('');
  $(this).addClass('hidden');
  $('#form-interests').removeClass('hidden');
  $.get('/interests/list')
    .done(function(data) {
      $('#list-interests').empty();
      $.each(data.list, function(key, val) {
        $('#list-interests').append('<option value="' + val + '">');
      });
    });
});

$('#new-interest').on('click', function() {
  if ($('.input-interest').val() && validateInterest(protectEntry($('.input-interest').val()))) {
    $('#form-interests').removeClass('has-error');
    var data = {
      newInterest : protectEntry($('.input-interest').val())
    };
    $.post('/interest/add', data)
      .done(function(data) {
        if (data.done === 'success') {
          $('#interests').empty().html(prepareInterests(data.interests));
          supprBtnTag();
          $('#add-interest').removeClass('hidden');
          $('#form-interests').addClass('hidden');
        } else
          $('#form-interests').addClass('has-error');
      });
  } else
    $('#form-interests').addClass('has-error');
});

var allowedTypes = ['png', 'jpg', 'jpeg', 'gif'];

$('#btn-cover :file').on('change', function(e) {
  if (e.target.files.length) {
    var fileType = (e.target.files[0].name.split('.')).pop().toLowerCase();

    if (allowedTypes.indexOf(fileType) != -1) {
      var file = e.target.files[0],
        reader = new FileReader();

      $(reader).on('load', function() {
        $.post('/cover/upload', {cover : reader.result})
          .done(function(data) {
            if (data.done === 'success')
              $('.header-picture').css('background-image', 'url("' + reader.result + '")');
          });
      });
      reader.readAsDataURL(file);
    }
  }
});

$('.change-photo :file').on('change', function(e) {
  if (e.target.files.length) {
    var fileType = (e.target.files[0].name.split('.')).pop().toLowerCase(),
      imgIndex = $(this).data('index');

    if (allowedTypes.indexOf(fileType) != -1) {
      var file = e.target.files[0],
        reader = new FileReader();

      $(reader).on('load', function() {
        $.post('/photo/upload', {
          photo : reader.result,
          index : imgIndex
        }).done(function(data) {
          if (data.done === 'success')
            $('#' + imgIndex + ' .img').css('background-image', 'url(' + reader.result + ')');
        });
      });
      reader.readAsDataURL(file);
    }
  }
});

$('.make-default').on('click', function() {
  var imgIndex = $(this).data('index');

  $.get('/photo/set/' + imgIndex)
    .done(function(data) {
      if (data.done === 'success') {
        $('#profile-pic').css('background-image', 'url(' + data.photo + ')');
      }
    });
});

$('.delete-photo').on('click', function() {
  var imgIndex = $(this).data('index');

  $.get('/photo/delete/' + imgIndex)
    .done(function(data) {
      if (data.done === 'success') {
        $('#' + imgIndex + ' .img').css('background-image', 'url("http://fakeimg.pl/300x300/")');
      } else
        console.log(data.fail);
    });
});

$('.menu-profile li a').on('click', function() {
  if ($(this).html() === 'About') {
    $('.tab-menu').addClass('hidden');
    $('#tab-about').removeClass('hidden');
    $('.menu-profile li').removeClass('active');
    $(this).closest('li').addClass('active');
  } else if ($(this).html() === 'Photos') {
    $('.tab-menu').addClass('hidden');
    $('#tab-photos').removeClass('hidden');
    $('.menu-profile li').removeClass('active');
    $(this).closest('li').addClass('active');
  } else if ($(this).html() === 'Reported users') {
    $('.tab-menu').addClass('hidden');
    $('#tab-report').removeClass('hidden');
    $('.menu-profile li').removeClass('active');
    $(this).closest('li').addClass('active');
  }
});
