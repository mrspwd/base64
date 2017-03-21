#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "base64.h"
#include <vector>
using namespace std;
using namespace cocos2d;

namespace url_encypt
{
	int key[] = { 1,2,3,4,5 };//加密字符

	std::vector<std::string> StringSplit(std::string str, std::string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str += pattern;//扩展字符串以方便操作
		int size = str.size();

		for (int i = 0; i < size; i++)
		{
			pos = str.find(pattern, i);
			if (pos < size)
			{
				std::string s = str.substr(i, pos - i);
				result.push_back(s);
				i = pos + pattern.size() - 1;
			}
		}
		return result;
	}

	//单个字符异或运算
	char MakecodeChar(char c, int key) {
		return c = c^key;
	}
	//单个字符解密
	char CutcodeChar(char c, int key) {
		return c^key;
	}

	//加密
	void Makecode(char *pstr, int *pkey = key) {
		int len = strlen(pstr);//获取长度
		for (int i = 0; i<len; i++)
			*(pstr + i) = MakecodeChar(*(pstr + i), pkey[i % 5]);
	}


	//解密
	void Cutecode(char *pstr, int *pkey = key) {
		int len = strlen(pstr);
		for (int i = 0; i<len; i++)
			*(pstr + i) = CutcodeChar(*(pstr + i), pkey[i % 5]);
	}

	//最终加密方法
	void base64Makecode(char *urls, char **d)
	{
		Makecode(urls);
		base64Encode((unsigned const char*)urls, (unsigned int)strlen(urls) + 1, d);
	}

	//最终解密方法
	void base64Cutecode(char *urls, unsigned char* &c)
	{
		//unsigned char *c = nullptr;
		base64Decode((unsigned const char*)urls, strlen(urls), &c);
		Cutecode((char *)c);
	}

	//解密url并得到其中随机一个 如果未加密则直接返回此url
	string getUrlCodeByRandOne(string xxurl)
	{
		if (xxurl.substr(0, 4) != "http")
		{
			// todo base64解密分割
			unsigned char *b;
			//base64Decode((unsigned const char*)xxurl.c_str(), (unsigned int)xxurl.length(), &b);
			base64Cutecode((char *)xxurl.c_str(), b);
			//base64Encode((unsigned const char*)_packageUrl.c_str(), (unsigned int)_packageUrl.length(), &b);
			xxurl = (char *)b;
			std::vector<std::string> result = StringSplit(xxurl, ",");
			//xxurl = result[random(0, (int)result.size() - 1)];
			
			int a1 = 0;
			int b1 = (int)result.size()-1;
			int idx = a1 + rand() % (b1 - a1 + 1);
			xxurl = result[idx];
		}
		return xxurl;
	}
}


//char urls[1024];
//cin >> urls;
//
//char *d = nullptr;
//url_encypt::base64Makecode(urls, &d);   // 加密
//
//cout << d << endl;
//
//unsigned char *c = nullptr;
//url_encypt::base64Cutecode(d, c);       // 解密
//cout << c << endl;
//
//string xx = url_encypt::getUrlCodeByRandOne(d);  // 直接从加密的url 解密并直接随机获取其中一个地址
//cout << xx.c_str() << endl;