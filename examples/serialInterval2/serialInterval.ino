/*
Description
=============
L'Arduino effectue a chaque 20 ms une mesure de la tension
de la broche analogique 0 et envoie la valeur sous forme de message ASCII.

Le message ASCII est compose des elements suivants:
1) "A0" suivi d'un espace
2) la valeur de la mesure
3) indicateur de fin de ligne (retour de chariot)

Circuit
=============
Broche analogique 0: un capteur analogique.

Logitheques
=============
Cet exemple utilise la logitheque Chrono

Version originale : Thomas Ouellet Fredericks, 4 novembre 2012
Seconde version :  Thomas Ouellet Fredericks, 23 septembre 2014
Derniere version :  Sinbrive, 26 Juillet 2018
*/

// INCLUDE CHRONO LIBRARY : http://github.com/SofaPirate/Chrono
#include <Chrono.h> 

const int FREQ=1000;

// Custom callback function
Chrono myChrono(FREQ, GetAnalogValue);

int PreviousV;

// callback function (called every xx ms in similar background)
void GetAnalogValue() {
    
      // Get analog value A0 
    int currentV = analogRead(0);
    
    // compare with the previous value
    if ( PreviousV != currentV ) {
      // Enregistrer la nouvelleMesure :
      PreviousV = currentV;
      
      // Envoyer la valeur du potentiometre.
      Serial.print("A0 "); // "A0" suivi d'un espace
      Serial.print(currentV); // la valeur de la mesure
      Serial.println(); // indicateur de fin de ligne  
    }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
 
    myChrono.update(1000);

}
