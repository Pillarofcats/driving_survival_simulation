//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes  

//PREPROCESSOR DIRECTIVES AND LIBRARIES

#include "car9.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//CAR CLASS DEFINITIONS

//GLOBAL VARIABLES
const int MAX_DAMAGE = 100;
const int MAX_BATTERY = 100;
const int MAX_DISTANCE = 100;

//CAR DEFAULT CONSTRUCTOR
Car::Car()
{
  int rng;  //Store random value for car battery
  const int RNG_MAX = 75;  //Car battery max value
  const int RNG_MIN = 50;  //Car battery min value
  
  car_width = 4;    //Intialization of car width
  car_dmg = 0.0;    //Initialization of car damage
  car_symbol = 'c'; //Initialization of car symbol
  
  rng = rand() % (RNG_MAX+1-RNG_MIN) + RNG_MIN; //Random num gen, (90-100)
  car_battery = rng; //Initialization of car_battery
  car_distance = 0;  //Initialization of car_distance
  car_position = 0;  //Initialization of car_position
  e_score = 0;       //Initialization of e_score
}//End default constructor

//CAR CONSTRUCTOR
Car::Car(int car_width_in, float car_dmg_in, 
         float car_battery_in, char car_symbol_in)
{
  car_width = car_width_in;      //Initialization of car width
  car_dmg = car_dmg_in;          //Initialization of car damage
  car_battery = car_battery_in;  //Initialization of car battery
  car_symbol = car_symbol_in;    //Initialization of car symbol
  car_distance = 0;              //Initialization of car distance
  car_position = 0;              //Initialization of car position
  e_score = 0;                   //Initialization of car e_score
}//End constructor

//ACCESSORS
int Car::get_e_score() const
//Car accessor, get_e_score
{
  return e_score;
}//End get_e_score

int Car::get_car_width() const 
//Car accessor, get_car_width
{
  return car_width;              
}//End get_car_width

float Car::get_car_dmg() const
//Car accessor, get_car_dmg
{
  return car_dmg;             
}//End get_car_dmg

float Car::get_car_battery()const
//Car accessor, get_car_battery
{ 
  return car_battery;               
}//End get_car_battery

int Car::get_car_distance() const
//Car accessor, get_car_distance
{
  return car_distance;   
}//End get_car_distance

char Car::get_car_symbol() const
//Car accessor, get_car_symbol
{
  return car_symbol;
}//End get_car_symbol

int Car::get_car_position() const
//Car accessor, get_car_position
{
  return car_position;
}//End get_car_position

//MUTATORS
void Car::set_e_score()
//Car mutator, set_e_score
{   
  e_score++;   
}//End set_e_score

void Car::set_car_position(int position_in)
//Car mutator, set_car_position
{
  car_position = position_in;
}//End set_car_position

//MEMBER FUNCTIONS
void Car::repair_car()
//Car member function, repair_car: This functions repairs the car by 1%
{
  car_dmg--;
  if(car_dmg <= 0)
    car_dmg = 0;    
}//End repair_car

void Car::damage_car()
//Car member function, damage_car: This function damages the car by 1%
{
  car_dmg++;
  if(car_dmg > MAX_DAMAGE)
    car_dmg = MAX_DAMAGE;  
}//End damage_car

void Car::increase_battery(float obstacle_wt_in)
//Pre Cond: Parameter in must be a float
//Post Cond: Returns modified car battery private member data
{
  int battery_inc;
  //Calculations for new battery value
  obstacle_wt_in /= 10;
  battery_inc = static_cast<int>(obstacle_wt_in);
  car_battery += battery_inc;
  
  //Condition check
  if(car_battery >= MAX_BATTERY)
    car_battery = MAX_BATTERY;    
}//End increase_battery

void Car::increase_damage(float animal_wt_in)
//Pre Cond: Parameter in must be an float
//Post Cond: Returns modified car battery private member data
{
  //Calculate damage to be added
  float add_dmg = ((100.0 - car_dmg)/100.0) * (animal_wt_in/10.0);
  //Adding damage to current damage
  car_dmg += add_dmg;
  car_dmg = static_cast<int>(car_dmg);
  //Condition check
  if(car_dmg > MAX_DAMAGE)
    car_dmg = MAX_DAMAGE;

  return;
}//End increase_damage

//This function increase the distance traveled and decrements the battery
//for every 1km traveled
void Car::dist_driven()
{
  car_distance++;
  car_battery--;
  return;
}//End distance_driven

//CAR OPERATOR
ostream& operator << (ostream& output, const Car& car_status)
//Pre Cond: I/O stream library must be included, has access to car class
//Post Cond: Returns output stream, can output car class objects
{
   //Display car status
   output << "[CAR STATUS] " << "Battery: " << car_status.car_battery 
          << " | Damage: " << car_status.car_dmg << " | Distance: "
          << car_status.car_distance;
          
   //Display car destruction condition
   if(car_status.car_dmg >= MAX_DAMAGE)
     output << "\nThe car has blown up! You died.";
     
   //Display car battery depleted  
   else if(car_status.car_battery <= 0)
     output << "\nThe car has run out of power. This is as far as you go.";
     
   //Display car distance condition
   if(car_status.car_distance >= MAX_DISTANCE)
     output << "\nYou have reached your destination." <<endl;
   
   return output; //return ostream object
}// End ostream operator
