# Serveur NTP
NTP est un protocole de temp réseau.
Il permet de synchroniser l'horloge locale d'ordinateurs sur une référence d'heure.
Ce rapport explique ce qu'est NTP ainsi que son implémentation sur un environement client/serveur sous OpenSuse.
Le Serveur fournira une heure de référence au client.

## Auteur
Rémy De Poorter
52063
52063@etu.he2b.be

## Générer le rapport avec pdflatex
cd DE_POORTER_REMY_NTP_RAPPORT/DE_POORTER_REMY_NTP_RAPPORT_TEX
pdflatex DE_POORTER_REMY_NTP_RAPPORT.tex

## Compilations des codes
Il y a 3 codes a compiler
- Le premier est a executer sur le serveur et s'occupe de le configurer.
- Le second est a executer sur le client et permet synchroniser l'heure du client avec le serveur.
- Le dernier permet d'executer une tache automatiquement avec cron.
	Le programme écrira "coucou" dans le fichier "remy.txt"

Pour compiler les codes il suffit de se déplacer aux endroits voulu (serv, client, cron) :
cd DE_POORTER_REMY_NTP_AUTOMATISATION/serv
Ensuite d'exécuter le makefile avec :
make

## Faire fonctionner l'automatisation
- Pour le client :
cd DE_POORTER_REMY_NTP_AUTOMATISATION/client
bash clientAuto

- Pour le serveur :
cd DE_POORTER_REMY_NTP_AUTOMATISATION/serv
bash servAuto

- Pour l'automatisation avec cron peut se faire sur le serveur ou le client
cd DE_POORTER_REMY_NTP_AUTOMATISATION/cron
bash cronAuto