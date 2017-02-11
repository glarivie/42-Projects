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

var ageMin, ageMax, distMin, distMax, popMin, popMax;
var selectedInterests = [];

function getValues() {
  ageMin = a.getValue()[0];
  ageMax = a.getValue()[1];
  distMin = d.getValue()[0];
  distMax = d.getValue()[1];
  popMin = p.getValue()[0];
  popMax = p.getValue()[1];

  selectedInterests = [];
  $('.btn-filters').each(function() {
    if ($(this).hasClass('btn-warning'))
      selectedInterests.push($(this).children('.span-interest').html());
  });
}

function displayElements() {
  getValues();

  $('.profil').each(function() {
    var current = $(this),
      profilInterests = current.data('interests').split(',');
    profilInterests.pop();

    current.parent('.div-profil').addClass('hidden');

    $.each(profilInterests, function(index, value) {
      if (selectedInterests.indexOf(value) !== -1 && (current.data('age') >= ageMin && current.data('age') <= ageMax) && (current.data('distance') >= distMin && current.data('distance') <= distMax) && (current.data('popularity') >= popMin && current.data('popularity') <= popMax))
        current.parent('.div-profil').removeClass('hidden');
    });
  });
}

$('.btn-filters').on('click', function() {
  $(this).toggleClass('btn-warning');
  displayElements();
});

var a = $('#age')
  .slider()
  .on('slide change', function(e) {
    displayElements();
  }).data('slider');

var d = $('#distance')
  .slider()
  .on('slide change', function(e) {
    displayElements();
  }).data('slider');

var p = $('#popularity')
  .slider()
  .on('slide change', function(e) {
    displayElements();
  }).data('slider');
