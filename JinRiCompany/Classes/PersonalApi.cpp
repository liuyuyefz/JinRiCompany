//
//  PersonalApi.cpp
//  GreTest
//
//  Created by lyy on 13-6-14.
//
//

#include "PersonalApi.h"


using namespace std;

//c++字符串分割函数
vector<string>PersonalApi::split(string str,string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();
    
    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}


bool PersonalApi::isContantString(string sourceStr,string patternStr)
{
    const char *show;
    
    show=strstr(sourceStr.c_str(),patternStr.c_str());//返回指向第一次出现r位置的指针，如果没找到则返回NULL。
    
    bool isContant;
    if (show == NULL)
    {
        isContant = false;
    }
    else
    {
        isContant = true;
    }
    
    return isContant;
}




//安全字符串复制,附加拷贝0结尾
size_t PersonalApi::SafeStringCopy(void* dest,size_t destLen,const char* src)
{
	size_t stringLen = strlen(src);
	size_t size=min(destLen-1,stringLen);
	memcpy(dest,src,size);
	((char*)dest)[size]='\0';
	return size;
}

void PersonalApi::string_replace(string & strBig, const string & strsrc, const string &strdst)
{
    string::size_type pos=0;
    string::size_type srclen=strsrc.size();
    string::size_type dstlen=strdst.size();
    
    while( (pos=strBig.find(strsrc, pos)) != string::npos)
    {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
}

std::string PersonalApi::convertIntToString (int aNum) //int 转 string
{
    ostringstream oss;
    oss<<aNum;
    return oss.str();
}
int PersonalApi::convertStringToInt (std::string aStr) //string 转 int
{
    return  atoi( aStr.c_str());
}

