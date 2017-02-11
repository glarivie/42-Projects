(function () {
	$('.poster').on({
		'mouseover' : function() {
			$(this).children('.resolutions').removeClass('hidden');
		},
		'mouseout' : function() {
			$(this).children('.resolutions').addClass('hidden');
		}
	});
})();
