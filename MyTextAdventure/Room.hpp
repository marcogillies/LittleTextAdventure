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


class Room
{
    std::string text;
public:
    Room(std::string _text);
    void display();
};

#endif /* Room_hpp */
