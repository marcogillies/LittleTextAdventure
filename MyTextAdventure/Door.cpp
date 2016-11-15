//
//  Door.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Door.hpp"

#include <iostream>

// constructor
// _text: description of the door (i.e. the direction it goes in)
// _nextRoom: the name of the room to move to
Door::Door(std::string _text, std::string _nextRoom)
    :text(_text), nextRoom(_nextRoom)
{
    
};

// print out the text of the room
void Door::display(){
    std::cout << text << std::endl;
};

// get the name of the room to move to
std::string Door::getRoom(){
    return nextRoom;
};
