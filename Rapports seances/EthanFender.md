# Rapport de séance du  13/12/2019

## Objectifs de la séance 
* Construire le code des servomoteurs pour l'inclinaison des deux gouvernails et donc la direction que prendra le bateau.

## Tâches effectuées 
* Les codes ont été fait, j'ai aussi incorporé le code bluetooth en essayant de garder un code aussi générique ue possible pour pouvoi en tout temps modifier les angles minimums et maximums d'inclinaisons et les I/O des servomoteurs. Puis j'ai testé mon code avec un servomoteur.
Lorsque le bateau avancera les safrans recevront un siggnal de 1,5 ms ( position 90°) en alignement avec le bateau. Cette valeur sera modifiée selon la direction voulue.

## Problèmes possibles
Les problèmatiques à laquelle on peut s'attendre sont : 
    * Une marge d'erreur entre les deux servomoteurs
    * Une marge d'erreur lors du placement des safrans et leurs inclinaisons 
    
# Rapport de séance du 10/01/2020

## Objectifs de la séance 
* Créer une communication RF 433 MHz pour diriger le bateau, en effet une communication de ce type est bien plus efficace que le bluetooth qui ne porte que de quelques mètres 

## Tâches effectuées 
* J'ai codé et branché la communication RF 
* J'ai peaufiné les servomoteurs en leurs ajoutant une fonction de freinage 
* J'ai reconfiguré les servomoteurs aveec la bibliothèque servomoteur 2 pour éviter les interférences  avec la communication rf. 

## Problèmes rencontrés 
* Il a fallut comprendre que la bibliothèque ServoTimer2 n'utilise que des angles en microsecondes avec servo.write() pour communiquer avec les servos.
* J'ai eu quelques problèmes de branchement avec la plaque d'essai dont certains ports semblent avoir grillé. 


# Rapport de séance du 10/02/2020

## Objectif de la séance
*Réussir à faire fonctionner le module 433 Mhz de communication RF.

## Tâches éffectuées 

*Dans un premier temps pour améliorer la communication entre les modules, j'ai soudé deux antennes aux modules d'une longueur de 17cm.

*Ensuite il a fallu s'isoler pour éviter tout parasitage de la fréquence 433 Mhz, à partir de la j'ai démarré le code.


## Code de l'émetteur

#include <VirtualWire_Config.h>
#include <VirtualWire.h>

const int TX = 10;

void setup() {
  Serial.begin(9600);
  vw_set_tx_pin(TX);
  vw_setup(2000);
}

void loop() {
  while (Serial.available()) {
    byte plain[2];
    byte message = Serial.read();
    plain[0] = message;
    vw_send(plain, 2);
    vw_wait_tx();
    Serial.print("Caractère envoyé : ");
    Serial.println(char(message));
  }
}

D'abord on fait appel à la bibliothèque VirtualWire , on déclare le port TX qui est relié à l'arduino.

- void setup 

On initialise le port de l'émetteur et la vitesse de transmission des octets qui est ici de 2000 octets par secondes.

- void loop 

On fixe une boucle while qui attend que l'utilisateur rentre une valeur dans le moniteur série. 
On créé un tableau d'octet de 2 octet nommé plain qui sera composé du message et du caractère signifiant la fin du message ( il ne sera pas pris en compte à la réception).
Dans ce tableau d'octet on introduit le caractère tapé par l'utilisateur sous forme d'octet.
Puis on envoie le tableau d'octet au recepteur. 

## Code du récepteur 

#include <VirtualWire_Config.h>
#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(11);
  vw_setup(2000);
  vw_rx_start();
}

void loop() {
  byte message[1];
  byte taille_message = 1;
 
  vw_wait_rx();

  if (vw_get_message(message, &taille_message)) {
    Serial.println((char) message[0]);
  }
}

- void setup 

On initialise le port de l'émetteur, et la vitesse de transmission des octets puis on signale au récepteur qu'il doit démarrer à recevoir les messages avec vw_rx_start().

- void loop

On déclare  qu'on va recevoir un message de la taille d'un octet ( un caractère) et que sa taille est de 1 octet. 
On attend de recevoir un signal avec vw_wait_rx().
Puis on utilise un énoncé itératif pour vérifier si le message est corrompu ou pas avec vw_get_message(message, &taille_message)).
En effet si taille_ message est plus grand que le message alors cela voudrait dire que le message a été parasité durant sa transmission. 
Si il n'est pas corrompu on affiche le caractère reçu. 

## Problème rencontré 

Je recevais toujours le même caractère dû au fait que je n'ai pas émis un tableau d'octets assez grand comportant le caractère de fin de message. 

## Conclusion 

Le fonctionnement reste analogique peu importe la taille du message, ce code est un prémice au joystick qui controlera par la suite le bateau.


# Rapport de séance du 02/03/2020

## Objectifs de la séance 
Réussir à échanger des informations venant d’un joystick en utilisant une communication RF 433MHz permettant de contrôler le bateau. 

## Tâches effectuées
J’ai dû coder tout d’abord le joystick et réussir à envoyer des informations sous forme d’octets. Pour cela, j'ai respectivement connecté les broches X et Y du joystick aux entrées analogiques 0 et 1 de l'Arduino. Les valeurs récupérées sont comprises entre 0 et 1023. Par défaut, lorsque le joystick est au repos, les valeurs x et y valent 511. En effet, lorsque le joystick est incliné à gauche, la valeur X vaut 0, et à droite elle vaut 1023. Et lorsque le joystick est incliné en haut, la valeur Y vaut 0, et en bas elle vaut 1023. Ensuite, les données sont envoyées sous la forme d'un tableau d'octets à l'aide de l'émetteur 433MHz. Pour ce faire, j'ai transformé ces valeurs X et Y afin xxxxyyyy en utilisant le code : String(X) + String(Y) et en rajoutant un nombre nécessaire de 0 avant chaque nombre pour qu'ils aient une taille de 4 caractères. Exemple : 7 donnera 0007, 128 donnera 0128 etc... Les deux valeurs collées donneront donc une chaîne de 8 caractères correspondant aux valeurs X et Y collées.
Puis j'ai converti cette chaîne en tableau d'octets à l'aide de la méthode getBytes() du type String.
Une fois les données transmises, je convertis le tableau d'octets reçu par le récepteur 433MHz en String à l'aide du code : String((char*)tableau_d_octets)
J'utilise la méthode substring() du type String sur cette chaîne de caractère décodée afin d'extraire les deux valeurs X et Y, que je convertis en type entier et que je stocke dans deux variables à traiter plus tard pour l'activation des moteurs.

