(function() {
	var menu = document.getElementById('tab-headers'),
		menuObj = document.getElementById('tab-obj'),
		menuFilters = document.getElementById('tab-filters'),
		menuUpload = document.getElementById('tab-upload'),
		tabObj = document.getElementById('objects'),
		tabFilters = document.getElementById('filters'),
		tabUpload = document.getElementById('nocamera');

	// Basic onload configuration
	tabFilters.style.display = 'none';
	tabUpload.style.display = 'none';
	menuObj.style.borderTop = '1px solid #FFF';
	menuObj.style.borderLeft = '1px solid #FFF';
	menuObj.style.borderRight = '1px solid #FFF';
	menuObj.style.marginBottom = '-1px';

	function hideAll() {
		tabObj.style.display = 'none';
		tabFilters.style.display = 'none';
		tabUpload.style.display = 'none';
	}

	menuFilters.addEventListener('click', function(e) {
		hideAll();
		tabFilters.style.display = 'block';
	}, false);

	menuUpload.addEventListener('click', function(e) {
		hideAll();
		tabUpload.style.display = 'block';
	}, false);

	menuObj.addEventListener('click', function(e) {
		hideAll();
		tabObj.style.display = 'block';
	}, false);
})();
