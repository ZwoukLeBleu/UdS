#include <LibRobus.h>
#include <Arduino.h>

int etat = 0; // 0 = arrêt, 1 = avance, 2 = recule, 3 = tourne à droite, 4 = tourne à gauche
float vitesse = 0.37;
int maze[5][10] = { // 1 = mur, 0 = vide
{0,0,0,0,1,0,0,0,0,0},
{1,1,1,0,1,1,1,1,1,1},
{1,1,1,0,1,1,1,1,1,1},
{1,0,1,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1}
};

int posX = 0, posY = 0, direction = 1; // Position et direction initiales

void arret() {
  MOTOR_SetSpeed(RIGHT, 0);
  MOTOR_SetSpeed(LEFT, 0);
}

void avance(int distance) {
  MOTOR_SetSpeed(RIGHT, vitesse * 0.99);
  MOTOR_SetSpeed(LEFT, vitesse * 1.03);
  delay(distance);
  arret();
}

void recule(int distance) {
  MOTOR_SetSpeed(RIGHT, -vitesse);
  MOTOR_SetSpeed(LEFT, -vitesse);
  delay(distance);
  arret();
}

void tourneDroit() {
  MOTOR_SetSpeed(RIGHT, 0.5 * vitesse);
  MOTOR_SetSpeed(LEFT, -0.5 * vitesse);
  delay(500); 
  direction = (direction + 4) % 4; 
}

void tourneGauche() {
  MOTOR_SetSpeed(RIGHT, -0.5 * vitesse);
  MOTOR_SetSpeed(LEFT, 0.5 * vitesse);
  delay(500); 
  direction = (direction + 3) % 4; 
}



/// @brief Permets de vérifier si le robot peut avancer en fonction des murs et obstacles
/// @return true si le robot peut avancer, false sinon
bool canMoveForward() {
  int nextX = posX, nextY = posY;

  if (direction == 0) { // down
    nextY++;
  }
  if (direction == 1) { // right
    nextX++;
  }
  if (direction == 2) { // up
    nextY--;
  }
  if (direction == 3){ // left
    nextX--;
  }

  if (nextX < 0 || nextX > 9 || nextY < 0 || nextY > 4) {
    return false; // Hors labyrinthe
  }

  if (maze[nextY][nextX] == 1) {
    return false; // Mur
  }

  return true; // erreur here **
}

void updatePosition() {
  if (direction == 0) {
    posY++;
  } else if (direction == 1) {
    posX++;
  } else if (direction == 2) {
    posY--;
  } else if (direction == 3) {
    posX--;
  }
  
  Serial.print("Position: (");
  Serial.print(posX);
  Serial.print(", ");
  Serial.print(posY);
  Serial.print(") Direction: ");
  Serial.println(direction);
}


void setup() {
  BoardInit();
}

void loop() {
  switch(etat) {
    case 0: // Avancer
      if (canMoveForward()) {
        avance(1000);
        updatePosition();
      } else {
        etat = 1; // Reculer si bloqué
      }
      break;
      
    case 1: // Reculer
      recule(300);
      etat = 2; // Tourner à droite après le recul
      break;

    case 2:
        switch (direction)
        {
        case 0:
            if (maze[posX+1][posY] == 1) { tourneDroit(); }
            else { tourneGauche(); }
            break;
        case 1: 

        default:
            break;
        }   
  }

  delay(200);
}
