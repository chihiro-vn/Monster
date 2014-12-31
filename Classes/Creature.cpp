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
    hp = 100;
    mp = 100;
    power = 100;
    physical = 100;
    quickness = 100;
    dexterity = 100;
    cleverness = 100;
    chie = 100;
    smartness = 100;
    strength = 100;
    charm = 100;
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
    
    otherCreature->setHp(otherCreature->getHp() - this->getMp());
    if (otherCreature->getHp() <= 0)
    {
        otherCreature->setHp(0);
    }
    otherCreature->checkDie();
    
}


void Creature::checkDie()
{
    CCLOG("DISPLAY HP OF ENEMY %f", this->getHp());
    if (this->getHp() <= 0)
    {
        
        //display messgage otherCreate is die
        CCLOG("display message current creature is died");
        die();
        
    }
   
}

void Creature::die()
{
    this->_sprite->setOpacity(0);
}




