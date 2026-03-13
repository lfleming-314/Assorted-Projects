#include "leftPath.h"
#include "gameState.h"
#include "inputProcessing.h"
#include "underConstruction.h"
#include <iostream>
#include <cstdlib>

void leftPath(gameState *my_state) {
    std::string prompt = R"(After treading a ways along the path, you see a small pool of water. 
It appears to be glowing faintly red.
Do you look closer?
  1. Investigate the pool
  2. Continue on path)";
  int choice = input(2, prompt);
  if (choice == 2) {
    advanceLeftPath(my_state);
  } else {
    investigatePool(my_state);
  }
}

void investigatePool(gameState *my_state) {
    std::string prompt = R"(The red glow comes from a charged ruby sphere.
Do you take it?
  1. Take sphere
  2. Continue on path)";
  int choice = input(2, prompt);
  if (choice == 2) {
    advanceLeftPath(my_state);
  } else {
    takeFiremark(my_state);
  }
}

void takeFiremark(gameState *my_state) {
    std::string prompt = R"(You have collected a firemark!
  1. Continue on path)";
  my_state->firemark = true;
  input(1, prompt);
  advanceLeftPath(my_state);
}

void advanceLeftPath(gameState *my_state) {
    my_state->rocks += 1;
    my_state->rocks -= 1;
    underConstruction();
}