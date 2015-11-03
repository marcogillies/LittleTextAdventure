//
//  main.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include "Room.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector <Room *> rooms;
    rooms.push_back(new Room("you are standing on the edge of a deep dark forest"));
    rooms.push_back(new Room("it is dark in here"));
    rooms.push_back(new Room("you see a clearing"));
    rooms.push_back(new Room("its even darker"));
    
    rooms[0]->addDoor("stay here", rooms[0]);
    rooms[0]->addDoor("path into the forest", rooms[1]);
    rooms[1]->addDoor("go back", rooms[0]);
    rooms[1]->addDoor("turn left", rooms[2]);
    rooms[1]->addDoor("turn right", rooms[3]);
    rooms[2]->addDoor("go back", rooms[1]);
    rooms[3]->addDoor("go back", rooms[1]);

    
    Room *currentRoom = rooms[0];
    
    while (true){
        currentRoom->display();
        
        currentRoom = currentRoom->makeChoice();
        
        
        // if you return nullptr
        //Room *i = currentRoom->makeChoice();
        
        //if (i != nullptr){
        //    currentRoom = i;
        //} else {
        //    std::cout << "error!";
        //}
        
        //if(i >= 0 && i < rooms.size()){
        //    currentRoom = i;
        //}
    }
    
    for(int i = 0; i < rooms.size(); i++){
        delete rooms[i];
    }
    rooms.clear();
    
    return 0;
}
