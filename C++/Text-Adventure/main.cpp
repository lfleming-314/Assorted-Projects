#include "inputProcessing.h"
#include "gameState.h"
#include "rightPath.h"
#include "leftPath.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
  gameState my_state;

  std::string first_prompt = R"(Welcome to the text adventure! Press 0 to quit.
  
You are exploring the chasms of the Shattered Plains.
You encounter a crossroads. Which way do you go?
  1. Go Left
  2. Go Right)";

  int first_response = input(2, first_prompt);
  if (first_response == 1) { leftPath(&my_state);}
  else { rightPath(&my_state); }

  return 0;
}

