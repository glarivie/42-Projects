/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 13:40:09 by glarivie          #+#    #+#             */
/*   Updated: 2015/08/23 14:23:12 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define BUFFER 4096					//taille maxi en octets

int		main(void)
{
	int		test;					//nombre d'octets renvoye lors du "read"
	char	buf[BUFFER];			//tableau de char qui stocke le retour du read

	test = read(0, buf, BUFFER);	//read = nombre d'octets renvoye en int
	buf[test] = '\0';				

	int i = 0;
	int	j = 0;
	int	k = 0;
	char	retour[5][5];			//le tableau devra etre dynamique
	
	while (buf[i] != '\0')			//tant que buf[i] existe
	{
		if (buf[i] == '\n')			//si je tombe sur un retour a la ligne je change la colonne de retour (j + 1)
		{
			j++;
			k = 0;					//je me remet a l'index 0 sur les lignes de mon tableau de retour
		}
		else
		{
			retour[j][k] = buf[i];	//sinon je remplit mon tableau et j'incremente mes compteurs
			k++;
		}
		i++;
	}								//Qd je sors de la boucle mon tableau est remplit

	//j'analyse la premiere et la derniere ligne pour connaitre le numero de la colle
	
	i = 0;
	while(buf[i] != '\n')
		i++;						//i contient la valeur x de la longueur du rectange de la colle
									//j contient deja la hauteur y du rectangle de la colle
	
	//retour[0][0] contient l'angle en haut a gauche
	//retour[0][i] contient l'angle en haut a gauche
	
	//if...
	//write colle0X [i] [j]


	printf("%d\n", test);
	printf("%s", buf);
	return (0);
}
