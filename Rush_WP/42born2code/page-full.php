<?php
/*
Template Name: Full Width
*/
?>
<?php get_header() ?>
<div id="wrapper">
	<div id="container">
		<div id="contentfull">
			<?php the_post() ?>
			<div class="entry-wide">
				<h2 class="page-title"><?php the_title() ?></h2>
				<div class="entry-content">
				<?php the_content() ?>
				</div>
			</div><!-- entry -->

		</div><!-- #contentfull -->
	</div><!-- #container -->
</div><!-- #wrapper -->
<?php get_footer() ?>
