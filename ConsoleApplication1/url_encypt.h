#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "base64.h"
#include <vector>
using namespace std;
using namespace cocos2d;

namespace url_encypt
{
	int key[] = { 1,2,3,4,5 };//�����ַ�

	std::vector<std::string> StringSplit(std::string str, std::string pattern)
	{
		std::string::size_type pos;
		std::vector<std::string> result;
		str += pattern;//��չ�ַ����Է������
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

	//�����ַ��������
	char MakecodeChar(char c, int key) {
		return c = c^key;
	}
	//�����ַ�����
	char CutcodeChar(char c, int key) {
		return c^key;
	}

	//����
	void Makecode(char *pstr, int *pkey = key) {
		int len = strlen(pstr);//��ȡ����
		for (int i = 0; i<len; i++)
			*(pstr + i) = MakecodeChar(*(pstr + i), pkey[i % 5]);
	}


	//����
	void Cutecode(char *pstr, int *pkey = key) {
		int len = strlen(pstr);
		for (int i = 0; i<len; i++)
			*(pstr + i) = CutcodeChar(*(pstr + i), pkey[i % 5]);
	}

	//���ռ��ܷ���
	void base64Makecode(char *urls, char **d)
	{
		Makecode(urls);
		base64Encode((unsigned const char*)urls, (unsigned int)strlen(urls) + 1, d);
	}

	//���ս��ܷ���
	void base64Cutecode(char *urls, unsigned char* &c)
	{
		//unsigned char *c = nullptr;
		base64Decode((unsigned const char*)urls, strlen(urls), &c);
		Cutecode((char *)c);
	}

	//����url���õ��������һ�� ���δ������ֱ�ӷ��ش�url
	string getUrlCodeByRandOne(string xxurl)
	{
		if (xxurl.substr(0, 4) != "http")
		{
			// todo base64���ָܷ�
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
//url_encypt::base64Makecode(urls, &d);   // ����
//
//cout << d << endl;
//
//unsigned char *c = nullptr;
//url_encypt::base64Cutecode(d, c);       // ����
//cout << c << endl;
//
//string xx = url_encypt::getUrlCodeByRandOne(d);  // ֱ�ӴӼ��ܵ�url ���ܲ�ֱ�������ȡ����һ����ַ
//cout << xx.c_str() << endl;