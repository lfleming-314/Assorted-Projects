#include "gamestate.h"
#include <string>
#include <array>
using namespace std;

GameState* GameState::instancePtr = nullptr;
GameState* gamestate = GameState::getInstance();

GameState* GameState::getInstance() {
    if (instancePtr == nullptr) instancePtr = new GameState();
    return instancePtr;
}

void GameState::setOrder(string order, string surge1, string surge2, string spren_type) {
    this->order = order;
    this->surges[0] = surge1;
    this->surges[1] = surge2;
    this->spren_type = spren_type;

}

string GameState::getOrder() { return this->order;}
array<string, 2> GameState::getSurges() { return this->surges;}

string GameState::getSprenType() {return this->spren_type;}
void GameState::setSprenName(string name) {this->spren_name = name;}

int GameState::getNumCharges() {return this->num_charges;}
void GameState::incrementCharges() {this->num_charges += 1;}
void GameState::decrementCharges() {this->num_charges -= 1;}

int GameState::getNumRocks() {return this->num_rocks;}
void GameState::incrementRocks() {this->num_rocks += 1;}
void GameState::decrementRocks() {this->num_rocks -= 1;}

void GameState::takeFiremark() {
    this->firemark = true;
    this->incrementCharges();
}
bool GameState::hasFiremark() {return this->firemark;}

void GameState::takeBoxing() {this->boxing = true;}
bool GameState::hasBoxing() {return this->boxing;}

void GameState::takeSkymark() {
    this->skymark = true;
    this->incrementCharges();
}
bool GameState::hasSkymark() {return this->skymark;}
