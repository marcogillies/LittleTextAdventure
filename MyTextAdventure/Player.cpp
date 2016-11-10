//
//  Player.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 10/11/2016.
//  Copyright © 2016 Marco Gillies. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

Player::Player(std::string _name, int _speed, int _strength)
:name(_name), speed(_speed), strength(_strength)
{
    
}

Player Player::setUpProfile(){
    std::string _name;
    int _speed;
    int _strength;
    
    std::cout << "Enter Name:" << std::endl;
    if(!(std::cin >> _name)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("could not read name");
    }
    std::cout << "Enter Speed:" << std::endl;
    if(!(std::cin >> _speed)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("speed must be a whole number");
    }
    std::cout << "Enter Strength:" << std::endl;
    if(!(std::cin >> _strength)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("strength must be a whole number");
    }
    
    if(_speed < 0){
        throw PlayerLoadException("speed must be a positive number");
    }
    
    if(_strength < 0){
        throw PlayerLoadException("strength must be a positive number");
    }
    
    if(_strength + _speed > 10){
        throw PlayerLoadException("strength and speed must add up to less than 10");
    }
    
    return Player(_name, _speed, _strength);
}

void Player::display()
{
    std::cout << name << ": " << std::endl;
};
