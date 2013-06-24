//
//  S14Brand.h
//  GreTest
//
//  Created by lyy on 13-6-24.
//
//

#ifndef __GreTest__S14Brand__
#define __GreTest__S14Brand__

#include "cocos2d.h"
#include <string.h>
#include "cocos-ext.h"

#include "JinRiShangPinScene.h"

class S14Brand : public JinRiShangPin
{
public:
    static cocos2d::CCScene* scene();
    virtual bool initInfo2();
    virtual bool setUpSubClass2();
    CREATE_FUNC(S14Brand);
private:
    cocos2d::CCDictionary* plistDic;
    std::map<std::string, std::string> titleMap;
};
#endif /* defined(__GreTest__S14Brand__) */
