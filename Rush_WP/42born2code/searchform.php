<?php
	if (is_home())
	{ ?>
		<form class="form-inline" method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
			<div class="form-group">
				<input type="text" class="form-control" value="<?php _e("Faites ici votre recherche"); ?>" name="s" id="searchbox" onfocus="if (this.value == '<?php _e("Faites ici votre recherche"); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e("Faites ici votre recherche"); ?>';}" />
			</div>
			<button type="submit" class="btn btn-danger">Rechercher</button>
		</form>
	<?php }
	else
	{ ?>
		<form class="form-inline" method="get" action="<?php echo $_SERVER['PHP_SELF']; ?>">
			<div class="form-group">
				<div class="input-group">
					<div class="input-group-addon"><i class="fa fa-search"></i></div>
					<input type="text" class="form-control input-sm" id="inputsm" value="<?php _e("Faites ici votre recherche"); ?>" name="s" id="searchbox" onfocus="if (this.value == '<?php _e("Faites ici votre recherche"); ?>') {this.value = '';}" onblur="if (this.value == '') {this.value = '<?php _e("Faites ici votre recherche"); ?>';}" />
				</div>
			</div>
		</form>
	<?php } ?>
