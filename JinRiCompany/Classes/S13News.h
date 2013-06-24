//
//  S13News.h
//  GreTest
//
//  Created by lyy on 13-6-23.
//
//

#ifndef __GreTest__S13News__
#define __GreTest__S13News__

#include "cocos2d.h"
#include <string.h>
#include "cocos-ext.h"

#include "JinRiShangPinScene.h"

class S13News : public JinRiShangPin
{
public:
    static cocos2d::CCScene* scene();
    virtual bool initInfo2();
    virtual bool setUpSubClass2();
    CREATE_FUNC(S13News);
private:
    cocos2d::CCDictionary* plistDic;
    void newsMenuCallback(CCObject* pSender);
    std::map<std::string, std::string> rightBigTitleCnMap;
    std::map<std::string, std::string> rightBigTitleEnMap;
    std::map<std::string, std::string> rightDetailTitleMap;
};

#endif /* defined(__GreTest__S13News__) */
