//
//  CompanyInfo.cpp
//  GreTest
//
//  Created by lyy on 13-6-23.
//
//

#include "CompanyInfo.h"
#include "AppMacros.h"
#include "ScriptParser.h"
#include "PersonalApi.h"



#define visibleSize CCDirector::sharedDirector()->getVisibleSize()//可视区域size
#define origin CCDirector::sharedDirector()->getVisibleOrigin()//可视区域原点

#define s1FontName_macro "Arial"

#define classPlistName_macro "CompanyInfo"
#define zNum 100
#define btnTag 100


using namespace cocos2d;
using namespace std;
using namespace extension;

CCScene* CompanyInfo::scene()
{
	CCScene * scene = NULL;
	do
	{
		scene = CCScene::create();
		CompanyInfo *layer = CompanyInfo::create();
		scene->addChild(layer);
	} while (0);
    
	return scene;
}

bool CompanyInfo::initInfo2()
{
    bool bRet = false;
	do
	{
        string plistStr = classPlistName_macro;
        plistStr += ".plist";
        plistDic = CCDictionary::createWithContentsOfFile(plistStr.c_str());
        
        selectedScene = 1;
        
        bRet = true;
	} while (0);
    
	return bRet;
}
bool CompanyInfo::setUpSubClass2()
{
	bool bRet = false;
	do
	{
        
        
        CCSprite * showbigPicture = CCSprite::create("S11BigPic.png");
        showbigPicture->setPosition( ScriptParser::getPositionFromPlist(plistDic,"S11BigPic"));
        this->addChild(showbigPicture,zNum);
		
        showPicMap = ScriptParser::getGroupImageFromPlist(plistDic,"scrollPic");
        
        CCSprite * rulerSprite = CCSprite::create(showPicMap["1"].c_str());
        CCSize tableViewSize = CCSizeMake(showbigPicture->getContentSize().width, rulerSprite->getContentSize().height);
        pTableView = CCTableView::create(this, tableViewSize);
		pTableView->setDirection(kCCScrollViewDirectionHorizontal);
		pTableView->setAnchorPoint(ccp(0.0,1.0));
        pTableView->setPosition(ccp(showbigPicture->getPosition().x-showbigPicture->getContentSize().width/2,showbigPicture->getPosition().y-showbigPicture->getContentSize().height/2-110));
		pTableView->setDelegate(this);
		pTableView->setVerticalFillOrder(kCCTableViewFillTopDown);
        this->addChild(pTableView,zNum);
		pTableView->reloadData();
        
        
        map<string, string> naviGroupStrMap =  ScriptParser::getGroupStringFromPlist(plistDic,"leftDownTitle");
        float fontSize = ScriptParser::getFontSizeFromPlist(plistDic,"leftDownTitle");
        CCSize dimensionsSize = ScriptParser::getSizeFromPlist(plistDic,"leftDownTitle");
        float lastLabelHeight;
        float lastLabelPositionY;
        
        int k = 1;
        for (int i=0; i<naviGroupStrMap.size()/2; i++)
        {
            for (int j = 0; j<2; j++)
            {
                const char * labelStr = naviGroupStrMap[PersonalApi::convertIntToString(k)].c_str();
                
                
                CCLabelTTF *pLabel = CCLabelTTF::create(labelStr, s1FontName_macro, fontSize, dimensionsSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
                pLabel->setAnchorPoint(ccp(0.0,1.0));
                pLabel->setPosition(ccp(pTableView->getPosition().x+pTableView->getContentSize().width/2*j,pTableView->getPosition().y-pLabel->getContentSize().height*1.2*i-10));
                pLabel->setColor(ccRED);
                this->addChild(pLabel,zNum);
                
                k++;
            }
        }
        
        
         
        showStrMap = ScriptParser::getGroupStringFromPlist(plistDic,"rightTitleTableView");
        
        const char * titleStr = showStrMap[PersonalApi::convertIntToString(1)].c_str();
        float titleFontSize = ScriptParser::getFontSizeFromPlist(plistDic,"rightFirstTitle");
        CCLabelTTF *titleLabel = CCLabelTTF::create(titleStr, s1FontName_macro, titleFontSize);
        titleLabel->setAnchorPoint(ccp(0.0,0.5));
        CCPoint titleLabelPosition = ScriptParser::getPositionFromPlist(plistDic,"rightTitleTableView");
        titleLabel->setPosition(ccp(titleLabelPosition.x+10,showbigPicture->getPosition().y+showbigPicture->getContentSize().height/2-25));
        titleLabel->setColor(ccRED);
        this->addChild(titleLabel,zNum);
        
        dimensionsSize = ScriptParser::getSizeFromPlist(plistDic,"rightTitleTableView");
        lastLabelHeight = titleLabel->getContentSize().height;
        lastLabelPositionY = titleLabel->getPosition().y;
        
        for (int i  = 1; i<showStrMap.size(); i++)
        {
            CCSprite *pSprite = CCSprite::create("S11triangle.png");
            if (1 == i)
            {
                pSprite->setPosition(ccp(titleLabel->getPosition().x+10,lastLabelPositionY-lastLabelHeight-10));
            }
            else
            {
                pSprite->setPosition(ccp(titleLabel->getPosition().x+10,lastLabelPositionY-lastLabelHeight-20));
            }
            
            this->addChild(pSprite,zNum);
            
         
            string spaceStr = " ";
            string labelNoSpaceStr = showStrMap[PersonalApi::convertIntToString(i+1)];
            for (int j = 0; j<3; j++)
            {
                labelNoSpaceStr = spaceStr + labelNoSpaceStr;
            }
            
            const char * labelStr = labelNoSpaceStr.c_str();
            float fontSize = pSprite->getContentSize().height;
            CCLabelTTF *pLabel = CCLabelTTF::create(labelStr, s1FontName_macro, fontSize, dimensionsSize, kCCTextAlignmentLeft, kCCVerticalTextAlignmentCenter);
            pLabel->setAnchorPoint(ccp(0.0,1.0));
            pLabel->setPosition(ccp(pSprite->getPosition().x-5,pSprite->getPosition().y+10));
            pLabel->setColor(ccBLACK);
            this->addChild(pLabel,zNum);
            
            lastLabelHeight = pLabel->getContentSize().height;
            lastLabelPositionY = pLabel->getPosition().y;
        }
        
        
		bRet = true;
	} while (0);
    
	return bRet;
}

void CompanyInfo::companyMenuCallback(CCObject* pSender)
{
    
    CCMenuItemSprite *aItem = (CCMenuItemSprite *)pSender;
    CCScene *newScene = CCScene::create();
    switch (aItem->getTag())
    {
        case btnTag:
            newScene->addChild(CompanyInfo::create());
            
            break;
        case btnTag+1:
            //newScene->addChild(S3TestMain::create());
            
            break;
            
        default:
            break;
    }
    CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(0.3, newScene));//动画过场
    
}



void CompanyInfo::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLog("cell touched at index: %i", cell->getIdx());
}

CCSize CompanyInfo::tableCellSizeForIndex(CCTableView *table,unsigned int idx)
{
    if (table == pTableView)
    {
        CCSprite *rulerSprite = CCSprite::create(showPicMap[PersonalApi::convertIntToString(idx+1)].c_str());
        return rulerSprite->getContentSize();
    }
    else if(table == pTableView)
    {
        CCSprite *pSprite = CCSprite::create(showPicMap[PersonalApi::convertIntToString(idx+1)].c_str());
        const char * labelStr = showStrMap[PersonalApi::convertIntToString(idx)].c_str();
        float fontSize = pSprite->getContentSize().height;
        CCLabelTTF *pLabel = CCLabelTTF::create(labelStr, s1FontName_macro, fontSize);
        return pLabel->getContentSize();
    }
    
    return CCSizeMake(0,0);
}

CCTableViewCell* CompanyInfo::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    
    CCTableViewCell *pCell = table->dequeueCell();
    if (!pCell)
    {
        
        pCell = new CCTableViewCell();
        pCell->autorelease();
       
            CCSprite *pSprite = CCSprite::create(showPicMap[PersonalApi::convertIntToString(idx+1)].c_str());
            pSprite->setAnchorPoint(CCPointZero);
            pSprite->setTag(123);
            pSprite->setPosition(CCPointZero);
            pCell->addChild(pSprite);

    }
    else
    {
       
            CCSprite *pSprite = (CCSprite*)pCell->getChildByTag(123);
            //cocos2d-x 动态修改图片
            pSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(showPicMap[PersonalApi::convertIntToString(idx+1)].c_str()));

    }
    
    
    return pCell;
}

unsigned int CompanyInfo::numberOfCellsInTableView(CCTableView *table)
{
    return showPicMap.size();
}


