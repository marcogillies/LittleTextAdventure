//
//  Room.hpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Door.hpp"


class Room
{
    std::string text;
    std::vector <Door> doors;
    int id;
public:
    Room(std::string _text, int _id);
    
    void addDoor(std::string text, int nextRoom);
    void display();
    
    int makeChoice();
};

#endif /* Room_hpp */
