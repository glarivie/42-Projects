USE db_glarivie;
SELECT titre AS 'Titre', resum AS 'Resume', annee_prod FROM film, genre WHERE film.id_genre = genre.id_genre AND nom = 'erotic' ORDER BY annee_prod DESC;