//
//  ScriptParser.h
//  GreTest
//
//  Created by lyy on 13-5-3.
//
//

#ifndef __GreTest__ScriptParser__
#define __GreTest__ScriptParser__

#include "PersonalApi.h"
#include "cocos2d.h"
/*
#include<map>
#include<vector>
#include<string>
#include<cstdio>
#include "cocos2d.h"
*/
class ScriptParser
{
public:
	
    static std::string readScript(std::string fileName);
    
    static cocos2d::CCDictionary* readPlist(std::string fileName);
    
    static std::map<std::string, std::string> paserScript(std::string className,std::string mapName);
    
    static std::vector<std::string> traversingMap(std::map<std::string, std::string> aMap);
    
    static cocos2d::CCPoint getPositionFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& positionName);
    
    static cocos2d::CCSize getSizeFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& sizeName);
    
   static float getFontSizeFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& key);
    
    static std::map<std::string, std::string> getStringGroupFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& stringSectionName);
    
    static const char* getStringFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& key);
    
    static std::map<std::string,std::string> getGroupStringFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& imageSectionName);
    
    static const char*  getImageFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& key);
    
    static std::map<std::string,std::string> getGroupImageFromPlist(cocos2d::CCDictionary * plistDictionary,const std::string& imageSectionName);
    
};

#endif /* defined(__GreTest__ScriptParser__) */
