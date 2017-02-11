<?php

$rootDIR = dirname(__DIR__, 1);
require_once($rootDIR . '/config/database.php');

$user = $bdd->query('CREATE TABLE IF NOT EXISTS camagru_users (user_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, user_login VARCHAR(255) NOT NULL, user_password VARCHAR(128) NOT NULL, user_email VARCHAR(255) NOT NULL, user_registered BOOLEAN NOT NULL DEFAULT 0, user_isadmin BOOLEAN NOT NULL DEFAULT 0)');

$img = $bdd->query('CREATE TABLE IF NOT EXISTS camagru_img (img_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, img_base64 MEDIUMTEXT CHARACTER SET ascii NOT NULL, author_id INT(6) UNSIGNED NOT NULL, img_likes INT(6) NOT NULL DEFAULT 0, img_date TIMESTAMP NOT NULL DEFAULT now(), img_comments_nb INT(6) NOT NULL DEFAULT 0)');

$comments = $bdd->query('CREATE TABLE IF NOT EXISTS camagru_comments (comment_id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY, img_id INT(6) UNSIGNED NOT NULL, author_id INT(6) UNSIGNED NOT NULL, author_email VARCHAR(255) NOT NULL, comment_date TIMESTAMP NOT NULL DEFAULT now(), comment_content TEXT NOT NULL, author_avatar VARCHAR(255))');

?>
