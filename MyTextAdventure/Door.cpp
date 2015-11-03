//
//  Door.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Door.hpp"

#include <iostream>

Door::Door(std::string _text, Room *_nextRoom)
    :text(_text), nextRoom(_nextRoom)
{
    
};

void Door::display(){
    std::cout << text << std::endl;
};

Room * Door::getRoom(){
    return nextRoom;
};