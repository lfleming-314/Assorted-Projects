#include "inputProcessing.h"
#include "gamestate.h"
#include "firstSegment.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {

string first_prompt = R"(Welcome to the text adventure! Press 0 to quit.
  
You are a Knight Radiant exploring the chasms of the Shattered Plains.
Which Radiant Order do you belong to?
  1. Windrunner
  2. Skybreaker
  3. Dustbringer
  4. Edgedancer
  5. Truthwatcher
  6. Lightweaver
  7. Elsecaller
  8. Willshaper
  9. Stoneward
  10. Bondsmith)";

  int first_response = input(10, first_prompt);
  switch (first_response){
    case 1:
      gamestate->setOrder("windrunner", "adhesion", "gravitation", "honorspren");
      break;
    case 2:
      gamestate->setOrder("skybreaker", "gravitation", "division", "highspren");
      break;
    case 3:
      gamestate->setOrder("dustbringer", "division", "abrasion", "ashspren");
      break;
    case 4:
      gamestate->setOrder("edgedancer", "abrasion", "progression", "cultivationspren");
      break;
    case 5:
      gamestate->setOrder("truthwatcher", "progression", "illumination", "mistspren");
      break;
    case 6:
      gamestate->setOrder("lightweaver", "illumination", "transformation", "Cryptic");
      break;
    case 7:
      gamestate->setOrder("elsecaller", "transformation", "transportation", "inkspren");
      break;
    case 8:
      gamestate->setOrder("willshaper", "transportation", "cohesion", "lightspren");
      break;
    case 9:
      gamestate->setOrder("stoneward", "cohesion", "tension", "peakspren");
      break;
    case 10:
      gamestate->setOrder("bondsmith", "tension", "adhesion", "unique spren");
      break;
  }

  nameSpren();  
  return 0;
}

