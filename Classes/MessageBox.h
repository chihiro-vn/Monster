//
//  MessageBox.h
//  MyGame
//
//  Created by DuyTT on 12/31/14.
//
//

#ifndef __MyGame__MessageBox__
#define __MyGame__MessageBox__

#include <stdio.h>
#include <cocos2d.h>
#include "Player.h"
#include "Enemy.h"

USING_NS_CC;

class MessageBoxDelegate {
public:
    virtual void onBtnNextTouch(cocos2d::Ref* pSender) = 0;
};

class MessageBox : public Node {
private:

    Sprite *spBackGround;
    Label *message;
    MenuItemImage *btNext;
       
    
public:
    MessageBoxDelegate* delegate;
    MessageBox();
    virtual ~ MessageBox();
    void NextScreen(Ref* pSender);
    void Display(char *sms);

    CREATE_FUNC(MessageBox);
};



#endif /* defined(__MyGame__MessageBox__) */
