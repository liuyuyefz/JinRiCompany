#ifndef __S1MAIN_SCENE_H__
#define __S1MAIN_SCENE_H__

#include "cocos2d.h"
#include <string.h>

class S1Main : public cocos2d::CCLayer
{
public:
    virtual bool init();
    cocos2d::CCMenu* _menu;
    virtual bool initInfo(){return 0;};
    virtual bool setUpSubClass(){return 0;};
 
private:
    
    cocos2d::CCDictionary* plistDic;
    cocos2d::CCLabelTTF *titleLabel;
    void menuCallback(CCObject* pSender);
   
};

#endif  // __HELLOWORLD_SCENE_H__
