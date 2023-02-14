# TP-morse
Répertoire des sujets du TP sur le morse

## Introduction
L’objectif de ce TP est de se familiariser avec les outils de développement en C, en regardant l’application d’un code à travers plusieurs types de matériel.
-	Type 1 : Ordinateurs – sans contrainte d’espace, en général plus orienté graphique et réseau. 
-	Type 2 : microcontrôleurs – peu de place, associé à des périphériques externes. L’opération logique y règne en maître. 

Il vous est proposé de réaliser deux programmes communiquant entre eux afin de créer une interaction entre ces deux types de machines. Votre ordinateur sera relié à une carte de prototypage par une liaison UART. Il devra envoyer un message par ce biais, qui sera récupéré par la carte de prototypage et transcrira ce message en morse à l’aide d’une LED. 

TP 1 – (1 jour) : Vous vous concentrerez sur la partie Ordinateur. Il vous sera demandé de créer un code C pouvant être appelé en ligne de commande en passant une phrase en paramètre suivi de plusieurs arguments.

TP 2 – (3 jours) : Vous vous concentrerez sur la partie Microcontrôleur. Il vous sera demandé de créer un programme prenant une entrée via l’UART et de transcrire le message en MORSE à l’aide d’une LED. 

## Description du TP 1
L’exercice sera découpé en deux parties :

### 1ere partie : 
Mise en forme du code afin de permettre l’entrée d’une phrase et de paramètres dans la commande.
Les paramètres qui doivent être gérés étant :
-	t : les différents timers permettant la gestion des temps du protocole MORSE 
-	b : envoie le message en boucle 
-	n : permet à l’utilisateur de choisir un nombre de répétition du message
-	s : permet l’arrêt immédiat de l’envoi de messages

### 2eme partie : 
Gestion de la communication en UART et mise en place du protocole défini.
Il vous sera demandé de configurer un des ports séries de l’ordinateur et de créer le protocole à envoyer.
Le protocole est défini dans le word (.doc).

## Spécifications 

### Spécification 1 
Faites-en sorte que l’utilisateur ne puisse pas utiliser les options « n » et « b » en même temps.

### Spécification 2
Si le message est vide et que l’option « s » n’est pas activé, affichez un message d’erreur à l’utilisateur.
