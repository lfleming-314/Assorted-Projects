#include "rightPath.h"
#include "gameState.h"
#include "inputProcessing.h"
#include "underConstruction.h"
#include <iostream>
#include <cstdlib>

void rightPath(gameState *my_state) {
  std::string prompt = R"(You see a pile of interesting rocks.
Do you take one?
  1. Take rock
  2. Continue on path)";
  int choice = input(2, prompt);
  if (choice == 2) {
    advanceRightPath( my_state);
  } else {
    std::cout << "The rock is very cool.\n";
    my_state->rocks ++;
    collectMoreRocks(my_state);
  }
}

void collectMoreRocks(gameState *my_state) {
  if (my_state->rocks > 1) {
    std::cout << "You have " << my_state->rocks <<" rocks.\n";
  }
  if (my_state->rocks >= 10) {
    tooManyRocks(my_state);
  } else if (my_state->rocks > 3 && !my_state->boxing) {
      collectBoxing(my_state);
      return;
  } else {
    std::string prompt = R"(Do you collect another rock?
  1. Take another rock
  2. Continue on path)";
    int choice = input(2, prompt);
    if (choice == 2) {
      advanceRightPath(my_state);
    } else {
      my_state->rocks++;
      collectMoreRocks(my_state);
    }
  }
}

void collectBoxing(gameState *my_state) {
  std::string prompt = R"(You see a strange object among the rocks. 
It appears to be a small, flat metal circle.
  1. Take the strange object
  2. Take another rock instead
  3. Continue on path)";
  int choice = input(3, prompt);
  if (choice == 3) {
    advanceRightPath(my_state);
  } else if (choice == 2) {
    my_state->rocks ++;
    collectMoreRocks(my_state);
  } else {
    std::cout << "You inspect the object. It appears to be made of gold and has a picture of a building on one side.\n";
    my_state->boxing = true;
    collectMoreRocks(my_state);
  }
}

void tooManyRocks(gameState *my_state) {
  std::cout << "There are no more rocks in the pile.\n";
  if (!my_state->boxing) {
    std::string prompt1 = R"(The strange object is still there.
    1. Take the strange object
    2. Continue on path)";
    int choice1 = input(2, prompt1);
    if (choice1 == 1) {
      my_state->boxing = true;
    }
  } else {
    std::string prompt = R"(  1. Continue on path)";
    input(1, prompt);
  }
  advanceRightPath(my_state);
}

void advanceRightPath (gameState *my_state) {
  my_state->rocks += 1;
  my_state->rocks -= 1;
  underConstruction();
}