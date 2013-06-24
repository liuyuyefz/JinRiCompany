//
//  GRETestAppDelegate.cpp
//  GRETest
//
//  Created by lyy on 13-3-26.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "AppMacros.h"


#include "CompanyInfo.h"
#include "S13News.h"
USING_NS_CC;
using namespace CocosDenshion;
using namespace std;
#define rate_macro 1.5

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
    
    // Set the design resolution
   // pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);//kResolutionExactFit,kResolutionNoBorder,kResolutionShowAll,kResolutionUnKnown
    float rate1 =2.0;
    float rate2 =2.0;
    
    //pEGLView->setDesignResolutionSize(2048/rate1, 1536/rate2, kResolutionShowAll);
    
   
	CCSize frameSize = pEGLView->getFrameSize();
    
    vector<string> searchPath;
    
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);
     
        //pDirector->setContentScaleFactor(MIN(largeResource.size.height/(2048/rate1), largeResource.size.width/(1536/rate2)));
	}
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
       
        //pDirector->setContentScaleFactor(MIN(mediumResource.size.height/(2048/rate1), mediumResource.size.width/(1536/rate2)));
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
	else
    {
        searchPath.push_back(smallResource.directory);
   
        //pDirector->setContentScaleFactor(MIN(smallResource.size.height/(2048/rate1), smallResource.size.width/(1536/rate2)));
    }
 
    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
	
    // turn on display FPS
   // pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    // create a scene. it's an autorelease object
    CCScene *pScene = CompanyInfo::scene();
    
    // run
    pDirector->runWithScene(pScene);
    
    glClearColor(1.0, 1.0, 1.0, 1.0);//changeBackGroundDefautColor
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
