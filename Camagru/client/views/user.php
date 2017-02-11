<div class="gallery">
	<?php
		if (isset($data)) {
			foreach ($data as $photo) { ?>
				<div class="gallery-single" id="<?php echo $photo['id']; ?>">
					<a href="single/<?php echo $photo['id']; ?>">
						<img src="<?php echo $photo['img']; ?>" alt="img-<?php echo $photo['id']; ?>" />
					</a>
					<i class="fa fa-trash-o" aria-hidden="true"></i>
				</div>
			<?php }
		} ?>
</div>

<script type="text/javascript" src="./public/js/user.js"></script>
