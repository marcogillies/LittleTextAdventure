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
    std::string nextRoom;
    
public:
    Door(std::string _text, std::string _nextRoom);
    
    void display();
    std::string getRoom();
};


#endif /* Door_hpp */
