<div class="gallery">
	<?php
		if (isset($data)) {
			foreach ($data as $photo) { ?>
				<div class="gallery-single" id="<?php echo $photo['id']; ?>">
					<a href="single/<?php echo $photo['id']; ?>">
						<img src="<?php echo $photo['img']; ?>" alt="img-<?php echo $photo['id']; ?>" />
					</a>
					<ul>
						<?php if ($photo['likes'] == 0) { ?>
							<li class="likes-nb"><i class="fa fa-heart-o" aria-hidden="true"></i> <?php echo $photo['likes']; ?></li>
						<?php } else { ?>
							<li class="likes-nb"><i class="fa fa-heart" aria-hidden="true"></i> <?php echo $photo['likes']; ?></li>
						<?php } ?>

						<?php if ($photo['comments'] == 0) { ?>
							<li class="comments-nb"><i class="fa fa-comment-o" aria-hidden="true"></i> <?php echo $photo['comments']; ?></li>
						<?php } else { ?>
							<li class="comments-nb"><i class="fa fa-comment" aria-hidden="true"></i> <?php echo $photo['comments']; ?></li>
						<?php } ?>
					</ul>
				</div>
			<?php }
		} ?>
</div>

<script type="text/javascript" src="./public/js/gallery.js"></script>
