//
//  MonsterBox.cpp
//  MyGame
//
//  Created by DuyTT on 12/30/14.
//
//

#include "MonsterBox.h"

USING_NS_CC;


MonsterBox::MonsterBox() : Node()
{
    this->setContentSize(Size(300, 400));
    
    //set background
    spBackGround = Sprite::create("tl.png");
    Size target = Size(300, 400);
    Size origin = spBackGround->getContentSize();
    spBackGround->setScale(target.width/origin.width,
                           target.height/origin.height);
    spBackGround->setPosition(Vec2(150, 200));
    this->addChild(spBackGround);
    //set sepline
    
    spSepLine = Sprite::create();
    spSepLine->setColor(Color3B::WHITE);
    spSepLine->setContentSize(Size(100, 400));
    spSepLine->setPosition(this->getContentSize().width/2,
                           this->getContentSize().height - spSepLine->getContentSize().height/2 - 30);
    this->addChild(spSepLine);
    
    //set lbname
    lbname = Label::createWithTTF("ななし: 0", "fonts/MS Gothic.ttf", 24);
    lbname->setPosition(this->getContentSize().width/2, this->getContentSize().height - lbname->getContentSize().height/2);
                        
    
    this->addChild(lbname);
    
//    lbPhysical = NULL;
//    lbQuickness = NULL;
//    lbDexterity = NULL;
//    lbCleverness = NULL;
//    lbChie = NULL;
//    lbSmartness = NULL;
//    lbStrength = NULL;
//    lbCharm = NULL;
}

MonsterBox::~MonsterBox()
{
    
}

void MonsterBox::setMyEnemy(Enemy enemy) {
    // to set new property to Enemy such as power, cleverness, ...
//    myenemy = enemy;
}

void MonsterBox::drawMonsterBox(class Enemy * _enemy)
{
    Array * arr = Array::create();
    arr->addObject(String::create("ちから"));
    arr->addObject(String::create("たいりょく"));
    arr->addObject(String::create("すばやさ"));
    arr->addObject(String::create("きようさ"));
    arr->addObject(String::create("かしこさ"));
    arr->addObject(String::create("ちえ"));
    arr->addObject(String::create("かっこうさ"));
    arr->addObject(String::create("つよさ"));
    arr->addObject(String::create("まもり"));
    
   
}