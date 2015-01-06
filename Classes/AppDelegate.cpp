#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    this->setUp();
    auto scene = HelloWorld::createScene(this->myPlayer, this->myEnemy);
   
    // run
    director->runWithScene(scene);
    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::setUp()
{
    myPlayer = new class Player();
    myPlayer->_sprite = Sprite::create("char1.png");
    myPlayer->setHp(1000);
    myPlayer->setMp(1000);
    myPlayer->_sprite->setName("ななし");
    
    myEnemy = new class Enemy();
    myEnemy->_sprite = Sprite::create("char2.png");
    myEnemy->setHp(999);
    myEnemy->setMp(999);
    
    myPlayer->_sprite->setScale(1.5);
    myEnemy->_sprite->setScale(1.5);
    myPlayer->_sprite->setName("まどうし");
    
    CC_SAFE_RETAIN(myPlayer);
    CC_SAFE_RETAIN(myEnemy);
}

