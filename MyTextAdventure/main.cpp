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
#include "Player.hpp"


// contains all of the rooms in the game
vector <Room> rooms;

// finds a room based on its name
vector <Room>::iterator findRoom(std::string name){
    auto found = find_if(rooms.begin(), rooms.end(),
                         [name] (Room room){
                             return room.getName() == name;
                         });
    return found;
}

int main(int argc, const char * argv[]) {
    
    // create the rooms
    rooms.push_back(Room("start", "you are standing on the edge of a deep dark forest"));
    rooms.push_back(Room("dark forest", "it is dark in here"));
    rooms.push_back(Room("clearing", "you see a clearing"));
    rooms.push_back(Room("very dark forest", "its even darker"));
    
    // add doors between rooms
    rooms[0].addDoor("stay here", "start");
    rooms[0].addDoor("path into the forest", "dark forest");
    rooms[1].addDoor("go back", "start");
    rooms[1].addDoor("turn left", "clearing");
    rooms[1].addDoor("turn right", "very dark forest");
    rooms[2].addDoor("go back", "dark forest");
    rooms[3].addDoor("go back", "dark forest");

    // load the player profile
    // if the profile doesn't load correct (incorrect data entered)
    // then try again, the loop goes on until the profile is loaded
    // correctly
    Player p;
    while (p.getName() == ""){
        try{
            p = Player::setUpProfile();
        } catch (PlayerLoadException &e){
            std::cout << "Please correct the following errors:" << std::endl;
            std::cout << e.getMessage() << std::endl;
        }
    }
    
    // start at the first room in the array
    auto currentRoom = rooms.begin();
    
    // main game loop
    while (true){
        // print text for the player and current room
        p.display();
        currentRoom->display();
        
        // try to get the next room
        // this might throw an exception triggering a quit,
        // if so break out of the loop
        // if the room is not a valid room then print an error
        // and stay where we are
        std::string nextRoomName;
        try{
            nextRoomName = currentRoom->makeChoice();
            currentRoom = findRoom(nextRoomName);
        } catch(EndGameException){
            break;
        } catch (InputValueException &e){
            std::cout << "Error :" << e.getMessage() << std::endl;
        }
    }
    
    rooms.clear();
    
    return 0;
}
