//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes  

//PREPROCESSOR DIRECTIVES AND LIBRARIES
#ifndef CAR_H
#define CAR_H

#include "road9.h"
#include <iostream>

using namespace std;

class Car
{
  public:
         
    //CAR DEFAULT CONSTRUCTOR
    Car();
    
    //CAR CONSTRUCTORS
    Car(int car_width_in, float car_dmg_in, 
        float car_battery_in, char car_symbol_in);
        
    //ACCESSORS
    int get_car_width() const;    //Accessor function, car width
    float get_car_dmg() const;    //Accessor function, car damage
    float get_car_battery() const;//Accessor function, car battery
    int get_car_distance() const; //Accessor function, car distance
    char get_car_symbol() const;  //Accessor function, car symbol
    int get_car_position() const; //Accessor function, car position
    int get_e_score() const;      //Accessor function, car e-score
    
    //MUTATORS
    void set_car_position(int position_in);  //Mutator function set_car_position
    void set_e_score();                      //Mutator function, set_e_score
    
    //MEMBER FUNCTIONS
    void dist_driven();                         //Member function, dist_driven
    void repair_car();                          //Member function, repair_car
    void damage_car();                          //Member function, damage_car
    void increase_battery(float obstacle_wt_in);//Member function, increase_bat
    void increase_damage(float animal_wt_in);   //Member function, increase_dam
    
    //OPERATORS
    friend ostream& operator << (ostream& output, const Car& car_status);
    
  private:
          
    //PRIVATE MEMBER FUNCTIONS
    int car_width;     //Car Width
    float car_dmg;     //Car damage
    float car_battery; //Car battery
    char car_symbol;   //Car symbol
    int car_distance;  //Car distance
    int car_position;  //Car position
    int e_score;       //Car escore
    
};  //End class Car

#endif //CAR_H
