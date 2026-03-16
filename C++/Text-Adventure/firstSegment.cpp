#include "firstSegment.h"
#include "gamestate.h"
#include "inputProcessing.h"
#include "underConstruction.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

void nameSpren() {
    array<string, 2> surges = gamestate->getSurges();
    cout << "Your surges are " + surges[0] + " and " + surges[1] + ".\n";
    cout << "You are bonded to a " + gamestate->getSprenType() + ".\n";
    if (gamestate->getOrder() == "bondsmith") {
        string prompt = R"(Which one is your spren?
  1. The Stormfather
  2. The Sibling
  3. The Nightwatcher)";
        int uniqueSpren = input(2, prompt);
        switch (uniqueSpren) {
            case 1:
                gamestate->setSprenName("Stormfather");
                break;
            case 2:
                gamestate->setSprenName("Sibling");
                break;
            case 3:
                gamestate->setSprenName("Nightwatcher");
                break;
        }
    } else {
        cout << "What is your spren's name?\n";
        string name = stringInput();
        gamestate->setSprenName(name);
    }

    findPool();
}
    
void findPool() {
    string prompt = "After treading a ways along the path, you see a small pool of water.\n";
    prompt.append("It appears to be glowing faintly red.\n");
    prompt.append("Do you look closer?\n");
    prompt.append("  1. Investigate the pool\n");
    prompt.append("  2. Continue on path\n");
    int choice = input(2, prompt);
    if (choice == 1) {
        investigatePool();
    } else {
        advancePath();
    }
}

void investigatePool() {
    string prompt = "The red glow comes from a charged firemark.\n";
    prompt.append("Do you take it?\n");
    prompt.append("  1. Take firemark\n");
    prompt.append("  2. Continue on path\n");
    int choice = input(2, prompt);
    if (choice == 1) {
        collectFiremark();
    } else {
        toRockpile();
    }
}

void collectFiremark() {
    gamestate->takeFiremark();
    cout << "You now have " + to_string(gamestate->getNumCharges()) + " charged spheres.\n";
    toRockpile();
}

void toRockpile() {
    string prompt = "You continue along the path and find a pile of interesting rocks.\n";
    prompt.append("Do you take one?\n");
    prompt.append("  1. Take rock\n");
    prompt.append("  2. Continue on path\n");
    int choice = input(2, prompt);
    if (choice == 1) {
        cout << "The rock is very cool.\n";
        gamestate->incrementRocks();
        collectMoreRocks();
    } else {
        advancePath();
    }
};

void collectMoreRocks() {
    if (gamestate->getNumRocks() >= 10) {
        tooManyRocks();
    } else if (gamestate->getNumRocks() > 7 && !gamestate->hasSkymark()) {
        if (!gamestate->hasBoxing()) {
            findBoxingOrSkymark();
        } else {
        findSkymark();
        }
    } else if (gamestate->getNumRocks() > 3 && !gamestate->hasBoxing()) {
        findBoxing();
    }  else {
        string prompt = "There are " + to_string(10 - gamestate->getNumRocks()) + " more rocks in the pile.\n";
        prompt.append("  1. Take another rock\n"); 
        prompt.append("  2. Continue on path\n");
        int choice = input(2, prompt);
        if (choice == 1) {
            gamestate->incrementRocks();
            cout << "You have " + to_string(gamestate->getNumRocks()) + " rocks.\n";
            collectMoreRocks();
        } else {
            advancePath();
        }
    }
}

void findBoxing() {
    string prompt = "You see a strange object among the rocks. It appears to be a small, flat metal circle.\n";
    prompt.append("  1. Take the strange object\n");
    prompt.append("  2. Take another rock instead\n");
    prompt.append("  3. Continue on path\n");
    int choice = input(3, prompt);
    if (choice == 1) {
        acquireBoxing();
        collectMoreRocks();
    } else if (choice == 2) {
        gamestate->incrementRocks();
        cout << "You have " + to_string(gamestate->getNumRocks()) + " rocks.\n";
        collectMoreRocks();
    } else {
        advancePath();
    }
}

void acquireBoxing() {
    cout << "You inspect the object. It appears to be made of gold and has a picture of a building on one side.\n";
    gamestate->takeBoxing();
}

void findSkymark() {
    string prompt = "You uncover the blue glow of a skymark!\n";
    prompt.append("  1. Take the skymark\n");
    prompt.append("  2. Take another rock instead\n");
    prompt.append("  3. Continue on path\n");
    int choice = input(3, prompt);
    if (choice == 1) {
        acquireSkymark();
        collectMoreRocks();
    } else if (choice == 2) {
        gamestate->incrementRocks();
        cout << "You have " + to_string(gamestate->getNumRocks()) + " rocks.\n";
        collectMoreRocks();
    } else {
        advancePath();
    }
}

void acquireSkymark() {
    gamestate->takeSkymark();
    cout << "You now have " + to_string(gamestate->getNumCharges()) + " charged spheres.\n";
}

void findBoxingOrSkymark() {
    string prompt = "You see a strange object among the rocks. It appears to be a small, flat metal circle.\n";
    prompt.append("You also see a skymark in the rock pile.\n");
    prompt.append("Which do you take?\n");
    prompt.append("  1. Take the strange object\n");
    prompt.append("  2. Take the skymark\n");
    prompt.append("  3. Take another rock instead\n");
    prompt.append("  4. Continue on path\n");
    int choice = input(4, prompt);
    if (choice == 1) {
        acquireBoxing();
        collectMoreRocks();
    } else if (choice == 2) {
        acquireSkymark();
        collectMoreRocks();
    } else if (choice == 3) {
        gamestate->incrementRocks();
        cout << "You have " + to_string(gamestate->getNumRocks()) + " rocks.\n";
        collectMoreRocks();
    } else {
        advancePath();
    }
}

void tooManyRocks() {
    cout << "There are no more rocks in the pile.\n";
    if (!gamestate->hasBoxing() && !gamestate->hasSkymark()) {
        string prompt = "The strange object and the skymark are still there.\n";
        prompt.append("  1. Take the strange object\n");
        prompt.append("  2. Take the skymark\n");
        prompt.append("  3. Continue on path\n");
        int choice = input(3, prompt);
        if (choice == 1) {
            acquireBoxing();
        } else if (choice == 2) {
            acquireSkymark();
        } else {
            advancePath();
        }
    } else if (!gamestate->hasBoxing()) {
            string prompt = "The strange object is still there.\n";
            prompt.append("  1. Take the strange object\n");
            prompt.append("  2. Continue on path\n");
            int choice = input(2, prompt);
            if (choice == 1) {
                acquireBoxing();
            } else {
                advancePath();
            }
    } else if (!gamestate->hasSkymark()) {
        string prompt = "The skymark is still there.\n";
        prompt.append("  1. Take the skymark\n");
        prompt.append("  2. Continue on path\n");
        int choice = input(2, prompt);
        if (choice == 1) {
            acquireSkymark();
        } else {
            advancePath();
        }
    } else {
        advancePath();
    }
}

void advancePath() {
    underConstruction();
}