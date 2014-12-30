//
//  Creature.cpp
//  MyGame
//
//  Created by DuyTT on 12/29/14.
//
//

#include "Creature.h"

USING_NS_CC;


Creature::Creature()
{
    _sprite = NULL;
    hp = 0;
    mp = 0;
    power = 0;
    physical = 0;
    quickness = 0;
    dexterity = 0;
    cleverness = 0;
    chie = 0;
    smartness = 0;
    strength = 0;
    charm = 0;
}
Creature::~Creature()
{
    
}

bool Creature::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Creature::init() )
    {
        return false;
    }
    return true;
    
}

void Creature::attack(Creature *otherCreature)
{
    otherCreature->setHp(otherCreature->getHp() - getMp());
    if (otherCreature->getHp() <= 0)
    {
        otherCreature->setHp(0);
    }
    otherCreature->checkDie();
    
}


void Creature::checkDie()
{
    if (this->getHp() <= 0)
        //display messgage otherCreate is die
        CCLOG("display message current creature is died");
   
}

void Creature::die()
{
    this->_sprite->setOpacity(0);
}




