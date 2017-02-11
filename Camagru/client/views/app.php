<div class="main app">
	<div class="top-app">
		<div id="top-left-app" class="webcam">
			<img id="moustacheAbsolute" src="./public/img/moustache.png"/>
			<img id="lunettesAbsolute" src="./public/img/lunettes.png"/>
			<img id="hatAbsolute" src="./public/img/hat.png"/>
			<!-- if camera available -->
			<video id="camera" width="100%" autoplay></video>
			<!-- else -->
			<img class="hidden" id="top-left-img" src="" alt="top-left-img" />
		</div>
		<div id="top-right-app" class="preview">
			<!-- hidden -->
			<canvas class="hidden" id="canvas" width="" height=""></canvas>
			<!-- else if uploaded image -->
			<img class="hidden" id="return-img" src="" alt="return-img" />
		</div>
	</div>
	<div class="bottom-app">
		<div id="bottom-left-app" class="tabs">
			<ul id="tab-header">
				<li id="tab-obj">Objects</li>
				<li id="tab-filters">Filters</li>
				<li id="tab-upload" class="hidden">Image Upload</li>
			</ul>
			<div id="objects">
				<input id="moustache" type="checkbox" name="moustache" value="Moustache">
				<img src="./public/img/moustache.png" width="100" />
				<div class="position">
					<input id="moustache-x" type="range" value="50" max="100" min="0" step="1">
					<input id="moustache-y" type="range" value="50" max="100" min="0" step="1">
				</div>
				<input id="lunettes" type="checkbox" name="lunettes" value="Lunettes">
				<img src="./public/img/lunettes.png" width="110" />
				<div class="position">
					<input id="lunettes-x" type="range" value="50" max="100" min="0" step="1">
					<input id="lunettes-y" type="range" value="50" max="100" min="0" step="1">
				</div>
				<input id="hat" type="checkbox" name="hat" value="hat">
				<img src="./public/img/hat.png" width="80" />
				<div class="position">
					<input id="hat-x" type="range" value="50" max="100" min="0" step="1">
					<input id="hat-y" type="range" value="50" max="100" min="0" step="1">
				</div>
			</div>
			<div id="filters">
				<button class="" id="Normal" type="button" name="Normal">Normal</button>
				<button class="_1977" id="1977" type="button" name="1977">1977</button>
				<button class="aden" id="Aden" type="button" name="Aden">Aden</button>
				<button class="brooklyn" id="Brooklyn" type="button" name="Brooklyn">Brooklyn</button>
				<button class="clarendon" id="Clarendon" type="button" name="Clarendon">Clarendon</button>
				<button class="earlybird" id="Earlybird" type="button" name="Earlybird">Earlybird</button>
				<button class="gingham" id="Gingham" type="button" name="Gingham">Gingham</button>
				<button class="Hudson" id="Hudson" type="button" name="Hudson">Hudson</button>
				<button class="inkwell" id="Inkwell" type="button" name="Inkwell">Inkwell</button>
				<button class="lark" id="Lark" type="button" name="Lark">Lark</button>
				<button class="lofi" id="Lo-Fi" type="button" name="Lo-Fi">Lo-Fi</button>
				<button class="mayfair" id="Mayfair" type="button" name="Mayfair">Mayfair</button>
				<button class="moon" id="Moon" type="button" name="Moon">Moon</button>
				<button class="nashville" id="Nashville" type="button" name="Nashville">Nashville</button>
				<button class="perpetua" id="Perpetua" type="button" name="Perpetua">Perpetua</button>
				<button class="reyes" id="Reyes" type="button" name="Reyes">Reyes</button>
				<button class="rise" id="Rise" type="button" name="Rise">Rise</button>
				<button class="slumber" id="Slumber" type="button" name="Slumber">Slumber</button>
				<button class="toaster" id="Toaster" type="button" name="Toaster">Toaster</button>
				<button class="walden" id="Walden" type="button" name="Walden">Walden</button>
				<button class="willow" id="Willow" type="button" name="Willow">Willow</button>
				<button class="xpro2" id="X-pro-II" type="button" name="X-pro-II">X-pro II</button>
				<button class="sepia" id="Sepia" type="button" name="Sepia">Sepia</button>
				<button class="blur" id="Blur" type="button" name="Blur">Blur</button>
			</div>
			<div id="nocamera">
				<input type="file" name="fileToUpload" id="fileToUpload">
			</div>
			<button type="button" class="btn disabled" id="snap" disabled>Take snapshot</button>
		</div>
		<div id="bottom-right-app" class="last-taken">
			<?php
				if (isset($data)) {
					for ($index = 0; $index < 4; $index++) {
						if ($data[$index]) { ?>

						<div class="gallery-single-small" id="<?php echo $data[$index]['id']; ?>">
							<a href="single/<?php echo $data[$index]['id']; ?>">
								<img src="<?php echo $data[$index]['img']; ?>" alt="img-<?php echo $data[$index]['id']; ?>" />
							</a>
						</div>
					<?php }
					}
				} ?>
		</div>
	</div>
</div>

<script type="text/javascript" src="./public/js/tabs.js"></script>
<script type="text/javascript" src="./public/js/app.js"></script>
<script type="text/javascript" src="./public/js/filter.js"></script>
