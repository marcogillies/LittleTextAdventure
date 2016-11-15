//
//  Player.cpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 10/11/2016.
//  Copyright © 2016 Marco Gillies. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

// the private constructor
Player::Player(std::string _name, int _speed, int _strength)
:name(_name), speed(_speed), strength(_strength)
{
    
}

// prompt the user for the data about thee player
Player Player::setUpProfile(){
    std::string _name;
    int _speed;
    int _strength;
    
    // try to read in the name and if it fails
    // throw an exception
    // (unlikely to fail)
    std::cout << "Enter Name:" << std::endl;
    if(!(std::cin >> _name)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("could not read name");
    }
    
    // try to read in the speed and if it fails
    // throw an exception
    // will fail if the text entered does not correspond to an integer
    std::cout << "Enter Speed:" << std::endl;
    if(!(std::cin >> _speed)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("speed must be a whole number");
    }
    
    // try to read in the strength and if it fails
    // throw an exception
    // will fail if the text entered does not correspond to an integer
    std::cout << "Enter Strength:" << std::endl;
    if(!(std::cin >> _strength)){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw PlayerLoadException("strength must be a whole number");
    }
    
    // speed and strength have to be positive
    if(_speed < 0){
        throw PlayerLoadException("speed must be a positive number");
    }
    if(_strength < 0){
        throw PlayerLoadException("strength must be a positive number");
    }
    
    // don't make the character too powerful
    // make sure the speed and strength add up to 10 or less
    if(_strength + _speed > 10){
        throw PlayerLoadException("strength and speed must add up to less than 10");
    }
    
    return Player(_name, _speed, _strength);
}

// print text describing the player
void Player::display()
{
    std::cout << name << ": " << std::endl;
};
