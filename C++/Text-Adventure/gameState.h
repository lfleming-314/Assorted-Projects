#include <string>
#include <array>
using namespace std;

#ifndef GAMESTATE
#define GAMESTATE

class GameState {
  private:
    static GameState* instancePtr;
    GameState() {};
    string order;
    array<string,2> surges;
    string spren_type;
    string spren_name;
    int num_charges = 0;
    int num_rocks = 0;
    bool firemark = false;
    bool boxing = false;
    bool skymark = false;
  public:
    static GameState* getInstance();
    void setOrder(string order, string surge1, string surge2, string spren_type);
    string getOrder();
    array<string, 2> getSurges();
    string getSprenType();
    void setSprenName(string name);
    int getNumCharges();
    void incrementCharges();
    void decrementCharges();
    int getNumRocks();
    void incrementRocks(); 
    void decrementRocks();
    void takeFiremark();
    bool hasFiremark();
    void takeBoxing();
    bool hasBoxing();
    void takeSkymark();
    bool hasSkymark();
};

extern GameState* gamestate;

#endif