<?php get_header() ?>

		<div id="content">

<?php the_post() ?>

<div class="page-auteur">
	<?php
		$default = "https://cdn.intra.42.fr/userprofil/glarivie.jpg";
		$data = get_userdata(get_the_author_meta('ID'));
		$date = $data->user_registered;

		echo get_avatar(get_the_author_meta('ID'), 96, $default);
		echo '<h5><i class="fa fa-user"></i> '. get_the_author_meta('user_login') .'</h5>';
		echo '<h5><i class="fa fa-facebook-official"></i> <a href="'. get_the_author_meta('facebook_url') .'">Facebook</a></h5>';
		echo '<h5><i class="fa fa-phone"></i> '. get_the_author_meta('mobile_phone') .'</h5>';
		echo '<h5><i class="fa fa-home"></i> '. get_the_author_meta('home_phone') .'</h5>';
		echo '<h5><i class="fa fa-envelope"></i></i> <a href="mailto:'. get_the_author_meta('user_email') .'"><em>'. get_the_author_meta('user_email') .'</em></a></h5>';
		echo '<h5><i class="fa fa-calendar"></i> '. date("d/m/Y", strtotime($date)) .'</h5>';
	?>
</div>

	<div class="auteur-rooms">
		<h3>Mes locations :</h3>

	<?php
		//rewind_posts();
		$args = array(
			    'post_type' => 'room' ,
			    'author' => get_queried_object_id(),
			    'showposts' => 10
			);
		$custom_posts = new WP_Query($args);

		if ($custom_posts->have_posts())
		{
			while ($custom_posts->have_posts())
			{
				$custom_posts->the_post();
				echo '<a href ="'. get_permalink() .'">'. get_the_post_thumbnail() .'</a>';
				echo '<div class="infos-au">';
				echo '<h4><a href ="'. get_permalink() .'">'. get_the_title() .'</a></h4>';
				echo '<small>Posté le ' .get_the_date(). '</small>';
				echo '<p>'. get_the_excerpt() .'</p>';
				echo '</div>';
			}
		}

	?>

	</div>
</div> <!-- #container -->
<?php get_footer(); ?>
