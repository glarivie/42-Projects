<?php

function imagecopymerge_alpha($dst_im, $src_im, $dst_x, $dst_y, $src_x, $src_y, $src_w, $src_h, $pct) {
	$cut = imagecreatetruecolor($src_w, $src_h);
	imagecopy($cut, $dst_im, 0, 0, $dst_x, $dst_y, $src_w, $src_h);
	imagecopy($cut, $src_im, 0, 0, $src_x, $src_y, $src_w, $src_h);
	return (imagecopymerge($dst_im, $cut, $dst_x, $dst_y, 0, 0, $src_w, $src_h, $pct));
}

function miniaturePNG($src, $min_w, $min_h) {
	$miniature = imagecreatetruecolor($min_w, $min_h);
	$black = imagecolorallocate($miniature, 0, 0, 0);
	imagealphablending($miniature, false);
	imagesavealpha($miniature, true);

	imagecopyresampled($miniature, $src, 0, 0, 0, 0, $min_w, $min_h, imagesx($src), imagesy($src));
	
	imagecolortransparent($miniature, $black);
	return ($miniature);
}

//imagecopymerge_alpha($webcam, $miniHat, intval($json->data[0]->hat->x), intval($json->data[0]->hat->y), 0, 0, intval($json->data[0]->size->width), intval($json->data[0]->size->height), 100));

function imagesMerge($out, $png, $coord_x, $coord_y, $ori_x, $ori_y, $out_w, $out_h, $transparency) {
	$newMiniature = imagecreatetruecolor($out_w, $out_h);
	$black = imagecolorallocate($newMiniature, 0, 0, 0);
	imagecolortransparent($newMiniature, $black);
	imagecopymerge($newMiniature, $png, 0, 0, 0, 0, $out_w, $out_h, $transparency);
	imagecopymerge($out, $newMiniature, $coord_x, $coord_y, $ori_x, $ori_y, $out_w, $out_h, $transparency);
}

?>
