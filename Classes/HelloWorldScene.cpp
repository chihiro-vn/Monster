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
    layer->setTag(9999);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

Scene* HelloWorld::createScene(Creature *player, Creature *enemy)
{
    auto scene = Scene::create();
    auto layer = new (std::nothrow) HelloWorld();
    
    
    if(layer && layer->init(player, enemy)) {
        scene->addChild(layer);
        return scene;
    }
    return nullptr;
}

void HelloWorld::onBtnNextTouch(cocos2d::Ref *pSender) {
    
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
    
    schedule(schedule_selector(HelloWorld::update), 0.1f);
    
    return true;
}

bool HelloWorld::init(Creature* player, Creature* enemy) {
    if(!Layer::init()) {
        return false;
    }
    this->setmyPlayer(player);
    this->setmyEnemy(enemy);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    //create monsterbox as information of player
    auto note = MonsterBox::create();
    note->setContentSize(Size(150, 150));
    note->setTag(0);
    this->addChild(note);
    
    
    note->setPosition(Vec2(origin.x + visibleSize.width - note->getContentSize().width - 10,
                           origin.y + visibleSize.height - note->getContentSize().height - 10));
    
    note->drawMonsterBox(player);
    
    //create monsterbox as information of emeny
    auto note2 = MonsterBox::create();
    
    
    note2->setContentSize(Size(150, 150));
    
    note2->setPosition(Vec2(note->getPosition().x - note->getContentSize().width - 30,
                            note->getPosition().y));
    
    note2->setTag(1);
    this->addChild(note2);
    note2->drawMonsterBox(enemy);
    CCLOG("helloworld/ monsterbox. position %f %f: ", note2->getPosition().x, note2->getPosition().y);
    
    
///
    
    //Draw Background
    Sprite * spriteBG = Sprite::create("bg_3.jpg");
    spriteBG->setScale((this->getContentSize().width)/spriteBG->getContentSize().width,
                       (this->getContentSize().height)/spriteBG->getContentSize().height);
    
    spriteBG->setPosition(Vec2(this->getContentSize().width/2,
                               this->getContentSize().height/2 + 100));
    
    addChild(spriteBG);
    //draw 2 sprites
    
    DrawEngine(this->getmyPlayer(), this->getmyEnemy());
    
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
    
    //draw message box
    messageBox = new class MessageBox();
    messageBox->setPosition(Vec2::ZERO);
    messageBox->delegate = this;
    addChild(messageBox);
    
    //display message intro
    this->setState(0);
    char * temp = "ななしが現れた。\n まどうしが現れた。";
    messageBox->Display(temp);
    
    return true;
}

void HelloWorld::ClickMenu(cocos2d::Ref *pSender)
{
    Node * node = (Node *) pSender;
    int tag = node->getTag();
    CCLOG("Click menu item = %d", tag);
    char * sms = NULL;
    if (tag == 0)
    {
   
        this->setState(1); //state attack
        
        messageBox = new class MessageBox();
        messageBox->setPosition(Vec2::ZERO);
        messageBox->delegate = this;
        addChild(messageBox);
//        if (this->getmyPlayer()->checkDie())
//        {
//            sms = "ななしは、なくなる。";
//            this->CreateMessage(sms);
//            
//        }
//        if(this->getmyEnemy()->checkDie())
//        {
//            sms = "まどうしは、なくなる。";
//            this->CreateMessage(sms);
//        }
        if(this->getmyPlayer()->getHp() != 0 && this->getmyEnemy()->getHp() != 0)
        {
            this->getmyPlayer()->attack(this->getmyEnemy());
            sms = "ななしは、まどうしを攻撃した。";
            messageBox->Display(sms);
            //turn base
            if(this->getmyPlayer()->getHp() != 0 && this->getmyEnemy()->getHp() != 0)
            {
                sms = "まどうし、はななしを攻撃した。";
                this->getmyEnemy()->attack(this->getmyPlayer());
                messageBox->Display(sms);
            }
            
            //            messageBox->removeFromParent();
            
            CCLOG("HP of player: %d \n HP of enemy: %d", this->getmyPlayer()->getHp(), this->getmyEnemy()->getHp());
            
            
        }
        
        
//        //loading new menu
//        {
//            Menu * menu = Menu::create();
//            menu->setPosition(Vec2::ZERO);
//            menu->setContentSize(this->getContentSize());
//            addChild(menu);
//            
//            Array * arr = Array::create();
//            arr->addObject(String::create("まどうし"));
//            arr->addObject(String::create("しりょう"));
//           
//            int posX = 420;
//            int posY = 100;
//            int dis = 10;
//            
//            for (int i = 0; i < 2; i++)
//            {
//                String * name = (String *) arr->getObjectAtIndex(i);
//                Label * labelNode = Label::createWithTTF(name->getCString(), "fonts/MS Gothic.ttf", 24);
//                MenuItem * item = MenuItemLabel::create(labelNode, CC_CALLBACK_1(HelloWorld::Apply, this));
//                item->setTag(i);
//                item->setPosition(posX, posY - (item->getContentSize().height + dis)*i);
//                menu->addChild(item);
//                item->setAnchorPoint(ccp(0, 0));
//            }
//
//        }
        
    }
    
}
void HelloWorld::CreateMessage(char * sms)
{
    if (!messageBox)
    {
        messageBox = new class MessageBox();
        messageBox->setPosition(Vec2::ZERO);
        messageBox->delegate = this;
        addChild(messageBox);
    }
    
    sms = "ななしは、なくなる。";
    messageBox->Display(sms);
    //sleep messageBox
//    messageBox->removeFromParent();
    messageBox->pause();
    
}

void HelloWorld::DrawEngine(class Creature *myPlayer, class Creature *myEnemy)
{
    CCLOG("CALL METHOD DRAW ENGINE");
    myPlayer->_sprite->setScale(1.5);
    myEnemy->_sprite->setScale(1.5);
    
    
    myPlayer->_sprite->setPosition(this->getContentSize()/2 - myPlayer->_sprite->getContentSize()/2);
    myPlayer->_sprite->setPosition(Vec2(myPlayer->_sprite->getPosition().x - 100,
                                        myPlayer->_sprite->getPosition().x - 100));
    
    this->addChild(myPlayer->_sprite);

   
    myEnemy->_sprite->setPosition(this->getContentSize()/2 - myEnemy->_sprite->getContentSize()/2);
    myEnemy->_sprite->setPosition(Vec2(myEnemy->_sprite->getPosition().x + 100,
                                        myEnemy->_sprite->getPosition().x - 100));
    addChild(myEnemy->_sprite);
    
    
}

void HelloWorld::Apply(cocos2d::Ref *pSender)
{
//    myplayer->attack(myEnemy1);
    
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
