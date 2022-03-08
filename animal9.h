//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes 

//PREPROCESSOR DIRECTIVES AND LIBRARIES
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "road9.h"
#include "car9.h"

using namespace std;

//DECLARING CLASSES
class Road;
class Car;

class Animal
{
  public:
         
    //CONSTRUCTORS
    Animal(); //default construct
    Animal(string animal_in, int width_animal_in, 
           float weight_animal_in, int chance_road_in); //Constructor
    void animal_appears(Animal& animal_in, Road& road_in, Car& car_in);
    
    //ACCESSORS      
    float get_weight_animal() const; //Accessor function, weight animal
    int get_width_animal() const;    //Accessor function, width animal
    string get_animal() const;       //Accessor function, species animal
    int get_stupid() const;          //Accessor function, stupidity animal
    bool get_is_dead() const;        //Accessor function, dead/alive animal
    char get_animal_symbol() const;  //Accessor function, animal symbol
    int get_animal_position() const; //Accessor function, animal position
    
    //MUTATORS
    void set_animal_position(int position_in); //Mutator Function, animal pos.
    
    //OPERATORS
    friend ostream& operator << (ostream& output, const Animal& animal_status);
    
  private:
          
    //PRIVATE MEMBER FUNCTIONS
    bool choose_to_run(int chance_walk_road_in); //Animal condition check
    
    //PRIVATE MEMBER VARIABLES
    bool is_dead;              //Animal is alive/dead?
    bool ran;                  //Animal ran? 
    float kg_weight_animal;    //Animal's weight in kg
    string animal;             //Animal's species
    int width_animal;          //Animal's width
    int chance_walk_on_road;   //Animal's stupidity
    char animal_symbol;        //Animal's symbol
    int animal_position;       //Animal's position
}; //End car animal

#endif //ANIMAL_H
