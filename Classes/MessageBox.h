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

class MessageBox : public Node {
private:

    Sprite *spBackGround;
    Label *message;
    MenuItemImage *btNext;
    
public:
    MessageBox();
    virtual ~ MessageBox();
    void NextScreen(Ref* pSender);
    CREATE_FUNC(MessageBox);
};



#endif /* defined(__MyGame__MessageBox__) */
