<?php

add_action( 'init', 'register_my_menus' );
function register_my_menus() {
	register_nav_menus(
		array(
			'primary-menu' => __( 'Main Menu' ),
		));
}

add_theme_support( 'post-thumbnails' );
set_post_thumbnail_size( 200, 150, true ); // Normal post thumbnails

add_custom_background();

// Custom comment listing
function wpbx_comment($comment, $args, $depth) {
	$GLOBALS['comment'] = $comment;
	$commenter = get_comment_author_link();
	if ( ereg( '<a[^>]* class=[^>]+>', $commenter ) ) {
		$commenter = ereg_replace( '(<a[^>]* class=[\'"]?)', '\\1url ' , $commenter );
	} else {
		$commenter = ereg_replace( '(<a )/', '\\1class="url "' , $commenter );
	}
	$avatar_email = get_comment_author_email();
    $avatarURL = get_bloginfo('template_directory');
	$avatar = str_replace( "class='avatar", "class='avatar", get_avatar( $avatar_email, 40, $default = $avatarURL . '/images/gravatar-blank.jpg' ) );
?>
	<li <?php comment_class(); ?> id="comment-<?php comment_ID() ?>">
		<div id="div-comment-<?php comment_ID(); ?>">
			<div class="comment-author vcard">
				<?php echo $avatar . ' <span class="fn n">' . $commenter . '</span>'; ?>
			</div>
			<div class="comment-meta">
				<?php printf(__('%1$s <span class="meta-sep">|</span> <a href="%3$s" title="Permalink to this comment">Permalink</a>', 'wpbx'),
					get_comment_date('j M Y', '', '', false),
					get_comment_time(),
					'#comment-' . get_comment_ID() );
					edit_comment_link(__('Edit', 'wpbx'), ' <span class="meta-sep">|</span> <span class="edit-link">', '</span>');
				?>
				<span class="reply-link">
					<span class="meta-sep">|</span> <?php comment_reply_link(array_merge( $args, array('add_below' => 'div-comment', 'depth' => $depth, 'max_depth' => $args['max_depth']))) ?>
				</span>
			</div>

			<?php if ($comment->comment_approved == '0') _e("\t\t\t\t\t<span class='unapproved'>Your comment is awaiting moderation.</span>\n", 'wpbx') ?>

			<div class="comment-content"><?php comment_text() ?></div>
		</div>
<?php
}
// wpbx_comment()

// For category lists on category archives: Returns other categories except the current one (redundant)
function wpbx_cat_also_in($glue) {
	$current_cat = single_cat_title( '', false );
	$separator = "\n";
	$cats = explode( $separator, get_the_category_list($separator) );
	foreach ( $cats as $i => $str ) {
		if ( strstr( $str, ">$current_cat<" ) ) {
			unset($cats[$i]);
			break;
		}
	}
	if ( empty($cats) )
		return false;

	return trim(join( $glue, $cats ));
}

// For tag lists on tag archives: Returns other tags except the current one (redundant)
function wpbx_tag_also_in($glue) {
	$current_tag = single_tag_title( '', '',  false );
	$separator = "\n";
	$tags = explode( $separator, get_the_tag_list( "", "$separator", "" ) );
	foreach ( $tags as $i => $str ) {
		if ( strstr( $str, ">$current_tag<" ) ) {
			unset($tags[$i]);
			break;
		}
	}
	if ( empty($tags) )
		return false;

	return trim(join( $glue, $tags ));
}

// Generate custom excerpt length
function wpbx_excerpt_length($length) {
	return 75;
}
add_filter('excerpt_length', 'wpbx_excerpt_length');


// Widgets plugin: intializes the plugin after the widgets above have passed snuff
function wpbx_widgets_init() {
	if ( !function_exists('register_sidebars') ) {
		return;
	}
	// Formats the theme widgets, adding readability-improving whitespace
	$p = array(
		'before_widget'  =>   '<li id="%1$s" class="widget %2$s">',
		'after_widget'   =>   "</li>\n",
		'before_title'   =>   '<h3 class="widget-title">',
		'after_title'    =>   "</h3>\n"
	);
	register_sidebars( 1, $p );
} // ici on ferme la fonction function wpbx_widgets_init()


// Runs our code at the end to check that everything needed has loaded
add_action( 'init', 'wpbx_widgets_init' );

// Adds filters for the description/meta content
add_filter( 'archive_meta', 'wptexturize' );
add_filter( 'archive_meta', 'convert_smilies' );
add_filter( 'archive_meta', 'convert_chars' );
add_filter( 'archive_meta', 'wpautop' );

// Translate, if applicable
load_theme_textdomain('wpbx');


// Construct the WordPress header
remove_action('wp_head', 'start_post_rel_link');
remove_action('wp_head', 'index_rel_link');
remove_action('wp_head', 'adjacent_posts_rel_link');
remove_action('wp_head', 'next_post_rel_link');
remove_action('wp_head', 'previous_post_rel_link');


// MODIF glarivie@student.42.fr

function    footer_sidebar()
{
	$args = array(
		'class'         => 'sidebar-footer',
		'name'          => __('Footer', ''),
	);
	register_sidebar($args);
}

function    codex_room_init()
{
	$labels = array(
		'name'               => _x('Rooms', 'post type general name', ''),
		'singular_name'      => _x('Room', 'post type singular name', ''),
		'menu_name'          => _x('Rooms', 'admin menu', ''),
		'name_admin_bar'     => _x('Room', 'add new on admin bar', ''),
		'add_new'            => _x('Add New', 'room', ''),
		'add_new_item'       => __('Add New Room', ''),
		'new_item'           => __('New Room', ''),
		'edit_item'          => __('Edit Room', ''),
		'view_item'          => __('View Room', ''),
		'all_items'          => __('All Rooms', ''),
		'search_items'       => __('Search Rooms', ''),
		'parent_item_colon'  => __('Parent Rooms:', ''),
		'not_found'          => __('No rooms found.', ''),
		'not_found_in_trash' => __('No rooms found in Trash.', '')
	);

	$args = array(
		'labels'             => $labels,
		'description'        => __('Description.', ''),
		'public'             => true,
		'publicly_queryable' => true,
		'show_ui'            => true,
		'show_in_menu'       => true,
		'query_var'          => true,
		'rewrite'            => array('slug' => 'room'),
		'capability_type'    => 'post',
		'has_archive'        => true,
		'hierarchical'       => false,
		'menu_position'      => null,
		'supports'           => array('title', 'editor', 'excerpt', 'author', 'thumbnail', 'comments')
	);

	register_post_type('room', $args);
}

add_action('init', 'create_location_taxonomies', 0);

function	create_location_taxonomies()
{
	$labels = array(
		'name'                       => _x( 'Locations', 'taxonomy general name' ),
		'singular_name'              => _x( 'Location', 'taxonomy singular name' ),
		'search_items'               => __( 'Search Locations' ),
		'popular_items'              => __( 'Popular Locations' ),
		'all_items'                  => __( 'All Locations' ),
		'parent_item'                => null,
		'parent_item_colon'          => null,
		'edit_item'                  => __( 'Edit Location' ),
		'update_item'                => __( 'Update Location' ),
		'add_new_item'               => __( 'Add New Location' ),
		'new_item_name'              => __( 'New Location Name' ),
		'separate_items_with_commas' => __( 'Separate locations with commas' ),
		'add_or_remove_items'        => __( 'Add or remove locations' ),
		'choose_from_most_used'      => __( 'Choose from the most used locations' ),
		'not_found'                  => __( 'No locations found.' ),
		'menu_name'                  => __( 'Locations' ),
	);

	$args = array(
		'hierarchical'          => false,
		'labels'                => $labels,
		'show_ui'               => true,
		'show_admin_column'     => true,
		'update_count_callback' => '_update_post_term_count',
		'query_var'             => true,
		'rewrite'               => array( 'slug' => 'location' ),
	);

	register_taxonomy( 'location', 'room', $args );
}

function check($cible, $test)
{
	if (in_array($test, $cible))
		return ' checked="checked" ';
}

function	ft_init_meta()
{
	add_meta_box('prix', 'Prix par nuit', 'ft_price_meta', 'room', 'side', 'default');
	add_meta_box('type', 'Type de propriété', 'ft_type_meta', 'room', 'side', 'default');
	add_meta_box('equip', 'Équipements', 'ft_equip_meta', 'room', 'side', 'default');
}

function	ft_price_meta($post)
{
	$val = get_post_meta($post->ID, '_prix', true);
	echo '<label><input id="price_meta" type="number" name="mon_prix" value="'.$val.'" required /> €</label>';
}

function	ft_type_meta($post)
{

	$cond = get_post_meta($post->ID, '_type', false);

	echo '<label><input type="radio"' . check($cond, 4) . 'name="cond[]" value="4"/> Maison <br /></label>';
	echo '<label><input type="radio"' . check($cond, 5) . 'name="cond[]" value="5"/> Appartement <br /></label>';
}

function	ft_equip_meta($post)
{

	$cond = get_post_meta($post->ID, '_equip', false);

	echo '<label><input type="checkbox"' . check($cond, 1) . 'name="cond[]" value="1"/> Cuisine <br /></label>';
	echo '<label><input type="checkbox"' . check($cond, 2) . 'name="cond[]" value="2"/> Chauffage <br /></label>';
	echo '<label><input type="checkbox"' . check($cond, 3) . 'name="cond[]" value="3"/> Internet</label>';
}

function	save_metabox($post_id)
{
	if (isset($_POST['mon_prix']))
	{
		update_post_meta($post_id, '_prix', esc_html($_POST['mon_prix']));
	}
	if (isset($_POST['cond']))
	{
		delete_post_meta($post_id, '_equip');
		delete_post_meta($post_id, '_type');
		foreach ($_POST['cond'] as $elem)
		{
			add_post_meta($post_id, '_equip', intval($elem));
			add_post_meta($post_id, '_type', intval($elem));
		}
	}
}

add_action( 'widgets_init', 'footer_sidebar' );
add_action( 'init', 'codex_room_init' );
add_action('add_meta_boxes','ft_init_meta');
add_action('save_post','save_metabox');

add_action( 'show_user_profile', 'ft_add_extra' );
add_action( 'edit_user_profile', 'ft_add_extra' );

function	ft_add_extra( $user )
{
    ?>
        <h3>Informations complémentaires</h3>

        <table class="form-table">
            <tr>
                <th><label for="facebook_url">Facebook URL</label></th>
                <td><input type="url" name="facebook_url" value="<?php echo esc_attr(get_the_author_meta( 'facebook_url', $user->ID )); ?>" class="regular-text" /></td>
            </tr>

            <tr>
                <th><label for="mobile_phone">Téléphone Mobile</label></th>
                <td><input type="number" name="mobile_phone" value="<?php echo esc_attr(get_the_author_meta( 'mobile_phone', $user->ID )); ?>" class="regular-text" /></td>
            </tr>

            <tr>
                <th><label for="home_phone">Téléphone Fixe</label></th>
                <td><input type="number" name="home_phone" value="<?php echo esc_attr(get_the_author_meta( 'home_phone', $user->ID )); ?>" class="regular-text" /></td>
            </tr>
        </table>
    <?php
}

add_action( 'personal_options_update', 'ft_save_extra' );
add_action( 'edit_user_profile_update', 'ft_save_extra' );

function	ft_save_extra($user_id)
{
    update_user_meta( $user_id, 'facebook_url', sanitize_text_field( $_POST['facebook_url'] ) );
    update_user_meta( $user_id, 'mobile_phone', sanitize_text_field( $_POST['mobile_phone'] ) );
    update_user_meta( $user_id, 'home_phone', sanitize_text_field( $_POST['home_phone'] ) );
}
