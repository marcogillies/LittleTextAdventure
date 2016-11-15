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

// this is an exception that is triggered
// if the player chooses something that isn't a
// valid next room
class InputValueException{
    std::string message;
public:
    InputValueException(std::string _message):message(_message){};
    std::string getMessage(){return message;}
};

// this is an exception that is triggered if the player quits the game
class EndGameException{
public:
    EndGameException(){};
};

/*
 * This class represents a location in the game
 */
class Room
{
    // name of the location
    std::string name;
    // the description to be printed
    std::string text;
    // doors are ways of movin to the next room
    std::vector <Door> doors;
    
public:
    // constructor
    // name: name of the room
    // text: description to be printed when we are in the room
    Room(std::string name, std::string _text);
    
    // adds a new door to the room
    // Text: description of the direction to go in
    // nextRoom: name of the room you get to through this door
    void addDoor(std::string text, std::string nextRoom);
    
    // print out the text for this room
    void display();
    
    // get the room name
    std::string getName(){return name;};
    
    // get the user to choose the next room
    std::string makeChoice();
};

#endif /* Room_hpp */
