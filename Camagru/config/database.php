<?php

/*
$DB_DSN = 'mysql:dbname=camagru;host=localhost;charset=utf8';
$DB_USER = 'root';
$DB_PASSWORD = '1234';*/
$bdd = NULL;

$DB_DSN = 'mysql:dbname=sql8116326;host=sql8.freemysqlhosting.net;charset=utf8';
$DB_USER = 'sql8116326';
$DB_PASSWORD = 'j2msHbvqWi';

try {
	$bdd = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
	echo 'Connection failed: ' . $e->getMessage();
}
/*
$test = $bdd->query('SHOW TABLES');

while ($data = $test->fetch()) {
	print_r($data);
}*/

?>
