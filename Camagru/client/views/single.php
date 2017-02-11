<div class="gallery">
	<div class="image" id="<?php echo $data['id']; ?>">
		<img src="<?php echo $data['img']; ?>" alt="img-<?php echo $data['id']; ?>" />
		<h5>&copy; <?php echo $data['login']; ?></h5>
		<ul>
			<?php if ($data['likes'] == 0) { ?>
				<li class="likes-nb"><i class="fa fa-heart-o" aria-hidden="true"></i> <?php echo $data['likes']; ?></li>
			<?php } else { ?>
				<li class="likes-nb"><i class="fa fa-heart" aria-hidden="true"></i> <?php echo $data['likes']; ?></li>
			<?php } ?>

			<?php if ($data['comments'] == 0) { ?>
				<li class="comments-nb"><i class="fa fa-comment-o" aria-hidden="true"></i> <?php echo $data['nb']; ?></li>
			<?php } else { ?>
				<li class="comments-nb"><i class="fa fa-comment" aria-hidden="true"></i> <?php echo $data['nb']; ?></li>
			<?php } ?>
		</ul>
	</div>
	<div class="commentaires">
		<?php if (isset($data['comments'])) {
			foreach ($data['comments'] as $comment) {
				$date = explode('-', (explode(' ', $comment['comment_date'])[0]));
				$comment['comment_date'] = $date[2] . '/' . $date[1] . '/' . $date[0];
		?>
			<ul>
				<li class="author"><i class="fa fa-user" aria-hidden="true"></i> <a href="mailto:<?php echo $comment['mail']; ?>"><?php echo $comment['author_login']; ?></a></li>
				<li class="date"><i class="fa fa-calendar" aria-hidden="true"></i> <?php echo $comment['comment_date']; ?></li>
				<li class="content"><?php echo $comment['content']; ?></li>
			</ul>
		<?php }
			} ?>
		<form method="POST" action="../server/addNewComment.php">
			<textarea rows="3" name="comment" value="" placeholder="Comments..."></textarea>
			<input class="hidden" type="number" name="img_id" value="<?php echo $data['id']; ?>">
			<button type="submit" name="ok">Submit</button>
		</form>
	</div>
</div>

<script type="text/javascript" src="../public/js/single.js"></script>
