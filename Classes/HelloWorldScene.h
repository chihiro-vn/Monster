#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Creature.h"
#include "Player.h"
#include "Enemy.h"
#include "MonsterBox.h"
#include "MessageBox.h"

class HelloWorld : public cocos2d::Layer, public MessageBoxDelegate
{
public:
    CC_SYNTHESIZE_RETAIN(Creature*, _player, myPlayer);
    CC_SYNTHESIZE_RETAIN(Creature*, _enemy, myEnemy);
    CC_SYNTHESIZE(int, state, State);// 0: intro, 1: turn me or enemy
    class MessageBox *messageBox;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    static cocos2d::Scene* createScene(Creature* player, Creature* enemy);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual bool init(Creature* player, Creature* enemy);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void Play(cocos2d::Ref *pSender);
    void StopMusic(cocos2d::Ref *pSender);
    void PlayMusic(cocos2d::Ref *pSender);
    void Highscores(cocos2d::Ref *pSender);
    
    void PauseMusic(float dt);
    void ResumeMusic(float dt);
    void CreateMenu ();
    
    void ClickMenu(cocos2d::Ref * pSender);
    
    void Update(float var);
    
    void Apply(cocos2d::Ref * pSender);
    
    void DrawEngine(class Creature *myPlayer, class Creature *myEnemy);
    
    virtual void onBtnNextTouch(cocos2d::Ref* pSender);
    
    void CreateMessage(char * sms);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
