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
    this->setContentSize(Size(250, 350));
    
    //set background
    
//    myenemy = Enemy::create();
    
    spBackGround = Sprite::create("tl.png");
    Size target = Size(250, 350);
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
    lbname = Label::createWithTTF("ななし", "fonts/MS Gothic.ttf", 30);
    lbname->setPosition(this->getContentSize().width/2, this->getContentSize().height - lbname->getContentSize().height/2);
                        
    
    this->addChild(lbname);
    
    char text[256];
    char text1[256];
    char text2[256];
    char text3[256];
    char text4[256];
    char text5[256];
    char text6[256];
    char text7[256];
    char text8[256];
    
    sprintf(text, "ちから: %d", myenemy.getPower());
    sprintf(text1, "たいりょく: %d", myenemy.getPhysical());
    sprintf(text2, "すばやさ: %d", myenemy.getQuickness());
    sprintf(text3, "きようさ: %d", myenemy.getDexterity());
    sprintf(text4, "かしこさ: %d", myenemy.getCleverness());
    sprintf(text5, "ちえ: %d", myenemy.getChie());
    sprintf(text6, "かっこうさ: %d", myenemy.getSmartness());
    sprintf(text7, "つよさ: %d", myenemy.getStrength());
    sprintf(text8, "まもり: %d", myenemy.getCharm());
    
    lbPower = Label::createWithTTF(text, "fonts/MS Gothic.ttf", 24);
    lbPhysical = Label::createWithTTF(text1, "fonts/MS Gothic.ttf", 24);
    lbQuickness = Label::createWithTTF(text2, "fonts/MS Gothic.ttf", 24);
    lbDexterity = Label::createWithTTF(text3, "fonts/MS Gothic.ttf", 24);
    lbCleverness = Label::createWithTTF(text4, "fonts/MS Gothic.ttf", 24);
    lbChie = Label::createWithTTF(text5, "fonts/MS Gothic.ttf", 24);
    lbSmartness = Label::createWithTTF(text6, "fonts/MS Gothic.ttf", 24);
    lbStrength = Label::createWithTTF(text7, "fonts/MS Gothic.ttf", 24);
    lbCharm = Label::createWithTTF(text8, "fonts/MS Gothic.ttf", 24);

    int dis = 25;
    
    Array * arr = cocos2d::Array::create();
    arr->addObject(lbPower);
    arr->addObject(lbPhysical);
    arr->addObject(lbQuickness);
    arr->addObject(lbDexterity);
    arr->addObject(lbCleverness);
    arr->addObject(lbChie);
    arr->addObject(lbSmartness);
    arr->addObject(lbStrength);
    arr->addObject(lbCharm);
    

    myenemy.getPower();
    CCLOG("SIZE OF ARRAY: %zd", arr->count());
    //set position and update text label for each array
    for (int i = 0; i < arr->count(); i++)
    {
        Label *lbtemp = (Label *) arr->getObjectAtIndex(i);
        lbtemp->setAnchorPoint(Vec2(1, 0.5));
        lbtemp->setPosition(Vec2(this->getContentSize().width - 20,
                             lbname->getPosition().y - dis*(i+1) - lbtemp->getContentSize().height/2));
        
        addChild(lbtemp);
    
        
    }

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