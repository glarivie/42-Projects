(function() {
	function setSize(div, w, h) {
		div.setAttribute('width', w);
		div.setAttribute('height', h);
		div.style.width = w + 'px';
		div.style.height = h + 'px';
	}

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

	window.addEventListener("DOMContentLoaded", function() {
		var video = document.getElementById('camera'),
			canvas = document.getElementById('canvas'),
			bouton = document.getElementById('snap'),
			canvasWidth = video.offsetWidth,
			canvasHeight = Math.floor(canvasWidth / 1.33),
			moustacheAbsolute = document.getElementById('moustacheAbsolute'),
			lunettesAbsolute = document.getElementById('lunettesAbsolute'),
			hatAbsolute = document.getElementById('hatAbsolute'),
			topLeftIMG = document.getElementById('top-left-img'),
			topLeftApp = document.getElementById('top-left-app'),
			topRightApp = document.getElementById('top-right-app'),
			returnIMG = document.getElementById('return-img'),
			noCamera = document.getElementById('nocamera'),
			allowedTypes = ['png', 'jpg', 'jpeg', 'gif'],
			fileToUpload = document.getElementById('fileToUpload'),
			menuUpload = document.getElementById('tab-upload'),
			ctx = canvas.getContext('2d'),
			videoObj = { 'video' : true },
			moustacheCheckbox = document.getElementById('moustache'),
			moustacheOnVideo = document.getElementById('moustacheAbsolute'),
			moustacheX = document.getElementById('moustache-x'),
			moustacheY = document.getElementById('moustache-y'),
			moustacheInvert = document.getElementById('moustacheInvert'),
			lunettesCheckbox = document.getElementById('lunettes'),
			lunettesOnVideo = document.getElementById('lunettesAbsolute'),
			lunettesX = document.getElementById('lunettes-x'),
			lunettesY = document.getElementById('lunettes-y'),
			lunettesInvert = document.getElementById('lunettesInvert'),
			hatCheckbox = document.getElementById('hat'),
			hatOnVideo = document.getElementById('hatAbsolute'),
			hatX = document.getElementById('hat-x'),
			hatY = document.getElementById('hat-y'),
			hatInvert = document.getElementById('hatInvert'),
			rootURI = '/' + location.pathname.split('/')[1],
			noWebcam = false,
			myData = {
				'data' : [{
					'img' : null,
					'size' : {
						'width' : canvasWidth,
						'height' : canvasHeight
					},
					'moustache' : 0,
					'lunettes' : 0,
					'hat' : 0
				}]
			};

		function setObject(obj, w, h) {
			if (obj === 'moustache') {
				x = moustacheX;
				y = moustacheY;
				onVideo = moustacheOnVideo;
			} else if (obj === 'lunettes') {
				x = lunettesX;
				y = lunettesY;
				onVideo = lunettesOnVideo;
			} else if (obj === 'hat') {
				x = hatX;
				y = hatY;
				onVideo = hatOnVideo;
			}
			x.setAttribute('max', canvasWidth - w);
			x.setAttribute('value', canvasWidth / 2 - w);
			y.setAttribute('max', canvasHeight - h);
			y.setAttribute('value', canvasHeight / 2 - h);
			onVideo.style.top = canvasHeight / 2 - h + 'px';
			onVideo.style.left = canvasWidth / 2 - w + 'px';
		}

		topLeftApp.style.height = canvasHeight + 'px';
		topRightApp.style.height = canvasHeight + 'px';
		setSize(canvas, canvasWidth, canvasHeight);
		setSize(moustacheAbsolute, (canvasWidth / 3.9), ((canvasWidth / 3.9) / 3.19));
		setSize(lunettesAbsolute, (canvasWidth / 2.6), ((canvasWidth / 2.6) / 2.2));
		setSize(hatAbsolute, (canvasWidth / 2.8), ((canvasWidth / 2.8) / 1.52));
		setObject('moustache', (canvasWidth / 3.9), ((canvasWidth / 3.9) / 3.19));
		setObject('lunettes', (canvasWidth / 2.6), ((canvasWidth / 2.6) / 2.2));
		setObject('hat', (canvasWidth / 2.8), ((canvasWidth / 2.8) / 1.52));

		if (!window.URL)
			window.URL = window.URL || window.webkitURL || window.msURL || window.oURL;
		if (!navigator.getUserMedia)
			navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia;
		if (navigator.getUserMedia) {
			navigator.getUserMedia(videoObj, function(stream) {
				video.classList.remove('hidden');
				video.src = window.URL.createObjectURL(stream);
				video.play();
			}, isNoWebcam);
		}

		moustacheCheckbox.addEventListener('change', function(e) {
			if (e.target.checked) {
				moustacheOnVideo.style.display = 'block';
				bouton.disabled = false;
				bouton.classList.remove('disabled');
			} else {
				moustacheOnVideo.style.display = 'none';
				if (lunettesCheckbox.checked === false && hatCheckbox.checked === false) {
					bouton.disabled = true;
					bouton.classList.add('disabled');
				}
			}
		}, false);

		moustacheX.addEventListener('input', function(e) {
			moustacheOnVideo.style.left = moustacheX.value + 'px';
		}, false);

		moustacheY.addEventListener('input', function(e) {
			moustacheOnVideo.style.top = moustacheY.value + 'px';
		}, false);

		lunettesCheckbox.addEventListener('change', function(e) {
			if (e.target.checked) {
				lunettesOnVideo.style.display = 'block';
				bouton.disabled = false;
				bouton.classList.remove('disabled');
			} else {
				lunettesOnVideo.style.display = 'none';
				if (moustacheCheckbox.checked === false && hatCheckbox.checked === false) {
					bouton.disabled = true;
					bouton.classList.add('disabled');
				}
			}
		}, false);

		lunettesX.addEventListener('input', function(e) {
			lunettesOnVideo.style.left = lunettesX.value + 'px';
		}, false);

		lunettesY.addEventListener('input', function(e) {
			lunettesOnVideo.style.top = lunettesY.value + 'px';
		}, false);

		hatCheckbox.addEventListener('change', function(e) {
			if (e.target.checked) {
				hatOnVideo.style.display = 'block';
				bouton.disabled = false;
				bouton.classList.remove('disabled');
			} else {
				hatOnVideo.style.display = 'none';
				if (moustacheCheckbox.checked === false && lunettesCheckbox.checked === false) {
					bouton.disabled = true;
					bouton.classList.add('disabled');
				}
			}
		}, false);

		hatX.addEventListener('input', function(e) {
			hatOnVideo.style.left = hatX.value + 'px';
		}, false);

		hatY.addEventListener('input', function(e) {
			hatOnVideo.style.top = hatY.value + 'px';
		}, false);

		function isNoWebcam() {
			noWebcam = true;
			menuUpload.classList.remove('hidden');
			camera.classList.add('hidden');
			noCamera.addEventListener('change', function(e) {
				var imgType = (e.target.files[0].name.split('.')).pop().toLowerCase();
				if (allowedTypes.indexOf(imgType) != -1) {
					var file = e.target.files[0];
					var reader = new FileReader();
					reader.addEventListener('load', function(e) {
						myData.data[0].img = reader.result;
						topLeftIMG.classList.remove('hidden');
						topLeftIMG.src = myData.data[0].img;
					}, false);
					reader.readAsDataURL(file);
				}
			}, false);
		}

		bouton.addEventListener('click', function(e) {
			e.preventDefault();
			if (noWebcam === false) {
				ctx.drawImage(video, 0, 0, canvasWidth, canvasHeight);
				myData.data[0].img = canvas.toDataURL('image/jpeg', 1.0);
			} else {
				myData.data[0].size.width = topLeftIMG.width;
				myData.data[0].size.height = topLeftIMG.height;
			}

			if (moustacheCheckbox.checked) {
				myData.data[0].moustache = {
					'x' : moustacheX.value,
					'y' : moustacheY.value,
					'width' : (canvasWidth / 3.9),
					'height' : (canvasWidth / 3.9) / 3.19
				};
			}
			if (lunettesCheckbox.checked) {
				myData.data[0].lunettes = {
					'x' : lunettesX.value,
					'y' : lunettesY.value,
					'width' : (canvasWidth / 2.6),
					'height' : (canvasWidth / 2.6) / 2.2
				};
			}
			if (hatCheckbox.checked) {
				myData.data[0].hat = {
					'x' : hatX.value,
					'y' : hatY.value,
					'width' : (canvasWidth / 2.8),
					'height' : (canvasWidth / 2.8) / 1.52
				};
			}

			var xhr = getXMLHttpRequest();
			xhr.open('POST', rootURI + '/server/saveImage.php', true);
			xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
			xhr.send(JSON.stringify(myData));
			xhr.onreadystatechange = function() {
				if (xhr.readyState === 4 && xhr.status === 200) {
					//console.log(xhr.responseText);
					returnIMG.src = xhr.responseText;
					returnIMG.style.display = 'block';
					//location.reload();
				}

			};
		}, false);
	}, false);
})();
