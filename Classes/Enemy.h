//
//  Enemy.h
//  MyGame
//
//  Created by DuyTT on 12/29/14.
//
//

#ifndef __MyGame__Enemy__
#define __MyGame__Enemy__

#include <stdio.h>
#include "cocos2d.h"
#include "Creature.h"
USING_NS_CC;

class Enemy : public Creature::Creature
{
public:
    Enemy();
    virtual ~ Enemy();

    
    // implement the "static create()" method manually
};


#endif /* defined(__MyGame__Enemy__) */
