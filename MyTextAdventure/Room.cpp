//
//  Room.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#include "Room.hpp"
#include <iostream>


// constructor
// name: name of the room
// text: description to be printed when we are in the room
Room::Room(std::string _name, std::string _text)
    :text(_text),
     name(_name){
    
}

// print out the text for this room
void Room::display(){
    std::cout << text << std::endl;
    for(int i = 0; i < doors.size(); i++){
        std::cout << i << ". ";
        doors[i].display();
    }
}

// adds a new door to the room
// Text: description of the direction to go in
// nextRoom: name of the room you get to through this door
void Room::addDoor(std::string text, std::string nextRoom){
    doors.push_back(Door(text, nextRoom));
}

// get the user to choose the next room
std::string Room::makeChoice()
{
    int i = -1;
    std::string input;
    
    // read in the input
    // if it fails to read
    // then reset the input stream
    // and throw an exception
    if(!(std::cin >> input)){
        std::cout << "input error" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        throw InputValueException("Could not read player input");
    }
    
    // if the input is "quit" throw
    // an exception that will trigger
    // the game to quit
    if(input == "quit"){
        throw EndGameException();
    }
    
    // try to convert the input to an int
    // if this fails throw an exception
    try{
        i = stoi(input);
    } catch (std::invalid_argument){
        throw InputValueException("please enter a number");
    }
    
    // if the int is a valid index for the
    // doors array then select that door
    // otherwise throw an exception
    if(i >= 0 && i < doors.size()){
        return doors[i].getRoom();
    } else {
        throw InputValueException("did not recognise the option");
    }
}
