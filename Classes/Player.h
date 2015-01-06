//
//  Player.h
//  MyGame
//
//  Created by DuyTT on 12/29/14.
//
//

#ifndef __MyGame__Player__
#define __MyGame__Player__

#include "Creature.h"
#include "cocos2d.h"

class Player : public Creature
{

public:
    Player();
    virtual ~ Player();
    
    // implement the "static create()" method manually
};

#endif /* defined(__MyGame__Player__) */
