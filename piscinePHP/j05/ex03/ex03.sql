USE db_glarivie;
INSERT INTO ft_table (login, groupe, date_de_creation) SELECT NULL, nom, 'other', DATE(date_naissance) FROM fiche_personne WHERE nom LIKE '%a' AND LENGTH(nom) < 9 ORDER BY nom LIMIT 10;
