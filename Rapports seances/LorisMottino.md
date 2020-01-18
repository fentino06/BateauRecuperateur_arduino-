# Rapport de séance du 13/12/2019

## Objectifs de la séance
* Réaliser des modèles 3D du dispositif en vue de les imprimer plus tard grâce à une imprimante 3D.

## Tâches effectuées
* Les modèles 3D des flotteurs ont été réalisés durant cette séance, mais ont dû être repensé plusieurs fois afin de s'adapter aux contraintes physiques du dispositif. De plus, nous avons réfléchi à plusieurs designs pour le produit final, impliquant des modélisations diverses menant à un ensemble plus adapté aux conditions réelles de fonctionnement.

## Problèmes rencontrés
* La machine virtuelle sur laquelle était installé le programme de conception assistée par ordinateur (AutoDesk Inventor Professional 2020) n'a pas démarré, j'ai passé une partie conséquente de la séance à réparer le problème, sans succès. J'ai donc réinstallé le tout durant le week-end.

## Solutions aux problèmes
* Afin de pouvoir travailler sur le projet durant cette séance, j'ai utilisé l'ordinateur de mon binôme afin de modéliser les parties décrites plus haut.



# Rapport de séance du 07/01/2020

## Objectifs de la séance
* Création du châssis d'après les modèles 3D réalisés à la séance précédente. Ces modèles sont au nombre de deux, un pour le flotteur et un autre pour le capot du flotteur. Ils sont destinés à être imprimés en 3D au FabLab.

## Tâches effectuées
* Ne pouvant pas imprimer ces pièces en raison de leur taille (30cm) et du temps d'impression, j'ai aidé mon binôme dans la programmation du code destiné à contrôler les propulseurs. J'ai également revu et amélioré le code destiné au pilotage des servomoteurs pour les pâles directionnelles.
* J'ai cherché un autre moyen de fabriquer les flotteurs et les capots, par exemple en les usinant avec des tubes en PVC, mais cela ne donnerait pas le rendu attendu et sera effectué pour des tests primaires.

## Problèmes rencontrés
* Le principal problème rencontré ici était le fait que je ne pouvais pas réaliser l'objectif de la séance, à savoir imprimer le châssis en 3D.

## Solutions aux problèmes
* Pour pallier au problème de l'impression, j'ai aidé mon binôme afin d'avancer dans le projet sans être stoppé par cette contrainte.



# Rapport de séance du 10/01/2020

## Objectifs de la séance
* Réaliser des tests d'étanchéité sur les différentes parties du châssis, et voir comment placer les composants (moteurs, pâles, Arduino...) de manière optimale dans la structure.

## Tâches effectuées
* N'ayant toujours pas de châssis car impossible à imprimer, nous avons à la place ajouté des fonctions au code des servomoteurs, mais également des propulseurs, et avons essayé d'intégrer une communication RF avec des modules 433MHz, puis Bluetooth.

## Problèmes rencontrés
* Le principal problème rencontré ici était l'impossibilité de réaliser les tests sur le châssis, car ce dernier n'existe pas.
* De plus, les modules 433MHz captent trop d'interférences, les rendant inutilisables pour une utilisation normale.
* Les méthodes des classes Servo et ServoTimer2 sont difficiles à cerner, certaines prennent des angles en microsecondes et d'autres en angles, menant à des confusions lorsque nous avons voulu coder les servomoteurs avec ServoTimer2 (car nous avions utilisé Servo jusque là).

## Solutions aux problèmes
* Pour le problème principal qui était l'absence de châssis, nous y avons pallié en s'occupant d'autres aspects de notre projet tels que la communication RF et une meilleure maîtrise des moteurs.
* Concernant celui les modules 433MHz, nous avons préféré utiliser un module Bluetooth HC-05.
* Enfin, nous avons réussi à bien cerner la classe ServoTimer2 afin de l'implémenter dans le code des servomoteurs, et nous avons trouvé des valeurs d'angles en microsecondes pour les trois positions des servomoteurs (gauche, milieu et droit).
