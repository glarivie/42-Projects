<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier contient les réglages de configuration suivants : réglages MySQL,
 * préfixe de table, clefs secrètes, langue utilisée, et ABSPATH.
 * Vous pouvez en savoir plus à leur sujet en allant sur
 * {@link http://codex.wordpress.org/fr:Modifier_wp-config.php Modifier
 * wp-config.php}. C'est votre hébergeur qui doit vous donner vos
 * codes MySQL.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d'installation. Vous n'avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en "wp-config.php" et remplir les
 * valeurs.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define('DB_NAME', 'db_database');

/** Utilisateur de la base de données MySQL. */
define('DB_USER', 'Admin');

/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', '123456');

/** Adresse de l'hébergement MySQL. */
define('DB_HOST', 'localhost');

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define('DB_CHARSET', 'utf8mb4');

/** Type de collation de la base de données.
  * N'y touchez que si vous savez ce que vous faites.
  */
define('DB_COLLATE', '');

/**#@+
 * Clefs uniques d'authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clefs secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n'importe quel moment, afin d'invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         ';48pC4v)p=g@P/W|MW9N$=(6tBsSS?ey6o{d|Y-xHNj*+Jzg%w/CCXzm$6(o2/A9');
define('SECURE_AUTH_KEY',  'e;|3Cn?IT)dmmqgk/,[%wjPOQjLm,1]=TY>+<3!#*A<rW0G$B)|erAAR2TE=e48w');
define('LOGGED_IN_KEY',    '>BM{S$B,X_oHmC*afJWguZF]p*GrQkwT+`N.~w`-/!uhWobujv-I3:a[4;*]>>W%');
define('NONCE_KEY',        'Z>fMvCnxJajn(<hOCbTyr U?$hVFQ :h2=|f^|:Bcj-8PV{GG(M|.)RAaVoiYP#I');
define('AUTH_SALT',        '^Y.L*Xf?(-hyeriC$=,q/x!+D;e79}~,!GIiz3%g])!^,-{^CR-euCLve17[/T03');
define('SECURE_AUTH_SALT', 'tsL/[gyRJy-:qG*ud.R5;zpXMxk;wF|<|+E/SodFZFP;R|x(_>X9>;!eC[97aH!>');
define('LOGGED_IN_SALT',   'y}S!Yt+`kP>>B@Oi}?&lQfrpSP*+z$pGZfKMbQf$T[|$xj+cfz{iJpBV6iICxfO^');
define('NONCE_SALT',       'EgY.#ujk}Rp0h$;[tBASBc@y#!n[7DYcq|XZmR&6UUinp&e4nE}mN^_aa2[]:+|[');
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N'utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés!
 */
$table_prefix  = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l'affichage des
 * notifications d'erreurs pendant vos essais.
 * Il est fortemment recommandé que les développeurs d'extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 */
define('WP_DEBUG', false);

/* C'est tout, ne touchez pas à ce qui suit ! Bon blogging ! */

/** Chemin absolu vers le dossier de WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once(ABSPATH . 'wp-settings.php');