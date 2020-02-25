# Rapport de séance du Lundi 10/02/2020

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
    byte plain[1];
    byte message = Serial.read();
    plain[0] = message;
    vw_send(plain, 1);
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
On créé un tableau d'octet de 1 octet nommé plain.
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
    Serial.println((char*) message);
  }
}

- void setup 

On initialise le port de l'émetteur, et la vitesse de transmission des octets puis on signale au récepteur qu'il doit démarrer à recevoir les messages avec vw_rx_start().

- void loop

