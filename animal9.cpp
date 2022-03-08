//Programmer: Jacob White
//Section: F
//Files: animal9.cpp/animal9.h/road9.cpp/road9.h/car9.cpp/car9.h/main9.cpp
//Date: 11/1/2015
//Purpose: To create an object oriented program that integrates multiple classes 
 
//PREPROCESSOR DIRECTIVES AND LIBRARIES
          
#include "animal9.h"

using namespace std;

//ANIMAL CLASS DEFINITIONS
int hit = 0;

//ANIMAL DEFAULT CONSTRUCTOR
Animal::Animal() 
{}//End Animal default constructor

//ANIMAL CONSTRUCTOR
Animal::Animal(string animal_in, int width_animal_in, 
               float weight_animal_in, int chance_road_in)
{
  animal = animal_in; //Initialize animal private member
  kg_weight_animal = weight_animal_in; //Initialize weight private member
  width_animal = width_animal_in; //Initialize width private member
  chance_walk_on_road = chance_road_in;//Initialize stupidity private member
  is_dead = false; //Initialize dead private member
  animal_symbol = 'a'; //Initialize animal symbol private member
}//End Animal constructor

//This functions takes in 3 objects and generates an animal on the road in
//a random position. The constraints of this function are dependent on the
//objects passed in to function properly.
void Animal::animal_appears(Animal& animal_in, Road& road_in, Car& car_in)
{
  //VARIABLES
  const int MAX_POSITION = road_in.get_lanes(); //Get, max number of lanes
  const int LOSER_STAR = 10; //Max number of lines in loser star file
  string rline;  //string variable for random loser star line
  int r;  //random number variable
  
  //GET PRIVATE MEMBER DATA OF CLASS CAR
  int car_position = car_in.get_car_position();
  int car_width = car_in.get_car_width();
  char car_symbol = car_in.get_car_symbol();
  
  //DECLARE IFSTREAM OBJECT
  ifstream stream_in;
  
  //OPEN IFSTREAM OBJECT
  stream_in.open("loser_star.dat");
  
  //CHECK IF ANIMAL CHOSE TO RUN ONTO THE ROAD
  ran = choose_to_run(chance_walk_on_road);
  
  //JUMP ON ROAD
  if(ran == true)
  {
    //PICK RANDOM LOCATION ON ROAD
    r = rand() % (MAX_POSITION); //0 -> 14
    
    //CHECK RIGHT BORDER 
    if((r + width_animal) >= road_in.get_lanes())
      r = road_in.get_lanes() - width_animal;
      
    //SET ANIMAL POSITION TO RANDOM LOCATION ON ROAD
    animal_in.set_animal_position(r);
    
    //CLEAR ROAD
    road_in.clear_road();
    
    //PRINT CAR
    road_in.set_lanes_car(car_position, car_width, car_symbol);
    
    //PRINT ANIMAL
    road_in.set_lanes_animal(animal_in.animal_position, animal_in.width_animal, 
                             animal_in.animal_symbol);
    
    //PRINT ROAD
    cout << road_in;
    
    //COLLISION DETECTION 
    if((animal_position >= car_position 
      && animal_position < car_position + car_width)
      || (animal_position + width_animal > car_position 
      && animal_position + width_animal < car_position + car_width) 
      || (animal == "whale"))
    {
      //LONESTAR SERVICE ANNOUNCEMENT
      //RANDOM ROLL FOR LINE NUMBER IN FILE
      int r = rand() % (LOSER_STAR+1); // 0 -> 9
      
      //GET RANDOM LONESTAR LINE
      for(int i = 0; i < r; i++)
        getline(stream_in, rline);
      
      //OUTPUT LOSERSTAR MESSAGE
      cout << rline << endl;
      cout << " You've hit a " << animal 
           << "! Can I be of assistance? " << endl;
           
      //INCREASE E-SCORE +1
      car_in.set_e_score();
      
      //INCREASE BATTERY
      car_in.increase_battery(animal_in.kg_weight_animal);
      
      //BATTERY CONDITION CHECK    
      if(car_in.get_car_battery() <= 0)
      {
        is_dead = true;
        car_in.increase_damage(animal_in.kg_weight_animal);
      }
      
      else
      {
        is_dead = true;
        car_in.increase_damage(animal_in.kg_weight_animal);
        cout << " " << car_in;
      }
    }//End if
    
    cout << endl;
  }//End if
  else
  
  //DISPLAY ROAD
  cout << road_in << endl;
  
  //CLOSE IFSTREAM OBJECT
  stream_in.close();
   
  return;    
}//End animal_appears

//ANIMAL ACCESSORS
string Animal::get_animal() const
//Animal accessor, get_animal
{
  return animal;      
}//End get_animal

float Animal::get_weight_animal() const
//Animal accessor, get_weight
{
  return kg_weight_animal;             
}//End get_weight_animal

int Animal::get_width_animal() const
//Animal accessor, get width_animal
{
  return width_animal;  
}//End get_width

int Animal::get_stupid() const
//Animal accessor, get_stupid
{
  return chance_walk_on_road;
}//End get_stupid

bool Animal::get_is_dead() const
//Animal accessor, get_is_dead
{
  return is_dead;
}//End get_is_dead

char Animal::get_animal_symbol() const
//Animal accessor, get_animal_symbol
{
  return animal_symbol;
}//End get_animal_symbol

int Animal::get_animal_position() const
//Animal accessor, get_animal_position
{   
  return animal_position;   
}//End get_animal_position

//ANIMAL MUTATORS
void Animal::set_animal_position(int position_in)
//Animal mutator, set_animal_position
{
  animal_position = position_in;    
}//End set_animal_position

//ANIMAL MEMBER FUNCTIONS
bool Animal::choose_to_run(int chance_walk_on_road_in)
//Pre Conidtions : Parameter is a integer
//Post Conditions: Returns if the animal chose to run
{
  const int MAX_LUCK = 100;
  bool walk_on_road = false; //bool variable to check animal on/off road
  int r;
  
  //Condition check for stupidity to see if animal walks on/off road
  if(chance_walk_on_road_in <= 100 && chance_walk_on_road_in >= 80)
  {
    r = rand() % (MAX_LUCK); // 0 -> 99
    
    if(r <= 79)
      walk_on_road = true;

    else
      walk_on_road = false;
    
  }//End if
  
  //Condition check for stupidity to see if animal walks on/off road
  else if(chance_walk_on_road_in >= 50 && chance_walk_on_road_in < 80)
  {  
    r = rand() % (MAX_LUCK); // 0 -> 99
    if(r <= 49)
      walk_on_road = true;
      
    else
      walk_on_road = false;

  }//End else if
  
  else
  {  
    r = rand() % (MAX_LUCK); // 0 -> 99
    if(r <= 4)
      walk_on_road = true;

    else
      walk_on_road = false;

  }//End else if
   
  return walk_on_road;
}//End choose_to_run

//ANIMAL OPERATOR
ostream& operator << (ostream& output, const Animal& animal_status)
//Pre Cond: I/O stream library must be included, has access to animal class
//Post Cond: Returns output stream, can output animal class objects
{
   //Display animal status
   output << "[ANIMAL STATUS] " << "Animal: " << animal_status.animal
          << " | Weight: " << animal_status.kg_weight_animal
          << " | Width: " << animal_status.width_animal
          << " | Stupid: " << animal_status.chance_walk_on_road << endl;
   
   return output; //return ostream object  
}// End ostream operator
