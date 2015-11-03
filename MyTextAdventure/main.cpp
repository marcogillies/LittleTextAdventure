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
    
    vector <Room> rooms;
    rooms.push_back(Room("you are standing on the edge of a deep dark forest"));
    rooms.push_back(Room("it is dark in here"));
    rooms.push_back(Room("you see a clearing"));
    rooms.push_back(Room("its even darker"));
    
    rooms[0].addDoor("stay here", 0);
    rooms[0].addDoor("path into the forest", 1);
    rooms[1].addDoor("go back", 0);
    rooms[1].addDoor("turn left", 2);
    rooms[1].addDoor("turn right", 3);
    rooms[2].addDoor("go back", 1);
    rooms[3].addDoor("go back", 1);

    
    int currentRoom = 0;
    
    while (true){
        rooms[currentRoom].display();
        
        int i = rooms[currentRoom].makeChoice();
        
        if(i >= 0 && i < rooms.size()){
            currentRoom = i;
        }
    }
    return 0;
}
