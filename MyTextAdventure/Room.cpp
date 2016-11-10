//
//  Room.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Room.hpp"
#include <iostream>


Room::Room(std::string _text, int _id)
    :text(_text),
     id(_id){
    
}

void Room::display(){
    std::cout << text << std::endl;
    for(int i = 0; i < doors.size(); i++){
        std::cout << i << ". ";
        doors[i].display();
    }
}

void Room::addDoor(std::string text, int nextRoom){
    doors.push_back(Door(text, nextRoom));
}

int Room::makeChoice()
{
    int i = -1;
    
    if(!(std::cin >> i)){
        std::cout << "could not understand" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return id;
    }
    
    if(i >= 0 && i < doors.size()){
        return doors[i].getRoom();
    } else {
        return id;
    }
}
