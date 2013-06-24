//
//  PersonalApi.h
//  GreTest
//
//  Created by lyy on 13-6-14.
//
//

#ifndef __GreTest__PersonalApi__
#define __GreTest__PersonalApi__

#include<vector>
#include<string>
#include<cstdio>
#include <sstream>

class PersonalApi
{
public:
    
    static std::vector<std::string> split(std::string str,std::string pattern);//字符串分割
    static bool isContantString(std::string sourceStr,std::string patternStr);//判断一个字符串是否包含另外一个
    static size_t SafeStringCopy(void* dest,size_t destLen,const char* src);
    static void string_replace(std::string & strBig, const std::string & strsrc, const std::string &strdst);//字符串替换
    static std::string convertIntToString (int aNum); //int 转 string
    static int convertStringToInt (std::string aStr); //string 转 int
};

#endif /* defined(__GreTest__PersonalApi__) */
