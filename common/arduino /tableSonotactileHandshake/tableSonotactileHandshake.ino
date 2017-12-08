/*
Ce programme consiste simplement à mesurer les entrées analogiques en haute résolution, 
et à transmettre le résultat via une communication série.
*/
//déclaration des variables
//stockage des numéros de Pin où seront branchés les capteurs
//les capteurs sont branchés dans cet ordre : 
// - boutons FSR de gauche à droite sur entrées 1 à 4
// - glissière gauche sur entrée 5
// - glissière droite sur entrée 6

// adapter cette identifiant pour chaque pupitre
// on utilise les bytes inutilisés par les données pour éviter toute confusion
// 101 = pupitre 1, 102 = pupitre 2, etc...
int deviceUID = 103;

int Input_0 = 0;
int Input_1 = 1;
int Input_2 = 2;
int Input_3 = 3;
int Input_4 = 4;
int Input_5 = 5;

//conteneur pour stocker la mesure
int FSR_0 = 0;
int FSR_1 = 0;
int FSR_2 = 0;
int FSR_3 = 0;
int FSR_4 = 0;
int FSR_5 = 0;

// délai entre deux mesures
int periodeDeMesure = 1;
// output mode (0=sendID, 1=sendData)
int outMode= 0;

void setup(){ // Initialisation du programme
    // établir la connection série à 9600 baud
    Serial.begin(9600);
    // définition des entrées
    pinMode(Input_0, INPUT);
    pinMode(Input_1, INPUT);
    pinMode(Input_2, INPUT);
    pinMode(Input_3, INPUT);
    pinMode(Input_4, INPUT);
    pinMode(Input_5, INPUT);
    outMode = 0;
    
     while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
    }
    
}

void loop() { //boucle principale
  if (Serial.available() > 0) {
    // get incoming byte:
    outMode = Serial.read();
  }

  if (outMode == 0){
    Serial.write(deviceUID);   // send the device ID
    delay(300);
  }

  if (outMode == 1){
    FSR_0 = analogRead(Input_0); // Lit la tension du pin DeMesure et stocke le résultat dans la variable 
    delay(periodeDeMesure); //attendre jusqu'à la prochaine mesure
    FSR_1 = analogRead(Input_1); 
    delay(periodeDeMesure); 
    FSR_2 = analogRead(Input_2); 
    delay(periodeDeMesure);
    FSR_3 = analogRead(Input_3); 
    delay(periodeDeMesure);
    FSR_4 = analogRead(Input_4);
    delay(periodeDeMesure);
    FSR_5 = analogRead(Input_5); 
    delay(periodeDeMesure); 
    
    // notifies batch start
    Serial.write(255); // values beyond 0-31 can be used as separator
    delay(periodeDeMesure);
    
    Serial.write(FSR_0 & 31); // low 5 bits of the 10 bits value    
    delay(periodeDeMesure); 
    Serial.write((FSR_0 & 992) >> 5); // high 5 bits of the 10 bits value    
    delay(periodeDeMesure); 
    Serial.write(FSR_1 & 31); 
    delay(periodeDeMesure); 
    Serial.write((FSR_1 & 992) >> 5); 
    delay(periodeDeMesure); 
    Serial.write(FSR_2 & 31);     
    delay(periodeDeMesure);
    Serial.write((FSR_2 & 992) >> 5); 
    delay(periodeDeMesure); 
    Serial.write(FSR_3 & 31);     
    delay(periodeDeMesure); 
    Serial.write((FSR_3 & 992) >> 5);     
    delay(periodeDeMesure);
    Serial.write(FSR_4 & 31);     
    delay(periodeDeMesure); 
    Serial.write((FSR_4 & 992) >> 5);  
    delay(periodeDeMesure); 
    Serial.write(FSR_5 & 31);   
    delay(periodeDeMesure); 
    Serial.write((FSR_5 & 992) >> 5);
    delay(periodeDeMesure);
  }
}

