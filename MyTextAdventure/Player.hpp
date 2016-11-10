//
//  Player.hpp
//  MyTextAdventure
//
//  Created by Marco Gillies on 10/11/2016.
//  Copyright © 2016 Marco Gillies. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>

class PlayerLoadException{
    std::string message;
public:
    PlayerLoadException(std::string _message):message(_message){};
    std::string getMessage(){return message;}
};

class Player {
    std::string name;
    int speed;
    int strength;
    
    Player(std::string _name, int _speed, int _strength);
public:
    Player():name(""), speed(0), strength(0){};
    
    static Player setUpProfile();
    
    std::string getName(){return name;};
    int getSpeed(){return speed;};
    int getStrength(){return strength;}
    
    void display();
};

#endif /* Player_hpp */
