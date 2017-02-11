USE db_glarivie;
SELECT ABS(DATEDIFF(MIN(date), MAX(date))) AS 'uptime' FROM historique_membre;
