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
    
    int currentRoom = 0;
    
    while (true){
        rooms[currentRoom].display();
        
        int i = 0;
        
        if(std::cin >> i){
            if(i == 1){
                if(currentRoom < rooms.size()-1){
                    currentRoom += 1;
                }
            } else if(i == 2) {
                // do nothing
            } else if(i == 3) {
                if(currentRoom > 0){
                    currentRoom -= 1;
                }
            } else {
                std::cout << "please enter 1,2 or 3" << std::endl;
            }
        } else {
            std::cout << "you need to type a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

        }
        
    }
    return 0;
}
