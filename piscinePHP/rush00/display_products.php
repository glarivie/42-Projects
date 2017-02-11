<?php

function display_list_products($tab) {
	foreach ($tab as $product) {
		echo '<ul class="product">';
			echo '<li><img src="' . $product['imgURL'] . '" /></li>';
			echo '<li class="cat-name">' . $product['name'] . '</li>';
			echo '<li class="cat-brand">' . $product['brand'] . '</li>';

				echo '<ul>';
					foreach ($product['categories'] as $categorie) {
						echo '<li class="cat-list"><small><a href="?categorie=' . $categorie . '"><i class="fa fa-tag"></i> ' . ucfirst($categorie) . '</a>&nbsp;&nbsp; </small></li>';
					}
				echo '</ul>';
			echo '<li class="cat-price">' . floatval($product['price']) . ' <i class="fa fa-eur"></i></li>';
			echo '<li class="button-panier"><a href="panier.php?id=' . $product['id'] . '" type="button"><i class="fa fa-cart-arrow-down"></i> Ajouter au panier</a></li>';
		echo '</ul>';
	}
}

?>
