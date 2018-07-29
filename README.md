# CHRONO

Forked from http://github.com/SofaPirate/Chrono  (by Sofian Audry and Thomas Ouellet Fredericks)

Chrono library for Arduino or Wiring
Chronometer/stopwatch library that counts the time passed since started.

Added feature : callback

Files changed : 

- Chrono.h
- Chrono.cpp

Example added

- serialInterval2
```
Chrono::Chrono(void (*callBack_)(void))  
{
    _getTime = millis;
    restart();
    _callBack=callBack_;
}

void Chrono::update(chrono_t timeout) {
   if (hasPassed(timeout, true)) {
            _callBack();
           // restart();
  }
}
```

Example
```
#include <Chrono.h>

const int FREQ=1000;

// Custom callback function
Chrono myChrono(GetAnalogValue);

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
```
## Repository

* Broswe the source code here: http://github.com/SofaPirate/Chrono
* Download the latest version here : https://github.com/sinbrive/Chrono/archive/master.zip



