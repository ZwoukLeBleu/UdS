Pour compiler les fichiers de la probl�matique dans Geany:

  1. Ouvrir les fichiers de la probl�matique dans Geany via le menu "Fichier > Ouvrir...", puis en s�lectionnant les 3 fichiers du projet, soit :
     - gestion_images.c
     - bibliotheque_images.c
     - bibliotheque_image.h

  2. Ouvrir le menu d�roulant "Construire > D�finir les commandes de construction". Ceci ouvre un dialogue.

  3. Dans ce dialogue, changer l'instruction (Commande) associ�e � "Construire" ("Build", en anglais) pour la suivante:
       gcc -Wall -o gestion_images gestion_images.c bibliotheque_images.c

  4. Cliquer sur le bouton "Valider" (dans la bas du dialogue)

  5. Ensuite, pour proc�der � la construction du projet, utiliser l'une des 3 options suivantes :
     - Ouvrir le menu d�roulant "Construire > Build"
     - Ou appuyer sur F9
     - Ou dans la barre d'outils cliquer sur l'ic�ne "Build" (ressemblant � une brique rouge)
     
    *Le fichier ex�cutable qui est g�n�r� se nomme "gestion_images.exe" 

  6. Finalement, ex�cuter le projet comme suit :
     - Ouvrir le menu d�roulant "Construire > Execute
     - Ou appuyer sur F5
     - Ou dans la barre d'outils cliquer sur l'ic�ne "Execute" (comprenant des roues dentell�es)

    *La console s'ouvrira en affichant les "printf" du code.