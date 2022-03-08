//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes  

//PREPROCESSOR DIRECTIVES AND LIBRARIES

#include "pedestrian9.h"
#include <iostream>

using namespace std;

//DEFAULT CONSTRUCTOR
Pedestrian::Pedestrian()
{ 
  float const BAC_MAX = .2;
  float r = static_cast <float> (rand()) 
            / static_cast <float>(RAND_MAX/(BAC_MAX));
            
  person_symbol = 'P';
  person_bac = r;
  person_position = 0;
  person_width = 1;
  person_name = get_person_name();
}

//ACCESSORS
string Pedestrian::get_person_name()
{
  const int MAX_NAME = 25;
  const string names[25] = { "Homer", "Marge", "Bart", "Lisa", "Maggie",
                             "Blinky", "Dolph", "Duffman", "Itchy", "Scratchy", 
                             "Krusty", "Otto", "Nelson", "Patty", "Selma",
                             "Carl", "Eddie", "Lou", "Apu", "Seymour", 
                             "Milhouse", "Ralph", "Moe", "Edna", "Lenny" };
  string temp_name;
  int r = rand() % (MAX_NAME+1);
  temp_name = names[r];
       
 return temp_name;         
}

char Pedestrian::get_person_symbol() const
//Pedestrian accessor, get_person_symbol
{
  return person_symbol;
}//End get_person_symbol
 
float Pedestrian::get_person_bac() const
//Pedestrian accessor, get_person_bac
{
  return person_bac;     
}//End get_person_bac

int Pedestrian::get_person_position() const
//Pedestrian accessor, get_person_position
{
  return person_position;
}//End get_person_position

int Pedestrian::get_person_width() const
//Pedestrian accessor, get_person_position
{
  return person_width;                  
}//End get_person_width

//PEDESTRIAN MEMBER FUNCTIONS
//This function determines if a pedestrian object is drunk or not and walks
//them accross the road. While crossing a car the pedestrian with either repair
//or damage the car depending on there blood alcohol content
void Pedestrian::lets_walk(Road& road_in, Car& car_in, Pedestrian& person_in)
{
  const int MAX_DRUNK = 3;
  //INITIALIZATION AND DECLARATION OF CAR OBJECT MEMBER DATA
  int num_lanes = road_in.get_lanes();
  int car_position = car_in.get_car_position();
  int car_width = car_in.get_car_width();
  char car_symbol = car_in.get_car_symbol();
  
  //Initial car position with road state
  road_in.clear_road();
  road_in.set_lanes_car(car_position, car_width, car_symbol);
  road_in.set_lanes_person(0, person_symbol);
  
  //Print name
  cout << "Name: " << person_name << " " << "BAC: " << person_bac << endl;
  
  //Print road
  cout << road_in << " " << car_in << endl;
  
  for(int i = person_position; i < num_lanes; i++)
  //Starting to walk
  {
    //NOT DRUNK
    if(person_bac < .10) //IF BAC < .10
    {
      //Moving forward
      person_in.person_position++;
      i = person_in.person_position;
      
      //Check left border
      if(person_in.person_position <= -1)
      {
        person_in.person_position = 0;
        i = person_in.person_position;
      }
      
      //Collision
      if(person_in.person_position >= car_position && person_in.person_position 
         < car_position + car_width)
      {
        //REPAIR
        car_in.repair_car();
      }
      
      //Check right border  
      else if((person_in.person_position + person_in.person_width) >= num_lanes)
        person_in.person_position = num_lanes - person_in.person_width;
        
      //Clear road
      road_in.clear_road();
      
      //Update road with car
      road_in.set_lanes_car(car_position, car_width, car_symbol);
      
      //Update road with person
      road_in.set_lanes_person(person_position, person_symbol);
      
      //Print road
      cout << road_in << " " << car_in << endl;
     }//End if

    //DRUNK
    else //BAC > .10
    {
      //Random walking
      int r = rand() % (MAX_DRUNK+1);
      
      //Going back a step
      if(r == 0)
      {
        person_in.person_position--;
        i = person_in.person_position;
      }
      
      //Going forward a step
      else
      {
        person_in.person_position++;
        i = person_in.person_position; 
      }
      
      //Check left border
      if(person_in.person_position == -1)
      {
        person_in.person_position = 0;
        i = person_in.person_position;
      }
      
      //Check right border  
      else if((person_in.person_position + person_in.person_width) >= num_lanes)
        person_in.person_position = num_lanes - person_in.person_width;
        
      //Collision   
      if(person_in.person_position >= car_position && person_in.person_position 
         < (car_position + car_width))
      {
        //cout << "Collision" << endl;
        //Damage
        car_in.damage_car();
      }
          
      //Clear road
      road_in.clear_road();
      
      //Update road with car
      road_in.set_lanes_car(car_position, car_width, car_symbol);
      
      //Update road with person
      road_in.set_lanes_person(person_position, person_symbol);
      
      //Print road
      cout << road_in << " " << car_in << endl;
    }//End else
    
    //Delay
    for(int i = 0; i < 100000000; i++);
    
    //Break conditions
    if(car_in.get_car_dmg() >= 100)
      break;
      
    if(car_in.get_car_battery() <= 0)
      break;
 
  }//End for
  return;   
}//End lets_walk

