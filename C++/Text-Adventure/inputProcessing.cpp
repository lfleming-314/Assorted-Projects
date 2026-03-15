#include "inputProcessing.h"
#include <iostream>
#include <string>

int getInput(int max, std::string prompt) {
  std::cout << prompt;
  std::string response;
  std::cin >> response;
  int choice;
  try {choice = stoi(response);}
  catch( std::invalid_argument const&) {
    choice = getInput(max, "Invalid response. Try again.\n>");
    }
  return choice;
}

int input (int max, std::string prompt) {
  std::cout << prompt << "\n>";
  int choice = getInput(max, "");
  if (choice == 0) { 
    std::cout << "Goodbye!\n";
    exit(0); }
  if (choice < 0 || choice > max) {
    choice = input(max, "Not an option. Try again.\n>");
  }
  return choice;
}

string stringInput() {
  cout << ">";
  string response;
  cin >> response;
  if (response == "0") {
    exit(0);
  }
  return response;
}