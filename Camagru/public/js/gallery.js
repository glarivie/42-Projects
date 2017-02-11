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
		var heart = single.querySelector('ul .likes-nb i'),
			likesNb = parseInt(heart.nextSibling.data),
			imgID = single.id;
		if (likesNb === 0) {
			heart.addEventListener('mouseover', function(e) {
				e.target.classList.remove('fa-heart-o');
				e.target.classList.add('fa-heart');
			}, false);
			heart.addEventListener('mouseout', function(e) {
				e.target.classList.remove('fa-heart');
				e.target.classList.add('fa-heart-o');
			}, false);
		}
		heart.addEventListener('click', function(e) {
			if (likesNb === 0) {
				e.target.classList.remove('fa-heart-o');
				e.target.classList.add('fa-heart');
			}
			var xhr = getXMLHttpRequest();
			xhr.open('POST', rootURI + '/server/addNewLike.php', true);
			xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
			xhr.send(imgID);
			xhr.onreadystatechange = function() {
				if (xhr.readyState === 4 && xhr.status === 200) {
					likesNb = parseInt(xhr.responseText);
					e.target.nextSibling.data = ' ' + likesNb;
				}
			};
		}, false);
	});
})();
