//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes 

//PREPROCESSOR DIRECTIVES AND LIBRARIES
#ifndef ROAD_H
#define ROAD_H

#include "animal9.h"
#include "pedestrian9.h"
#include "car9.h"
#include <iostream>


using namespace std;

int const MAX_LANES = 15; //15 lanes per road, max

class Car;
class Pedestrian;
class Animal;

class Road
{
  public:
    //DEFAULT CONSTRUCTOR
    Road(); 
    
    //ACCESSORS
    int get_lanes() const;
    
    //MUTATORS
    void set_lanes_person(int person_position_in, char person_symbol_in);
    void set_lanes_car(int car_position_in, int car_width_in, 
                       char car_symbol_in);
    void set_lanes_animal(int animal_position_in, int animal_width_in, 
                          char animal_symbol_in);
    
    //ROAD MEMBER FUNCTIONS
    void left_right(const Car & car_in, int& pos_car_in);
    void clear_road();
    
    //OPERATORS
    friend ostream& operator << (ostream& output, const Road& road_in);
    
  private:
          
    //PRIVATE MEMBER VARIABLES
    int num_of_lanes;       //Number of lanes
    char lanes[MAX_LANES];  //Max number of lanes, array    
}; //End class Road

#endif //ROAD_H
