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

/*
 * This is an exception that is thrown if there is a problem
 * reading the player profile (i.e. user enters invalid data)
 */
class PlayerLoadException{
    std::string message;
public:
    PlayerLoadException(std::string _message):message(_message){};
    std::string getMessage(){return message;}
};

/*
 *   a player profile
 */
class Player {
    // name of the character
    std::string name;
    // speed attribute (not actually used)
    int speed;
    // strength attribute (not actually used)
    int strength;
    
    // the constructor is private because you create objects
    // using a factory function setUpProfile
    Player(std::string _name, int _speed, int _strength);
public:
    // you can create an empty player with this constructor
    Player():name(""), speed(0), strength(0){};
    
    // a factory function, i.e. a function for
    // creating Player's
    // it is a static function meaning it belongs
    // to the class not an object
    // so you can call it without an object
    static Player setUpProfile();
    
    // get the attributes of the player
    std::string getName(){return name;};
    int getSpeed(){return speed;};
    int getStrength(){return strength;}
    
    // print text describing the player
    void display();
};

#endif /* Player_hpp */
