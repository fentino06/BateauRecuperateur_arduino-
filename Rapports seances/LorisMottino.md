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



# Rapport de séance du 17/01/2020

## Objectifs de la séance
* Réaliser des tests sur les moteurs afin de vérifier s'ils se comportent comme prévu, et corriger les éventuels problèmes.

## Tâches effectuées
* Nous avons effectué des tests sur les deux servomoteurs, qui se sont avérés concluants. En effet, selon la valeur entrée dans le moniteur série, les moteurs s'inclinaient soit vers la gauche, soit vers la droite, soit au milieu, soit en position de freinage.
* De plus, nous avons ramené un tube en PVC et des pièces de tuyauterie afin de créer un châssis temporaire pour effectuer des tests plus poussés sur la structure.

## Problèmes rencontrés
* Étant donné l'absence de moteurs brushless, nous n'avons pas pu tester le code destiné aux propulseurs.
* Lors de l'oral de cinq minutes, les servomoteurs n'ont pas du tout fonctionné, alors qu'ils marchaient très bien dix minutes avant.

## Solutions aux problèmes

* Concernant l'absence de moteurs brushless pour les tests, nous n'avons rien pu faire et avons donc consacré plus de temps aux tests des servomoteurs et à l'usinage d'un flotteur temporaire.



# Rapport de séance du 10/02/2020

## Objectifs de la séance
* Réussir à imprimer des flotteurs avec une imprimante personelle. 

## Tâches effectuées
* Dû au fait que les flotteurs étaient de dimensions trop grandes pour les imprimer j'ai dû redimensioner leurs tailles de 85 % de leurs tailles initiales, on a alors obtenu un cylindre de 25 cm de longueur et 8,5 cm de diamètre. 
* J'ai ensuite apposé un support pour le renfocement à la base du flotteur pour permetttre une impression stable avec le flotteur parallèle à la plaque d'impression. 

## Problèmes rencontrés 
* Malheureusement, après 7h d'impression, il y a eu un problème, la structure n'était plus du tout solide. Nous avons finalement dû tout annuler.

## Solution au problème
J'ai récupéré un tuyau de PVC de 80 mm, répondant à nos exigences, mais malheureusement nous n'avons pas trouvé de bouchon pour le rendre étanche (les tuyaux de 80 mm n'étant pas de taille standard). Nous allons donc utiliser les tuyaux de PVC de 100 mm, bien plus accessibles et modulables. 


# Rapport de séance du 02/03/2020

## Objectifs de la séance 
* Créer le chassîs de notre bateau à partir des tubes de PVC de 10 cm de diamètre 

## Tâches effectuées 
* Dans un premier temps il a fallu préparer le deuxième flotteur et vérifier son étanchéité. 
* J'ai ensuite découpé une plaque rigide de 40 cm par 25 cm qui se placera au dessus des deux flotteurs, afin de les fixer et de permettre de placer la carte Arduino ainsi que la batterie servant à l'alimenter. 
* J'ai ensuite percé deux trous dans chaque flotteur pour ensuite y visser la plaque en y ajoutant des écrous pour assurer la stabilité et des rondelles en caoutchouc afin de rendre l'ensemble étanche.

## Problèmes rencontrés 
* J'ai esssayé au départ de visser une plaque en bois sur les flotteurs mais sans succès, en effet les trous de la plaque n'étaient pas alignés avec les trous des flotteurs. De plus, le bois n'est pas forcément le meilleur matériau pour une utilisation marine, il faut le traiter et une plaque de plastique rigide semblait plus adaptée.
* Le foret dont j'avais besoin pour tarauder était celui de 4 mm, car je comptais utiliser des vis M4, mais je ne l'ai pas trouvé.

## Solutions aux problèmes 
* Pour la plaque, j'ai donc pris une plaque en plastique rigide à la place plus adaptée à la maquette. 
* Pour le perçage, j'ai utilisé un foret de 5 mm et des vis M5 avec des écrous adaptés afin de créer des boulons parfaits. 
