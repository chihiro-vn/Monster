//
//  MonsterBox.h
//  MyGame
//
//  Created by DuyTT on 12/30/14.
//
//

#ifndef __MyGame__MonsterBox__
#define __MyGame__MonsterBox__

#include <stdio.h>
#include <cocos2d.h>
#include "Player.h"
#include "Enemy.h"

USING_NS_CC;

class MonsterBox : public Node {
private:
    class Enemy myenemy;
    
    Sprite *spBackGround;
    Sprite *spSepLine;
    Label *lbname;
//    Label *lbPower;
//    Label *lbPhysical;
//    Label *lbQuickness;
//    Label *lbDexterity;
//    Label *lbCleverness;
//    Label *lbChie;
//    Label *lbSmartness;
//    Label *lbStrength;
//    Label *lbCharm;
public:
    MonsterBox();
    virtual ~ MonsterBox();
    void drawMonsterBox(class Enemy * _enemy);
    
    void setMyEnemy(Enemy enemy);
    
    CREATE_FUNC(MonsterBox);
    
};

#endif /* defined(__MyGame__MonsterBox__) */
