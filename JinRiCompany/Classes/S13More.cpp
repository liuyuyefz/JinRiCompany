//
//  S13More.cpp
//  GreTest
//
//  Created by lyy on 13-6-24.
//
//

#include "S13More.h"
#include "AppMacros.h"
#include "ScriptParser.h"
#include "PersonalApi.h"


#include "S13News.h"
#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define s1FontName_macro "Arial"

#define classPlistName_macro "S13More"
#define zNum 100
#define btnTag 100


using namespace cocos2d;
using namespace std;
using namespace extension;

CCScene* S13More::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		S13More *layer = S13More::create();
		scene->addChild(layer);
	} while (0);
    
	return scene;
}

bool S13More::initInfo2()
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
bool S13More::setUpSubClass2()
{
	bool bRet = false;
	do
	{
        
        float dateFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"date");
        const char * dateLabelStr = ScriptParser::getStringFromPlist(plistDic,"date");
        
        CCLabelTTF *dateTitleLabel = CCLabelTTF::create(dateLabelStr, s1FontName_macro, dateFontSize);
        dateTitleLabel->setAnchorPoint(ccp(0.0,1.0));
        dateTitleLabel->setPosition(ScriptParser::getPositionFromPlist(plistDic,"date"));
        dateTitleLabel->setColor(ccGRAY);
        this->addChild(dateTitleLabel,zNum);
        
        
        float titleFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"title");
        const char * titleLabelStr = ScriptParser::getStringFromPlist(plistDic,"title");
        
        CCLabelTTF *titleLabel = CCLabelTTF::create(titleLabelStr, s1FontName_macro, titleFontSize);
        titleLabel->setAnchorPoint(ccp(0.0,1.0));
        titleLabel->setPosition(ScriptParser::getPositionFromPlist(plistDic,"title"));
        titleLabel->setColor(ccBLACK);
        this->addChild(titleLabel,zNum);
        
        {
            CCSprite * aSprite = CCSprite::create("PBackBtn.png");
            aSprite->setPosition( ScriptParser::getPositionFromPlist(plistDic,"PBackBtn"));
            this->addChild(aSprite,zNum);
            
            CCSprite * sprite1 = CCSprite::create();
            CCSprite * sprite2 = CCSprite::create();
            
            CCMenuItemSprite *aItem = CCMenuItemSprite::create(
                                                               sprite1,
                                                               sprite2,
                                                               this,
                                                               menu_selector(S13More::moreMenuCallback));
            aItem->setPosition(aSprite->getPosition());
            aItem->setContentSize(aSprite->getContentSize());
            aItem->setTag(btnTag);
            _menu ->addChild(aItem,zNum);
        }
        CCSprite * showbigPicture = CCSprite::create("s133LeftBigImg.png");
        showbigPicture->setPosition( ScriptParser::getPositionFromPlist(plistDic,"s133LeftBigImg"));
        this->addChild(showbigPicture,zNum);
		
        
        
        float detailFontSize1 = ScriptParser::getFontSizeFromPlist(plistDic,"detailStr");
        CCSize detailDimensionsSize1 = ScriptParser::getSizeFromPlist(plistDic,"detailStr1");
        const char * detailLabelStr1 = ScriptParser::getStringFromPlist(plistDic,"detailStr1");
        
        
        CCLabelTTF *detailLabel1 = CCLabelTTF::create(detailLabelStr1, s1FontName_macro, detailFontSize1, detailDimensionsSize1, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
        detailLabel1->setAnchorPoint(ccp(0.0,1.0));
        detailLabel1->setPosition(ScriptParser::getPositionFromPlist(plistDic,"detailStr1"));
        detailLabel1->setColor(ccBLACK);
        this->addChild(detailLabel1,zNum);
        
        
        float detailFontSize2 = ScriptParser::getFontSizeFromPlist(plistDic,"detailStr");
        CCSize detailDimensionsSize2 = ScriptParser::getSizeFromPlist(plistDic,"detailStr2");
        const char * detailLabelStr2 = ScriptParser::getStringFromPlist(plistDic,"detailStr2");
        
        
        CCLabelTTF *detailLabel2 = CCLabelTTF::create(detailLabelStr2, s1FontName_macro, detailFontSize2, detailDimensionsSize2, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
        detailLabel2->setAnchorPoint(ccp(0.0,1.0));
        detailLabel2->setPosition(ScriptParser::getPositionFromPlist(plistDic,"detailStr2"));
        detailLabel2->setColor(ccBLACK);
        this->addChild(detailLabel2,zNum);
        
     
        
        {
            CCSprite * aSprite = CCSprite::create("PPreBtn.png");
            aSprite->setPosition( ScriptParser::getPositionFromPlist(plistDic,"PPreBtn"));
            this->addChild(aSprite,zNum);
            
            CCSprite * sprite1 = CCSprite::create();
            CCSprite * sprite2 = CCSprite::create();
            
            CCMenuItemSprite *aItem = CCMenuItemSprite::create(
                                                               sprite1,
                                                               sprite2,
                                                               this,
                                                               menu_selector(S13More::moreMenuCallback));
            aItem->setPosition(aSprite->getPosition());
            aItem->setContentSize(aSprite->getContentSize());
            aItem->setTag(btnTag+1);
            _menu ->addChild(aItem,zNum);
        }
        
        {
            CCSprite * aSprite = CCSprite::create("PNextBtn.png");
            aSprite->setPosition( ScriptParser::getPositionFromPlist(plistDic,"PNextBtn"));
            this->addChild(aSprite,zNum);
            
            CCSprite * sprite1 = CCSprite::create();
            CCSprite * sprite2 = CCSprite::create();
            
            CCMenuItemSprite *aItem = CCMenuItemSprite::create(
                                                               sprite1,
                                                               sprite2,
                                                               this,
                                                               menu_selector(S13More::moreMenuCallback));
            aItem->setPosition(aSprite->getPosition());
            aItem->setContentSize(aSprite->getContentSize());
            aItem->setTag(btnTag+1);
            _menu ->addChild(aItem,zNum);
        }
        
        
		bRet = true;
	} while (0);
    
	return bRet;
}

void S13More::moreMenuCallback(CCObject* pSender)
{
    CCMenuItemSprite *aItem = (CCMenuItemSprite *)pSender;
    CCScene *newScene = CCScene::create();
    switch (aItem->getTag())
    {
        case btnTag:
            newScene->addChild(S13News::create());
            
            break;
        case btnTag+1:
           // newScene->addChild(S3TestMain::create());
            
            break;
            
        default:
            break;
    }
    CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.3, newScene));//动画过场
    
}
