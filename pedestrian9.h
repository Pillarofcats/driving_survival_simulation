//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes  

//PREPROCESSOR DIRECTIVES AND LIBRARIES

#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "road9.h"
#include "car9.h"

using namespace std;

//DECLARING CLASSES
class Road;
class Car;

class Pedestrian
{
  public:
    
    //DEFAULT CONSTRUCTOR
    Pedestrian();
    
    //ACCESORS
    char get_person_symbol() const;
    float get_person_bac() const;
    int get_person_position() const;
    int get_person_width() const;

    //MEMBER FUNCTIONS
    void lets_walk(Road& road_in, Car& car_in, Pedestrian& person_in);
    
  private:
    
    //PRIVATE MEMBER FUNCTIONS 
    string get_person_name();
    
    //PRIVATE MEMBER VARIABLES
    char person_symbol;
    float person_bac;
    int person_position;
    int person_width;
    string person_name;
      
}; //End Pedestrian class

#endif //PEDESTRIAN_H

