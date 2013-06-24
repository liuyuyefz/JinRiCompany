//
//  S13More.h
//  GreTest
//
//  Created by lyy on 13-6-24.
//
//

#ifndef __GreTest__S13More__
#define __GreTest__S13More__

#include "cocos2d.h"
#include <string.h>
#include "cocos-ext.h"

#include "JinRiShangPinScene.h"

class S13More : public JinRiShangPin
{
public:
    static cocos2d::CCScene* scene();
    virtual bool initInfo2();
    virtual bool setUpSubClass2();
    CREATE_FUNC(S13More);
private:
    cocos2d::CCDictionary* plistDic;
    std::map<std::string, std::string> titleMap;
    void moreMenuCallback(CCObject* pSender);
};
#endif /* defined(__GreTest__S13More__) */
