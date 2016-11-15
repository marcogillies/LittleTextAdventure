//
//  Door.hpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 03/11/2015.
//  Copyright © 2015 Marco Gillies. All rights reserved.
//

#ifndef Door_hpp
#define Door_hpp

#include <stdio.h>
#include <string>
class Room;

/*
 * A door allows you to move from one room to another
 */
class Door {
    // description of the door (i.e. the direction it goes in)
    std::string text;
    // the name of the room to move to
    std::string nextRoom;
    
public:
    // constructor
    // _text: description of the door (i.e. the direction it goes in)
    // _nextRoom: the name of the room to move to
    Door(std::string _text, std::string _nextRoom);
    
    // print out the text of the room
    void display();
    
    // get the name of the room to move to
    std::string getRoom();
};


#endif /* Door_hpp */
