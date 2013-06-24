//
//  S14Brand.cpp
//  GreTest
//
//  Created by lyy on 13-6-24.
//
//

#include "S14Brand.h"
#include "AppMacros.h"
#include "ScriptParser.h"
#include "PersonalApi.h"



#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define s1FontName_macro "Arial"

#define classPlistName_macro "S14Brand"
#define zNum 100
#define btnTag 100


using namespace cocos2d;
using namespace std;
using namespace extension;

CCScene* S14Brand::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		S14Brand *layer = S14Brand::create();
		scene->addChild(layer);
	} while (0);
    
	return scene;
}

bool S14Brand::initInfo2()
{
    bool bRet = false;
	do
	{
        string plistStr = classPlistName_macro;
        plistStr += ".plist";
        plistDic = CCDictionary::createWithContentsOfFile(plistStr.c_str());
        
        selectedScene = 4;
        
        bRet = true;
	} while (0);
    
	return bRet;
}
bool S14Brand::setUpSubClass2()
{
	bool bRet = false;
	do
	{
        
        
        CCSprite * showbigPicture = CCSprite::create("S14Brand.png");
        showbigPicture->setPosition( ScriptParser::getPositionFromPlist(plistDic,"S14Brand"));
        this->addChild(showbigPicture,zNum);
		
        

        float rightTitleFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"rightTitle");
        CCSize dimensionsSize = ScriptParser::getSizeFromPlist(plistDic,"rightTitle");
        const char * rightTitleLabelStr = ScriptParser::getStringFromPlist(plistDic,"rightTitle");
        
        
        CCLabelTTF *rightTitleLabel = CCLabelTTF::create(rightTitleLabelStr, s1FontName_macro, rightTitleFontSize, dimensionsSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
        rightTitleLabel->setAnchorPoint(ccp(0.0,1.0));
        rightTitleLabel->setPosition(ScriptParser::getPositionFromPlist(plistDic,"rightTitle"));
        rightTitleLabel->setColor(ccRED);
        this->addChild(rightTitleLabel,zNum);
        
        float rightDetailFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"rightTitleDetail");
         const char * rightDetailTitleLabelStr = ScriptParser::getStringFromPlist(plistDic,"rightTitleDetail");
        CCLabelTTF *rightDetailTitleLabel = CCLabelTTF::create(rightDetailTitleLabelStr, s1FontName_macro, rightDetailFontSize, dimensionsSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
        rightDetailTitleLabel->setAnchorPoint(ccp(0.0,1.0));
        rightDetailTitleLabel->setPosition(ccp(rightTitleLabel->getPosition().x,rightTitleLabel->getPosition().y-rightTitleLabel->getContentSize().height/2-60));
        rightDetailTitleLabel->setColor(ccBLACK);
        this->addChild(rightDetailTitleLabel,zNum);
        
        
		bRet = true;
	} while (0);
    
	return bRet;
}

