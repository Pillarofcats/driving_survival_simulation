//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes
           
//PREPROCESSOR DIRECTIVES AND LIBRARIES
           
#include "road9.h"
#include <iostream>
#include <string>

using namespace std;

//ROAD CLASS DEFINITIONS

//DEFAULT CONSTRUCTOR
Road::Road()  
{
  //INITALIZAE PRIVATE DATA MEMBERS
  num_of_lanes = 10; //Intialize number of lanes

  //CLEAR THE ROAD
  for(int i = 0; i < num_of_lanes; i++)
    lanes[i] =  ' ';
}//End default constructor

//MUTATORS
//This function places a pedestrian object onto the road at a specific position
void Road::set_lanes_person(int person_position_in, char person_symbol_in)
{    
  lanes[person_position_in] = person_symbol_in;     
}

//This function places a car object onto the road at a specific position         
void Road::set_lanes_car(int car_position_in, int car_width_in, 
                         char car_symbol_in)
{
  for(int i = car_position_in; i < car_position_in + car_width_in; i++)
    lanes[i] = car_symbol_in;
}

//This function places a animal object onto the road at a specific position
void Road::set_lanes_animal(int animal_position_in, int animal_width_in, 
                            char animal_symbol_in)
{
  for(int i = animal_position_in; i < animal_position_in + animal_width_in; i++)
    lanes[i] = animal_symbol_in;
}

//ACCESSORS
int Road::get_lanes() const
//road accessor, get_lanes
{ 
  return num_of_lanes;
}//End get_lanes

//ROAD MEMBER FUNCTIONS
//This functions determines the course the car object will take as it drives
//on the road, it will either stay center, go left, or right
void Road::left_right(const Car & car_in, int& pos_car_in)
{
   //DECLARATION & INITIALIZATION OF CAR CLASS MEMBER DATA
   const int car_width = car_in.get_car_width();
   const char car_symbol = car_in.get_car_symbol();
   
   //EDGE OF ROAD CHECK AND REPOSITION
   if(pos_car_in == -1)
     pos_car_in = 0;
   
   else if((pos_car_in + car_width) >= num_of_lanes)
     pos_car_in = num_of_lanes - car_width;
     
   //NEED TO SCAN ROAD FOR OBJECT BEFORE MOVING CAR
   //Clear the road for now  
   for(int i = 0; i < num_of_lanes; i++)
     lanes[i] =  ' ';
     
   //Print the car in its new position
   for(int i = pos_car_in; i < pos_car_in + car_width; i++)
      lanes[i] = car_symbol;
   
  return;
}//End car_left_right

//This function clears the road by replacing elements with spaces
void Road::clear_road()
{
 for(int i = 0; i < num_of_lanes; i++)
    lanes[i] =  ' ';    
}//End clear_road

//ROAD OPERATOR
ostream& operator << (ostream& output, const Road& road_in)
//Pre Cond: I/O stream library must be included, has access to road class
//Post Cond: Returns output stream, can output road class objects
{
  output << "|";
  //Display road status
  for(int i = 0; i < road_in.num_of_lanes; i++)
    output << road_in.lanes[i] << "|";
    
  return output; //return ostream object
}// End ostream operator
