//
//  S13News.cpp
//  GreTest
//
//  Created by lyy on 13-6-23.
//
//

#include "S13News.h"
#include "AppMacros.h"
#include "ScriptParser.h"
#include "PersonalApi.h"

#include "S13More.h"
#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define s1FontName_macro "Arial"

#define classPlistName_macro "S13News"
#define zNum 100
#define btnTag 100


using namespace cocos2d;
using namespace std;
using namespace extension;

CCScene* S13News::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		S13News *layer = S13News::create();
		scene->addChild(layer);
	} while (0);
    
	return scene;
}

bool S13News::initInfo2()
{
    bool bRet = false;
	do
	{
        string plistStr = classPlistName_macro;
        plistStr += ".plist";
        plistDic = CCDictionary::createWithContentsOfFile(plistStr.c_str());
        selectedScene = 3;
        
        bRet = true;
	} while (0);
    
	return bRet;
}
bool S13News::setUpSubClass2()
{
	bool bRet = false;
	do
	{
        
        
        CCSprite * showbigPicture = CCSprite::create("S13PLeftimg.png");
        showbigPicture->setPosition( ScriptParser::getPositionFromPlist(plistDic,"S13PLeftimg"));
        this->addChild(showbigPicture,zNum);
		
        CCSprite * lineSprite = CCSprite::create("s13PMiddleString.png");
        lineSprite->setPosition( ccp(showbigPicture->getPosition().x+showbigPicture->getContentSize().width/2+20,showbigPicture->getPosition().y-50));
        this->addChild(lineSprite,zNum);
      
        
        rightBigTitleCnMap = ScriptParser::getGroupStringFromPlist(plistDic,"rightBigTitleCn");
        rightBigTitleEnMap = ScriptParser::getGroupStringFromPlist(plistDic,"rightBigTitleEn");
        
        CCPoint titleCnPosition =  CCPointMake(lineSprite->getPosition().x + 10,lineSprite->getPosition().y+lineSprite->getContentSize().height/2-40);

        float lastTitlePositionY = titleCnPosition.y;
        float lastLabelHeight;
        float lastLabelPositionY = titleCnPosition.y;
        
        
        for (int i = 0; i<rightBigTitleCnMap.size(); i++)
        {
            CCSprite * dotTitleLineSprite = CCSprite::create("s131RightWordBottom.png");
            
            //
            const char * titleCnStr = rightBigTitleCnMap[PersonalApi::convertIntToString(i+1)].c_str();
            float titleCnFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"titleCnFontSize");
            CCSize titleCnSize = CCSizeMake(dotTitleLineSprite->getContentSize().width, titleCnFontSize);
            CCLabelTTF *titleCnLabel = CCLabelTTF::create(titleCnStr, s1FontName_macro, titleCnFontSize,titleCnSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
            titleCnLabel->setAnchorPoint(ccp(0.0,0.5));
            titleCnLabel->setPosition(ccp(titleCnPosition.x,lastTitlePositionY));
            titleCnLabel->setColor(ccBLACK);
            this->addChild(titleCnLabel,zNum);
            
            //
            const char * titleEnStr = rightBigTitleEnMap[PersonalApi::convertIntToString(1)].c_str();
            float titleEnFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"titleEnFontSize");
            CCSize titleEnSize = CCSizeMake(dotTitleLineSprite->getContentSize().width, titleCnFontSize);
            CCLabelTTF *titleEnLabel = CCLabelTTF::create(titleEnStr, s1FontName_macro, titleEnFontSize,titleEnSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
            titleEnLabel->setAnchorPoint(ccp(0.0,0.5));
            titleEnLabel->setPosition(ccp(titleCnLabel->getPosition().x+100,titleCnLabel->getPosition().y));
            titleEnLabel->setColor(ccGRAY);
            this->addChild(titleEnLabel,zNum);
            
            //
           float moreFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"moreFontSize");
            CCLabelTTF *moreLabel = CCLabelTTF::create("more", s1FontName_macro, moreFontSize);
            moreLabel->setPosition(ccp(titleCnLabel->getPosition().x+dotTitleLineSprite->getContentSize().width/1.1,titleCnLabel->getPosition().y-5));
            moreLabel->setColor(ccRED);
            this->addChild(moreLabel,zNum+1);
            {
            CCSprite * sprite1 = CCSprite::create();
			CCSprite * sprite2 = CCSprite::create();
            
			CCMenuItemSprite *aItem = CCMenuItemSprite::create(
                                                               sprite1,
                                                               sprite2,
                                                               this,
                                                               menu_selector(S13News::newsMenuCallback));
			aItem->setPosition(moreLabel->getPosition());
            aItem->setContentSize(moreLabel->getContentSize());
            aItem->setTag(btnTag+100+i);
			_menu ->addChild(aItem,zNum);
            }
            //
            
            
            lastLabelHeight  = titleCnLabel->getContentSize().height;
            lastLabelPositionY = titleCnLabel->getPosition().y-40;
            dotTitleLineSprite->setPosition(ccp(titleCnLabel->getPosition().x + dotTitleLineSprite->getContentSize().width/2,titleCnLabel->getPosition().y-titleCnLabel->getContentSize().height+5));
            this->addChild(dotTitleLineSprite,zNum);
            
            const string rightDetailTitle = "rightTitleDetail"+PersonalApi::convertIntToString(i+1);
            rightDetailTitleMap = ScriptParser::getGroupStringFromPlist(plistDic,rightDetailTitle);
            for (int j  = 0; j<rightDetailTitleMap.size(); j++)
            {
                CCSprite *detailSprite = CCSprite::create("S13PRightPoint.png");
                detailSprite->setPosition(ccp(titleCnLabel->getPosition().x,lastLabelPositionY-lastLabelHeight-20));
                this->addChild(detailSprite,zNum);
               
                const char * titleDetailLabelStr = rightDetailTitleMap[PersonalApi::convertIntToString(j+1)].c_str();
                float titleDetailFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"titleDetailFontSize");
                CCSize titleDetailSize = CCSizeMake(dotTitleLineSprite->getContentSize().width, titleCnFontSize);
                CCLabelTTF *titleDetailLabel = CCLabelTTF::create(titleDetailLabelStr, s1FontName_macro, titleDetailFontSize, titleDetailSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
                titleDetailLabel->setAnchorPoint(ccp(0.0,1.0));
                titleDetailLabel->setPosition(ccp(detailSprite->getPosition().x+5,detailSprite->getPosition().y+10));
                titleDetailLabel->setColor(ccBLACK);
                this->addChild(titleDetailLabel,zNum);
                
                lastLabelHeight = titleDetailLabel->getContentSize().height;
                lastLabelPositionY = titleDetailLabel->getPosition().y;
                
                if (j == rightDetailTitleMap.size()-1)
                {
                    
                    lastTitlePositionY = titleDetailLabel->getPosition().y-80;
                }
                {
                CCSprite * sprite1 = CCSprite::create();
                CCSprite * sprite2 = CCSprite::create();
                
                CCMenuItemSprite *aItem = CCMenuItemSprite::create(
                                                                   sprite1,
                                                                   sprite2,
                                                                   this,
                                                                   menu_selector(S13News::newsMenuCallback));
                aItem->setPosition(titleDetailLabel->getPosition());
                aItem->setContentSize(titleDetailLabel->getContentSize());
                aItem->setTag(btnTag+i);
                _menu ->addChild(aItem,zNum);
                }
                CCSprite * dotDetailTitleLineSprite = CCSprite::create("s131RightWordBottom.png");
                dotDetailTitleLineSprite->setPosition(ccp(titleDetailLabel->getPosition().x + dotDetailTitleLineSprite->getContentSize().width/2,titleDetailLabel->getPosition().y-titleDetailLabel->getContentSize().height-5));
                this->addChild(dotDetailTitleLineSprite,zNum);
     
            }
            
        }
        
        
        
		bRet = true;
	} while (0);
    
	return bRet;
}

void S13News::newsMenuCallback(CCObject* pSender)
{
    CCMenuItemSprite *aItem = (CCMenuItemSprite *)pSender;
    CCScene *newScene = CCScene::create();
    newScene->addChild(S13More::create());
    
    switch (aItem->getTag())
    {
        case btnTag:
            newScene->addChild(S13More::create());
            
            break;
        case btnTag+1:
            newScene->addChild(S13More::create());
            
            break;
            
        default:
            break;
    }
    CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.3, newScene));//动画过场
    
}



