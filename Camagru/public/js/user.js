(function() {
	var imageSingle = document.querySelectorAll('.gallery-single'),
		rootURI = '/' + location.pathname.split('/')[1];

	function getXMLHttpRequest() {
		var xhr = null;

		if (window.XMLHttpRequest || window.ActiveXObject) {
			if (window.ActiveXObject) {
				try { xhr = new ActiveXObject("Msxml2.XMLHTTP"); }
				catch(e) { xhr = new ActiveXObject("Microsoft.XMLHTTP"); }
			} else
				xhr = new XMLHttpRequest();
		} else
			return (null);
		return (xhr);
	}

	[].forEach.call(imageSingle, function(single) {
		var trash = single.querySelector('.gallery-single i'),
			imgID = single.id;

		trash.addEventListener('mouseover', function(e) {
			e.target.classList.remove('fa-trash-o');
			e.target.classList.add('fa-trash');
		}, false);
		trash.addEventListener('mouseout', function(e) {
			e.target.classList.remove('fa-trash');
			e.target.classList.add('fa-trash-o');
		}, false);
		trash.addEventListener('click', function(e) {
			var xhr = getXMLHttpRequest();
			xhr.open('POST', rootURI + '/server/removeImage.php', true);
			xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
			xhr.send(imgID);
			xhr.onreadystatechange = function() {
				if (xhr.readyState === 4 && xhr.status === 200) {
					location.reload();
				}
			};
		}, false);
	});
})();
