<?php
	$projectName = "ft_minishop";
	$pageTitle = $projectName . " - Administration";
	include_once('get_json.php');

	function display_list_admin($tab) {
		foreach ($tab as $product) {
			echo '<ul class="admin-product">';
				echo '<li><span>iD: </span>' . $product['id'] . '</li>';
				echo '<li><span>Name: </span>' . $product['name'] . '</li>';
				echo '<li><span>Brand: </span>' . $product['brand'] . '</li>';
						foreach ($product['categories'] as $categorie) {
							echo '<li>' . ucfirst($categorie) . '&nbsp;&nbsp;</li>';
						}
				echo '<li><span>Price: </span>' . $product['price'] . ' €</li>';
				echo '<li><a href="?action=del?id=' . $product['id'] . '"><i class="fa fa-trash"></i></a></li>';
			echo '</ul>';
		}
	}

	function del_product($tab, $id) {
		$list['products'] = [];
		foreach ($tab as $product) {
			if ($product['id'] !== $id) {
				$list['products'] = $product;
			}
		}
		print_r($list);
		//$ret = file_put_contents('data/products.json', json_encode($list, true));
		//echo $ret;
	}

 ?>

<!DOCTYPE html>
<html lang="fr">
	<?php include_once('views/head.php'); ?>
	<body>
		<?php include_once('views/nav.php'); ?>

		<?php include_once('views/admin-nav.php'); ?>

		<?php

			if ($_GET['admin'] === 'products') {
				$json = get_json();
				display_list_admin($json['products']);
			}
			if ($_GET['action'] === 'del') {
				echo "<h1>delete tentative</h1>";
				$json = get_json();
				del_product($json['products'], $_GET['id']);
			}

		?>

		<?php include_once('views/footer.html'); ?>
	</body>
</html>
