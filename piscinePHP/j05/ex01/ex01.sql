USE db_glarivie;
DROP TABLE IF EXISTS ft_table;
CREATE TABLE ft_table (
	id INT(6) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
	login VARCHAR(8) NOT NULL DEFAULT 'toto',
	groupe ENUM ('staff', 'student', 'other') NOT NULL,
	date_de_creation DATE NOT NULL DEFAULT '1970-01-01'
);
