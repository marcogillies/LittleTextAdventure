//
//  Room.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Room.hpp"
#include <iostream>


Room::Room(std::string _text):text(_text){
    
}

void Room::display(){
    std::cout << text << std::endl;
    for(int i = 0; i < doors.size(); i++){
        std::cout << i << ". ";
        doors[i].display();
    }
}

void Room::addDoor(std::string text, Room * nextRoom){
    doors.push_back(Door(text, nextRoom));
}

Room * Room::makeChoice()
{
    int i = -1;
    
    if(!(std::cin >> i)){
        std::cout << "could not understand" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return this;
    }
    
    if(i >= 0 && i < doors.size()){
        return doors[i].getRoom();
    } else {
        return this;
    }
}