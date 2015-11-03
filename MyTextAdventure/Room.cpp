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
    std::cout << "1. go back " << std::endl;
    std::cout << "2. stay here " << std::endl;
    std::cout << "3. go onwards " << std::endl;
}