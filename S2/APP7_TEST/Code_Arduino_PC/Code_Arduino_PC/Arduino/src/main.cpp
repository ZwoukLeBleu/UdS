/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
*/

/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <TimerOne.h>

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 115200        // Frequence de transmission serielle
#define DATA_ARRAY_SIZE 100 // Dimension du tableau de données 

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

int ledState = 0;
int potValue[DATA_ARRAY_SIZE];
unsigned long timeValue[DATA_ARRAY_SIZE];
int arrayIndex = 0;

int pinLED = 7;
int pinPOT = A0;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();
void printData();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, ledState);
  Timer1.initialize(10000); //Initialize timer with 1 millisecond period
  Timer1.attachInterrupt(printData);
}

/* Boucle principale (infinie) */
void loop() {

  if(shouldRead_){
    readMsg();
    sendMsg();
  }
  //Serial.println(potValue);          // debug
  delay(5);
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void sendMsg() {
  const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_ARRAY_SIZE(2*DATA_ARRAY_SIZE)+10;
  StaticJsonDocument<capacity> doc;
  // Elements du message
  //Tableau des donnée de la numérisation
  JsonArray data = doc.createNestedArray("data");
  JsonArray time = doc.createNestedArray("time");
  for (int i=0; i<DATA_ARRAY_SIZE; i++){
    data.add(potValue[i]);
    time.add(timeValue[i]);
  } 

  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["led"];
  if (!parse_msg.isNull()) {
    // mettre la led a la valeur doc["led"]
    digitalWrite(pinLED,doc["led"].as<bool>());
  }
}

/*---------------------------Definition de fonctions ------------------------
Fonction éxécuté à l'interruption du Timer1
Entrée : Aucun
Sortie : Aucun
Traitement : Écrit le temps et la valeur numérisée dans un tableau
-----------------------------------------------------------------------------*/
void printData(){
  //Écriture de la valeur numérisée
  potValue[arrayIndex] = analogRead(pinPOT);
  //Écriture du temps
  timeValue[arrayIndex] = millis();
  //Incrémentation de l'index du tampon circulaire
  if (arrayIndex < DATA_ARRAY_SIZE-1){
    arrayIndex++;
    }
  else {
    arrayIndex = 0;
  }
}