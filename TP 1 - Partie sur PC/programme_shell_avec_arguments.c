/* librairie standard ... */
#include <stdlib.h>
/* pour getopt */
#include <unistd.h>
/* déclaration des types de base */
#include <sys/types.h>
/* constantes relatives aux domaines, types et protocoles */
#include <sys/socket.h>
/* constantes et structures propres au domaine UNIX */
#include <sys/un.h>
/* constantes et structures propres au domaine INTERNET */
#include <netinet/in.h>
/* structures retournées par les fonctions de gestion de la base de
données du réseau */
#include <netdb.h>
/* pour les entrées/sorties */
#include <stdio.h>
/* pour la gestion des erreurs */
#include <errno.h>

#include <string.h>

void main (int argc, char **argv)
{
	int c;
	extern char *optarg;
	extern int optind;

	int timer1_ms = 0; 
	int timer2_ms = 0; 
	int timer3_ms = 0;
	int nb_message = -1; /* Nb de messages à envoyer ou à recevoir, par défaut : 10 en émission, infini en réception */
	int en_boucle = 0;
	int stop = 0;
	char message[100] = "";

	while ((c = getopt(argc, argv, "t:n:bhm")) != -1) {
		switch (c) {
            case 'b':
				en_boucle = 1;
				if (nb_message != -1) {
					printf("Mauvais usage. Option '-h' pour l'aide.\n");
					exit(1) ;
				}
                break;

            case 'n':
                nb_message = atoi(optarg);
				if (en_boucle != 0) {
					printf("Mauvais usage. Option '-h' pour l'aide.\n");
					exit(1) ;
				}
                break;

            case 't':
				timer1_ms = atoi(strtok(optarg, " "));
				timer2_ms = atoi(strtok(NULL, " "));
				timer3_ms = atoi(strtok(NULL, " "));

				printf("Temps définis : court = %dms, moyen = %dms, long = %dms.\n", timer1_ms, timer2_ms, timer3_ms);

                break;

            case 'h':
            default:
                printf("Utilisation du programme :\n");
                printf("-h : affiche l'aide\n");
                printf("-s : stop le programme\n");
                printf("-m \"xxx\" : message à envoyer\n");
                printf("-t \"# # #\" : configure les timers avec les temps indiqués\n");
                printf("-b : message affiché en morse en boucle\n");
                printf("-n # : message affiché en morse n-fois\n");

				exit(1) ;
                break;
		}
	} 

	if ((strcmp(message, "") == 0) && (stop == 0)) {
		printf("Précisez un message '-m' ou envoyez la commande stop '-s'. Option '-h' pour l'aide.\n");
		exit(0);
	}


	if (nb_message != -1) {
		printf("Message envoyé %d fois.\n", nb_message);
	} else {
		if (en_boucle == 1) {
			printf("Message envoyé en boucle.\n");
		}
		printf("Message envoyé 1 fois.\n");
	}
}

