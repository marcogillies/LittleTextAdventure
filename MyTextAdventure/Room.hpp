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

class InputValueException{
    std::string message;
public:
    InputValueException(std::string _message):message(_message){};
    std::string getMessage(){return message;}
};

class EndGameException{
public:
    EndGameException(){};
};


class Room
{
    std::string name;
    std::string text;
    std::vector <Door> doors;
    
public:
    Room(std::string name, std::string _text);
    
    void addDoor(std::string text, std::string nextRoom);
    void display();
    
    std::string getName(){return name;};
    
    std::string makeChoice();
};

#endif /* Room_hpp */
