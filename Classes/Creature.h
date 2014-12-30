//
//  Creature.h
//  MyGame
//
//  Created by DuyTT on 12/29/14.
//
//

#ifndef __MyGame__Creature__
#define __MyGame__Creature__

#include "cocos2d.h"
#include <stdio.h>
typedef enum
{
    Player,
    Enemy1,
    Enemy2,
} CreatureType;


class Creature : public cocos2d::Node
{
private:

 
    
    CC_SYNTHESIZE(CreatureType, type, Type);

    void checkDie();
public:
    cocos2d::Sprite * _sprite;
    CC_SYNTHESIZE(int, hp, Hp );
    CC_SYNTHESIZE(int, mp, Mp);
    CC_SYNTHESIZE(int, power, Power);
    CC_SYNTHESIZE(int, physical, Physical);
    CC_SYNTHESIZE(int, quickness, Quickness);
    CC_SYNTHESIZE(int, dexterity, Dexterity);
    CC_SYNTHESIZE(int, cleverness, Cleverness);
    CC_SYNTHESIZE(int, chie, Chie);
    CC_SYNTHESIZE(int, smartness, Smartness);
    CC_SYNTHESIZE(int, strength, Strength);
    CC_SYNTHESIZE(int, charm, Charm);
    Creature();
    
    virtual ~ Creature();
    
    virtual bool init();
    void attack(Creature * otherCreature);
    void die();
    // implement the "static create()" method manually
    CREATE_FUNC(Creature);
};

#endif /* defined(__MyGame__Creature__) */
