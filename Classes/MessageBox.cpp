//
//  MessageBox.cpp
//  MyGame
//
//  Created by DuyTT on 12/31/14.
//
//

#include "MessageBox.h"
#include "SimpleAudioEngine.h"
#include "CocosGUI.h"


USING_NS_CC;

MessageBox::MessageBox()
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin1 = Director::getInstance()->getVisibleOrigin();
    
    spBackGround = Sprite::create("tl.png");

    Size target = Size(visibleSize.width - 200, visibleSize.height/4);
    Size origin = spBackGround->getContentSize();
    spBackGround->setScale(target.width/origin.width,
                           target.height/origin.height);
    
    
    spBackGround->setPosition(Vec2(visibleSize.width/2,
                                   target.height/2 + 70));
    
    this->addChild(spBackGround);
    
    //

    
    //add sprite next
    

    btNext = MenuItemImage::create(
                                   "next.png",
                                   "next.png",
                                        CC_CALLBACK_1(MessageBox::NextScreen, this));
    
    
    btNext->setPosition(Vec2(visibleSize.width - 200 - btNext->getContentSize().width/2,
                             100 + btNext->getContentSize().height/2));
    CCLOG("BT NEXT... %f %f", btNext->getPosition().x, btNext->getPosition().y);
    
    auto menu_next = Menu::create(btNext, NULL);
    menu_next->setPosition(Vec2::ZERO);
    this->addChild(menu_next, 1);
    
    //add initial message
    auto lbMessage = Label::createWithTTF("まどうしが現れた。\n しりょうが現れた。", "fonts/MS Gothic.ttf", 35);
    lbMessage->setPosition(Vec2::ZERO);
    addChild(lbMessage);
    
}
MessageBox::~MessageBox()
{
    
}

                        
void MessageBox::NextScreen(cocos2d::Ref *pSender)
{
    this->removeFromParent();
}









