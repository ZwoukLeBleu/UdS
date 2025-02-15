// rectv2.cpp (based on Rectangle version 1 Gaddis ed 6  page 754)
// This program uses the Rectangle class, which is declared in
// the Rectangle.h file. The member Rectangle class's member
// functions are defined in the Rectangle.cpp file. This program
// should be compiled with those files in a project.
#include <iostream>
#include "rectangle.h"  // Needed for Rectangle class
using namespace std;

int main()
{
   Rectangle box;     	// Define an instance of the Rectangle class
   double rectWidth;  	// Local variable for width
   double rectLength; 	// Local variable for length
   int rectRed;			// Local variable for color red
   int rectGreen;		// Local variable for color green
   int rectBlue;		// Local variable for color blue

   // Get the rectangle's width and length from the user.
   cout << "This program will calculate the area of a\n";
   cout << "rectangle and display the color.\n\n";
   
   cout << "What is the width? ";
   cin >> rectWidth;
   cout << "What is the length? ";
   cin >> rectLength;
   cout << "What is the red color [0-255]? ";
   cin >> rectRed;
   cout << "What is the green color [0-255]? ";
   cin >> rectGreen;
   cout << "What is the blue color [0-255]? ";
   cin >> rectBlue;

   // Store the width and length of the rectangle
   // in the box object.
   box.setWidth(rectWidth);
   box.setLength(rectLength);
   box.setCouleur(rectRed, rectGreen, rectBlue);

   // Display the rectangle's data.
   cout << "Here is the rectangle's data:\n";
   cout << "Width: " << box.getWidth() << endl;
   cout << "Length: " << box.getLength() << endl;
   cout << "Area: " << box.getArea() << endl;
   cout << "Color: ";
   box.afficherCouleur();
   cout << endl;
   return 0;
}
