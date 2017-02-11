<!DOCTYPE html>
<html <?php language_attributes() ?>>
<head>
	<!-- Bootstrap + Font Awesome -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" integrity="sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7" crossorigin="anonymous">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">

	<meta http-equiv="content-type" content="<?php bloginfo('html_type') ?>" charset="<?php bloginfo('charset') ?>" />

	<title><?php wp_title( '-', true, 'right' ); echo wp_specialchars( get_bloginfo('name'), 1 ) ?></title>
<!--	<link rel="stylesheet" href="<?php bloginfo('stylesheet_directory'); ?>/style.css" type="text/css" media="screen" />
-->	<link rel="stylesheet" href="<?php bloginfo('stylesheet_directory'); ?>/custom.css" type"text/css" />

	<!--[if lte IE 6]>
		<script type="text/javascript" src="<?php bloginfo('template_url'); ?>/js/supersleight-min.js"></script>
	<![endif]-->

	<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/jquery.js'); ?>
	<?php wp_enqueue_script('superfish', get_bloginfo('template_directory').'/js/superfish.js', array('jquery'), '1.7'); ?>
	<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/nav.js'); ?>
	<?php if (trim(get_option('ft_header_code')) <> "") { echo stripslashes(get_option('ft_header_code')); } ?>
	<?php if (is_singular()) wp_enqueue_script('comment-reply'); ?>

	<?php wp_head(); ?> <!-- #NE PAS SUPPRIMER cf. codex wp_head() -->
</head>

<body>

<?php include_once('body.php'); ?>
