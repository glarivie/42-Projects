<?php get_header(); ?>
<?php if (have_posts()) : ?>
	<?php while (have_posts()) : the_post(); ?>
		<div class="room">

			<a href="<?php echo get_author_posts_url(get_the_author_meta('ID')); ?>" class="auteur inline-room">
				<?php
					$default = "https://cdn.intra.42.fr/userprofil/glarivie.jpg";
					echo get_avatar(get_the_author_meta('ID'), 96, $default);
					echo '<h4>'. get_the_author_meta('display_name') .'</h4>';
				?>
			</a>

			<div class="description inline-room">
				<h2 class="title">
					<?php the_title(); ?>
				</h2>
				<div class="content">
					<h5>DESCRIPTION :</h5>
					<?php
						the_content();
						comments_template();
					?>
				</div>
			</div>

			<div class="infos inline-room">
				<?php
					$prix = get_post_meta(get_the_ID(),'_prix', true);
					$type = get_post_meta(get_the_ID(),'_type', true);
					$equi =  get_post_meta(get_the_ID(),'_equip',false);

					echo '<h1>' . $prix . ' € <small>/nuits</small></h1>';
					if ($type == 5)
						echo '<h4 class="types">Type :<br/><br/><i class="fa fa-building-o"></i> Appartement</h4>';
					else
						echo '<h4 class="types">Type :<br/><br/><i class="fa fa-home"></i> Maison</h4>';
					echo '<h4 class ="options">Options :</h4>';
					if ($equi[1])
						echo '<h4 class="tab"><i class="fa fa-check-square-o"></i> Cuisine</h4>';
					if ($equi[2])
						echo '<h4 class="tab"><i class="fa fa-check-square-o"></i> Chauffage</h4>';
					if ($equi[3])
						echo '<h4 class="tab"><i class="fa fa-check-square-o"></i> Internet</h4>';
				?>
			</div>
		</div>
	<?php endwhile; ?>
<?php endif; ?>
<?php get_footer(); ?>
