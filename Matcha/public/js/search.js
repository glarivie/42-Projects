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

var s = $('#sort')
	.slider()
	.on('slide change', function() {
		if (s.getValue() === 1) {
			$('.profiles-around').addClass('hidden');
			$('.sortbyage').removeClass('hidden');
		} else if (s.getValue() === 2) {
			$('.profiles-around').addClass('hidden');
			$('.sortbydistance').removeClass('hidden');
		} else if (s.getValue() === 3) {
			$('.profiles-around').addClass('hidden');
			$('.sortbypopularity').removeClass('hidden');
		}
	}).data('slider');

var ageMin, ageMax, distMin, distMax, popMin, popMax, sex, ori;
var selectedInterests = [];

function getValues() {
	ageMin = a.getValue()[0];
	ageMax = a.getValue()[1];
	distMin = d.getValue()[0];
	distMax = d.getValue()[1];
	popMin = p.getValue()[0];
	popMax = p.getValue()[1];

	if (e.getValue() === 1) { sex = 'Male'; }
	else if (e.getValue() === 2) { sex = 'Female'; }
	else if (e.getValue() === 3) { sex = 'Other'; }

	if (o.getValue() === 1) { ori = 'Straight'; }
	else if (o.getValue() === 2) { ori = 'Bisexual'; }
	else if (o.getValue() === 3) { ori = 'Gay'; }

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
			if (selectedInterests.indexOf(value) !== -1 && current.data('sex') === sex && current.data('orientation') === ori && (current.data('age') >= ageMin && current.data('age') <= ageMax) && (current.data('distance') >= distMin && current.data('distance') <= distMax) && (current.data('popularity') >= popMin && current.data('popularity') <= popMax))
				current.parent('.div-profil').removeClass('hidden');
		});
	});
}

$('.btn-filters').on('click', function() {
	$(this).toggleClass('btn-warning');
	displayElements();
});

var e = $('#sex')
	.slider()
	.on('slide change', function() {
		displayElements();
	}).data('slider');

var o = $('#orientation')
	.slider()
	.on('slide change', function() {
		displayElements();
	}).data('slider');

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
