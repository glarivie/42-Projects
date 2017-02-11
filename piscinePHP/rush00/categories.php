<?php
	$projectName = 'ft_minishop';
	$pageTitle = $projectName . ' - Products';

	include_once('get_json.php');

	function get_categories_list($json) {
		$list = [];
		foreach ($json['products'] as $product) {
			foreach ($product['categories'] as $categorie) {
				if (!in_array($categorie, $list)) {
					$list[] = $categorie;
				}
			}
		}
		return($list);
	}

	function products_by_categories($json, $categorie) {
		$list = [];
		foreach ($json['products'] as $product) {
			if (in_array($categorie, $product['categories'])) {
				$list[] = $product;
			}
		}
		return ($list);
	}

	include_once('display_products.php');
?>

<!DOCTYPE html>
<html lang="fr">
	<?php include_once('views/head.php'); ?>
	<body>
		<?php include_once('views/nav.php'); ?>

				<?php
					$json = get_json();

					if ($json) {
						$list = get_categories_list($json);
						echo '<ul class="categories">';
							echo '<li>CATÉGORIES :</li>';
							foreach ($list as $categorie) {
								echo '<li><a href="?categorie=' . $categorie . '"><i class="fa fa-tag"></i> ' . ucfirst($categorie) . '</a></li>';
							}
						echo '</ul>';

						if ($_GET) {
							display_list_products(products_by_categories($json, $_GET['categorie']));
						} else {
							display_list_products($json['products']);
						}
					}
				?>

		<?php include_once('views/footer.html'); ?>
	</body>
</html>
