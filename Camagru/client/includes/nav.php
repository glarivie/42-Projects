<nav>
	<ul class="inline-block">
		<li class="logo text-left"><h1>CAMA<span class="bold gray">GRU</span></h1></li>
		<li id="shoot" class="menu text-right <?php echo $data['app'] ? 'active' : ''; ?>"><a href="<?php echo getRootURI() . 'app'; ?>">Shoot me</a></li>
		<li id="gallery" class="menu text-right <?php echo $data['gallery'] ? 'active' : ''; ?>"><a href="<?php echo getRootURI() . 'gallery'; ?>">Gallery</a></li>
		<li id="user" class="menu text-right <?php echo $data['user'] ? 'active' : ''; ?>"><a href="<?php echo getRootURI() . 'user'; ?>"><i class="fa fa-user" aria-hidden="true"></i></a></li>
		<li id="poweroff" class="menu text-right <?php echo $data['poweroff'] ? 'active' : ''; ?>"><a href="<?php echo getRootURI() . 'server/'; ?>logout.php"><i class="fa fa-power-off" aria-hidden="true"></i></a></li>
	</ul>
</nav>
