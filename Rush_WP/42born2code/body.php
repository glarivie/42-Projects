<?php
	$post_image_id = get_post_thumbnail_id($post_to_use->ID);
	if ($post_image_id)
	{
		$thumbnail = wp_get_attachment_image_src($post_image_id, 'full', false);
		if ($thumbnail)
		{
			(string)$thumbnail = $thumbnail[0];
			echo	'<style>
						.nothome {
							background-image: url('. $thumbnail .') !important;
							background-position: center;
						}
					</style>';
		}
	}
?>

<div class="<?php echo is_home() ? 'ban-home' : 'nothome'; ?>">
	<nav>
		<ul class="nav-logo left-align">
			<li class="my-logo">
				<a href="<?php echo get_option('home'); ?>">
					<i class="fa fa-apple"></i>
				</a>
			</li>
			<?php
				if (is_home() == FALSE)
				{
					echo '<li class="my-search">';
					include_once('searchform.php');
					echo '</li>';

					echo '<li id="menu-nav">Naviguer <i class="fa fa-caret-right"></i></li>';
					echo '<div id="wp-nav">';
						wp_nav_menu();
					echo '</div>';
				}
			?>
		</ul>
		<ul class="nav-right right-align">
			<?php
				if (is_user_logged_in())
					echo '<li class="nav-logout left-align"><a href="' . wp_logout_url(home_url()) . '">Déconnexion</a></li>';
				else
				{
					echo '<li class="nav-login"><a href="' . wp_login_url(home_url()) . '">Connexion</a></li>';
					echo '<li class="nav-register"><a href="' . wp_registration_url() . '">S\'enregistrer</a></li>';
				}
			?>
			<li class="publish">
				<a href="/wp-admin/post-new.php?post_type=room">
					<button type="button" class="btn btn-primary btn-sm">Publier une annonce</button>
				</a>
			</li>
		</ul>
	</nav>

<?php
	if (is_home())
	{ ?>
		<div class="message center-align">
			<h2>BIENVENUE À LA MAISON</h2>
			<h4>Louez des logements uniques auprès d'hôtes locaux dans 190+ pays.</h4>
			<a href="/mode-demploi/">
				<button type="button" class="btn btn-success btn-sm">MODE D'EMPLOI</button>
			</a>
		</div>

		<div class="find">
			<?php include_once('searchform.php'); ?>
		</div>
	<?php } ?>
</div>

<div id="container">
	<div class"pads clearfix">
