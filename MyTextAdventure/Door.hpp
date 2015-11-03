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

class Door {
    std::string text;
    Room *nextRoom;
    
public:
    Door(std::string _text, Room *_nextRoom);
    
    void display();
    Room * getRoom();
};


#endif /* Door_hpp */
