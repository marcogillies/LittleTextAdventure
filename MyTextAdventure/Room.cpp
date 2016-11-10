//
//  Room.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Room.hpp"
#include <iostream>


Room::Room(std::string _name, std::string _text)
    :text(_text),
     name(_name){
    
}

void Room::display(){
    std::cout << text << std::endl;
    for(int i = 0; i < doors.size(); i++){
        std::cout << i << ". ";
        doors[i].display();
    }
}

void Room::addDoor(std::string text, std::string nextRoom){
    doors.push_back(Door(text, nextRoom));
}

std::string Room::makeChoice()
{
    int i = -1;
    std::string input;
    
    if(!(std::cin >> input)){
        std::cout << "input error" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw InputValueException("Could not read player input");
    }
    
    if(input == "quit"){
        throw EndGameException();
    }
    
    try{
        i = stoi(input);
    } catch (std::invalid_argument){
        throw InputValueException("please enter a number");
    }
    
    if(i >= 0 && i < doors.size()){
        return doors[i].getRoom();
    } else {
        throw InputValueException("did not recognise the option");
    }
}
