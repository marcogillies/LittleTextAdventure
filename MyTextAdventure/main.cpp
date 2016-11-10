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
#include <algorithm>
using std::string;
using std::vector;

#include "Room.hpp"

vector <Room> rooms;

vector <Room>::iterator findRoom(std::string name){
    auto found = find_if(rooms.begin(), rooms.end(),
                         [name] (Room room){
                             return room.getName() == name;
                         });
    return found;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    rooms.push_back(Room("start", "you are standing on the edge of a deep dark forest"));
    rooms.push_back(Room("dark forest", "it is dark in here"));
    rooms.push_back(Room("clearing", "you see a clearing"));
    rooms.push_back(Room("very dark forest", "its even darker"));
    
    rooms[0].addDoor("stay here", "start");
    rooms[0].addDoor("path into the forest", "dark forest");
    rooms[1].addDoor("go back", "start");
    rooms[1].addDoor("turn left", "clearing");
    rooms[1].addDoor("turn right", "very dark forest");
    rooms[2].addDoor("go back", "dark forest");
    rooms[3].addDoor("go back", "dark forest");

    
    auto currentRoom = rooms.begin();
    
    while (true){
        currentRoom->display();
        
        std::string nextRoomName = currentRoom->makeChoice();
        currentRoom = findRoom(nextRoomName);
    }
    
    rooms.clear();
    
    return 0;
}
