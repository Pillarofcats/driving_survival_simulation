//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes 

//PREPROCESSOR DIRECTIVES AND LIBRARIES
 
#include "car9.h"
#include "pedestrian9.h"
#include "road9.h"          
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

//FUNCTION PROTOTYPES
void get_animal_data(Animal animal_in[]);
void print_animals_hit(ifstream& stream_in);

using namespace std;

//GLOBAL VARIABLES
const int MAX_ANIMALS = 10;

//MAIN
int main()
{
  //RUN EMULATION 3 TIMES  
  for(int i = 0; i < 3; i++)
  {
  
  //VARIABLE DECLARATIONS & INITIALIZATIONS
  const int MAX_LEFT_RIGHT = 2;
  const int MAX_PEDESTRIAN = 100;
  const int PEDESTRIAN_PERCENT = 5;
  
  bool distance = false;
  bool battery = false;
  bool damage = false;
  
  int r;
  
  //INITIALIZE RANDOM SEED USING SYSTEM CLOCK
  srand(time(NULL));
   
  //DECLARE EMULATION OBJECTS
  Car car;
  Animal animals[10];
  Road road;
  
  //DECLARE OFSTREAM OBJECT
  ofstream streamout; 
  
  //OPEN OFSTREAM OBJECT FILE
  streamout.open("animals_hit.dat");
    
  //GET ANIMAL DATA FROM FILE
  get_animal_data(animals);
  cout << "The car's starting battery life is " << car.get_car_battery() 
       << "." << endl << endl;
  
  //SET INITIAL CONDITIONS FOR CAR OBJECT
  int car_width = car.get_car_width();
  char car_symbol = car.get_car_symbol();
  car.set_car_position(3);
  int position_car = car.get_car_position();
  
  //CLEAR ROAD
  road.clear_road();
  
  //PRINT ROAD AND CAR OBJECTS
  road.set_lanes_car(position_car , car_width, car_symbol);
  
  //PRINT ROAD
  cout << road << endl;
  
  do
  //EMULATION START
  {
    //CAR CHANGING LANES     
    r = rand() % (MAX_LEFT_RIGHT+1); //0 -> 1
    if(r == 2)
      position_car++;
      
    else if(r == 0)
      position_car--;
    
    //CAR MOVES LEFT / RIGHT / FORWARD
    road.left_right(car, position_car);
    
    //GET CARS POSITION 
    car.set_car_position(position_car);
    
    //UPDATE DISTANCE AND BATTERY AFTER 1KM   
    car.dist_driven();
    
    //PEDESTRIAN WALKS
    r = rand() % (MAX_PEDESTRIAN);
    if(r < PEDESTRIAN_PERCENT)
    { 
      //CREATE PEDESTRIAN OBJECT
      Pedestrian person;
      //FUNCTION CALL, pedestrian::lets_walk
      person.lets_walk(road, car , person);
    }
    
    //ANIMAL APPEARS
    else
    {
      //GET RANDOM ANIMAL
      r = rand() % (MAX_ANIMALS);
      
      //CREATE RANDOM ANIMAL OBJECT
      Animal animal = animals[r];
      
      //CHECK IF ANIMAL APPEARS, FUNCTION CALL, animal::animal_appears
      animal.animal_appears(animal, road, car);
      
      //ANIMALS HIT LOG
      if(animal.get_is_dead() == true)
      {
        //OUTPUT(WRITE) ANIMALS HIT
        streamout << animal << "\n";
      }//End if                                       
    }//End else
    
    //DELAY
    for(int i = 0; i < 100000000; i++);
    
    //END CONDITIONS
    if(car.get_car_distance() >= 100)
    {
      distance = true;
      cout << car << endl;
    }
    
    if(car.get_car_dmg() >= 100)
    {
      damage = true;
    }
    
    if(car.get_car_battery() <= 0)
    {
      battery = true;
      cout << car << endl;
    } 
  
  //END while()
  }while(!(battery == true || damage == true || distance == true));

  //CLOSING ANIMALS HIT FILE
  streamout.close();
  
  cout << endl;
  
  //PRINT ANIMALS HIT
  ifstream streamin;
  streamin.open("animals_hit.dat");
  cout << "ANIMALS HIT: " << endl;
  print_animals_hit(streamin);
  streamin.close();
  
  //PRINT E-SCORE
  cout << "E-SCORE: " << car.get_e_score() << endl << endl;
  
  }//End for
  int cat;
  cin >> cat;
  
  return 0;
}//END main

//This function gets animal data from a file and stores them into an
//animal object array.
void get_animal_data(Animal animal_in[])
{
  string species;
  int width;
  float weight_kg;
  int stupid;
  //declare ifstream object streamin
  ifstream streamin;
  //Open ifstream object
  streamin.open("animal_db.dat"); 
  
  while(!streamin.eof())
  {  
    for(int i = 0; i < MAX_ANIMALS ; i++)
    {
      //Read in animal data and create an animal object 10 times                    
      streamin >> species >> width >> weight_kg >> stupid;   
      //Declare a new animal for each index from file data of animals
      Animal a(species, width, weight_kg, stupid);
      animal_in[i] = a; //new Animal(species, width, weight_kg, stupid);
    }//End for
  }//End while, end of file
  
  //Close ifstream object
  streamin.close(); 
  return;
}//End get_animal_data

//This function prints out all the animals hit in the emulation
void print_animals_hit(ifstream& stream_in)
{
  string line;
  while(!stream_in.eof())
  { 
    getline(stream_in, line);
    cout << line << endl;
  }//End while, end of file
}//End print_animals_hit

