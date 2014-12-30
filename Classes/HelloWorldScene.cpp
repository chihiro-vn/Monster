#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CocosGUI.h"
#include "Player.h"
#include "Enemy.h"
#include "MonsterBox.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
  
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    
    closeItem->setPosition(Point(origin.x + visibleSize.width/2 - closeItem->getContentSize().width/2,
                                 origin.y + closeItem->getContentSize().height/2));
    auto menu_close = Menu::create(closeItem, NULL);
    menu_close->setPosition(Point::ZERO);
    
    
    this->addChild(menu_close, 1);
    
    Sprite * spriteBG = Sprite::create("bg_3.jpg");
    spriteBG->setScale((this->getContentSize().width)/spriteBG->getContentSize().width,
                     (this->getContentSize().height)/spriteBG->getContentSize().height);
    
    spriteBG->setPosition(Vec2(this->getContentSize().width/2,
                               this->getContentSize().height/2 + 150));

    addChild(spriteBG);
    
    //draw menu item
    Menu * menu = Menu::create();
    menu->setPosition(Vec2::ZERO);
    menu->setContentSize(this->getContentSize());
    addChild(menu);
    
    Array * arr = Array::create();
    arr->addObject(String::create("攻撃"));
    arr->addObject(String::create("魔法"));
    arr->addObject(String::create("逃げる"));
    arr->addObject(String::create("道具"));
    arr->addObject(String::create("守る"));
    
    int posX = 200;
    int posY = 100;
    int dis = 15;
    
    for (int i = 0; i < 5; i++)
    {
        String * name = (String *) arr->getObjectAtIndex(i);
 
        Label * labelNode = Label::createWithTTF(name->getCString(), "fonts/MS Gothic.ttf", 24);
        MenuItem * item = MenuItemLabel::create(labelNode, CC_CALLBACK_1(HelloWorld::ClickMenu, this));
        item->setTag(i);
        if (i >= 3 )
        {
            item->setPosition(posX + 120, posY - (item->getContentSize().height + dis)*(i-3));
        }
        else
            item->setPosition(posX, posY - (item->getContentSize().height + dis)*i);
        menu->addChild(item);
        item->setAnchorPoint(ccp(0, 0));
    }
    
    //draw 1 player and 2 enemy
    // trying to draw
    class Player * myplayer = new class Player ();
    myplayer->_sprite = Sprite::create("player.png");
    
   
    myplayer->_sprite->setPosition(myplayer->_sprite->getContentSize().width/2 + 30,
                                   myplayer->_sprite->getContentSize().height/2 + 30);
    
    addChild(myplayer->_sprite);
    
    class Enemy * myEnemy1 = new class Enemy();
    class Enemy * myEnemy2 = new class Enemy();
    
    myEnemy1->_sprite = Sprite::create("char1.png");
    myEnemy2->_sprite = Sprite::create("char2.png");

    myEnemy1->_sprite->setScale(1.5);
    myEnemy2->_sprite->setScale(1.5);
    
    myEnemy1->_sprite->setPosition(this->getContentSize()/2 - myEnemy1->_sprite->getContentSize()/2);
    myEnemy1->_sprite->setPosition(Vec2(myEnemy1->_sprite->getPosition().x - 100,
                               myEnemy1->_sprite->getPosition().x - 100));
    
    addChild(myEnemy1->_sprite);

    myEnemy2->_sprite->setPosition(this->getContentSize()/2 - myEnemy2->_sprite->getContentSize()/2);
    myEnemy2->_sprite->setPosition(Vec2(myEnemy2->_sprite->getPosition().x + 100,
                               myEnemy2->_sprite->getPosition().x - 100));
    addChild(myEnemy2->_sprite);
    
    
    //draw Monsterbox
    class MonsterBox * myMonsterBox = new class MonsterBox();
    myMonsterBox->setAnchorPoint(Vec2(0, 0));
    myMonsterBox->setPosition(Vec2(this->getContentSize().width - myMonsterBox->getContentSize().width - 10,
                                   this->getContentSize().height - myMonsterBox->getContentSize().height - 10));
    
//    myMonsterBox->setAnchorPoint(Vec2(1, 1));
    addChild(myMonsterBox);
    CCLOG("content size of scene %f %f", this->getContentSize().width,
          this->getContentSize().height);
    
    
    
    return true;
}

void HelloWorld::ClickMenu(cocos2d::Ref *pSender)
{
    Node * node = (Node *) pSender;
    int tag = node->getTag();
    CCLOG("Click menu item = %d", tag);
    
    if (tag == 0)
    {
        //loading new menu
        {
            Menu * menu = Menu::create();
            menu->setPosition(Vec2::ZERO);
            menu->setContentSize(this->getContentSize());
            addChild(menu);
            
            Array * arr = Array::create();
            arr->addObject(String::create("まどうし"));
            arr->addObject(String::create("しりょう"));
           
            int posX = 420;
            int posY = 100;
            int dis = 10;
            
            for (int i = 0; i < 2; i++)
            {
                String * name = (String *) arr->getObjectAtIndex(i);
                Label * labelNode = Label::createWithTTF(name->getCString(), "fonts/MS Gothic.ttf", 24);
                MenuItem * item = MenuItemLabel::create(labelNode, CC_CALLBACK_1(HelloWorld::Apply, this));
                item->setTag(i);
                item->setPosition(posX, posY - (item->getContentSize().height + dis)*i);
                menu->addChild(item);
                item->setAnchorPoint(ccp(0, 0));
            }

        }
        
    }
    
}

void HelloWorld::DrawEngine(CreatureType _type)
{
    Label *labelNode = Label::createWithTTF("ななし-1", "fonts/MS Gothic.ttf", 30);
    labelNode->setPosition(labelNode->getContentSize().width,
                           this->getContentSize().height - 50 - labelNode->getContentSize().height);
    addChild(labelNode);
}

void HelloWorld::Apply(cocos2d::Ref *pSender)
{
    Node * node = (Node *) pSender;
    int tag = node->getTag();
    CCLOG("Click menu item = %d", tag);
  
   
}


void HelloWorld::Update(float var)
{

}


void HelloWorld::CreateMenu()
{
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite* background = Sprite::create("background.png");
    background->setPosition(Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    this->addChild(background, 0);
    
    //add title 0
    //
    auto lb_layer = Label::createWithTTF("Player 001", "fonts/Marker Felt.ttf", 24);
    
    
    lb_layer->setPosition(Point(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height
                                -lb_layer->getContentSize().height));
    
    
    this->addChild(lb_layer, 1);
    
    //create button label
    
    auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemFont::create("Highscores", CC_CALLBACK_1(HelloWorld::Highscores, this));
    auto menu_item_3 = MenuItemFont::create("Play Music", CC_CALLBACK_1(HelloWorld::PlayMusic, this));
    auto menu_item_4 = MenuItemFont::create("Stop Music", CC_CALLBACK_1(HelloWorld::StopMusic, this));
    
    
    //    menu_item_1->setPosition(Point(visibleSize.width/2, (visibleSize.height/5)*4));
    //    menu_item_2->setPosition(Point(visibleSize.width/2, (visibleSize.height/5)*3));
    //    menu_item_3->setPosition(Point(visibleSize.width/2, (visibleSize.height/5)*2));
    
    
    auto menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, menu_item_4, NULL);
    menu->alignItemsVertically();
    
    //    menu->setPosition(Point(0,0));
    this->addChild(menu);
    
    //New button
    
    auto bt = cocos2d::ui::Button::create("CloseNormal.png",
                                          "CloseSelected.png");
    
    bt->setTitleText("Text button");
    
    bt->setPosition(Point(origin.x + visibleSize.width/2 - bt->getContentSize().width/2,
                          origin.y + visibleSize.height - bt->getContentSize().height/2));
    //    bt->addTouchEventListener(CC_CALLBACK_2(cocos2d::ui::Button::TouchEventType, this));
    
    this->addChild(bt);

    
}


void HelloWorld::Play(Ref *pSender)
{

}


void HelloWorld::Highscores(Ref *pSender)
{

    
    log("タップされました。");
}
void HelloWorld::PlayMusic(Ref *pSender)
{
    CCLOG("PlayMusic");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("audio/mainMainMusic.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("audio/mainMainMusic.mp3");
    
    this->scheduleOnce(schedule_selector(HelloWorld::PauseMusic), 5);
    this->scheduleOnce(schedule_selector(HelloWorld::ResumeMusic), 10);
    
}


void HelloWorld::StopMusic(Ref *pSender)
{
    CCLOG("StopMusic");
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void HelloWorld::PauseMusic(float dt)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void HelloWorld::ResumeMusic(float dt)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
