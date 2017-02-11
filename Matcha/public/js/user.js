$(document).ready(function() {
  if ($('#geo-map').data('latitude') && $('#geo-map').data('longitude')) {
    var url = GMaps.staticMapURL({
      size: [330, 280],
      lat: $('#geo-map').data('latitude'),
      lng: $('#geo-map').data('longitude')
    });
    $('#geo-map').attr('src', url).removeClass('hidden');
  }

  var userID = $('.actions > a').attr('href').split('/')[2];

  date = $.format.prettyDate(parseInt($('#connected').html()));
  if (typeof date === 'undefined')
    date = 'Not connected yet';
  $('#connected')
    .html('<span class="glyphicon glyphicon-option-horizontal" aria-hidden="true"></span> ' + date);

  if (parseInt($('#like .badge').html()) > 0) {
    $('#like .glyphicon')
      .removeClass('glyphicon-heart-empty')
      .addClass('glyphicon-heart');
  }

  $.get('/user/new/visit/' + userID).done(function(data) {
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
  } else if ($(this).html() === 'Options') {
    console.log('options tab');
  }
});

$('#like').on('click', function() {
  var userID = $('.actions > a').attr('href').split('/')[2];

  $.post('/like/plusone', {id : userID})
    .done(function(data) {
      if (data.done === 'success') {
        $('#like .badge').html(data.likes);
        if (data.likes > 0) {
          $('#like .glyphicon')
            .removeClass('glyphicon-heart-empty')
            .addClass('glyphicon-heart');
        } else {
          $('#like .glyphicon')
            .removeClass('glyphicon-heart')
            .addClass('glyphicon-heart-empty');
        }
      } else if (data.fail === 'You already like this user')
        console.log('You already like this user');
    });
});

$('#report').on('click', function() {
  var userID = $('.actions > a').attr('href').split('/')[2];

  $.post('/report/plusone', {id : userID})
    .done(function(data) {
      if (data.done === 'success')
        $('#report .badge').html(data.reports);
      else if (typeof data.fail !== 'undefined')
        console.log('Report / Unreport is not possible');
    });
});
