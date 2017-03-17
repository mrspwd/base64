#include "stdafx.h"

#include <iostream>
#include <vector>
#include "base64.h"
using namespace std;
using namespace cocos2d;
// todo
std::vector<std::string> split(std::string str, std::string pattern)
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
int main()
{
	// 用于*.manifest 更新url 编码 编码格式 url,url,url,url
	std::string xx = "http://xxx.xxxx.com:8091/version.manifest,http://xxx.xxx.com:8092/version.manifest,http://xxx.xxx.com:8093/xxx.manifest,http://xxxx.xxx.com:8094/version.manifest";

	string aa = xx.substr(0, 114);
	bool xxxxx = aa == "http";

	unsigned char *c = nullptr;
	char *d = nullptr;
	base64Encode((unsigned const char*)xx.c_str(), (unsigned int)xx.length()+1, &d);
	cout << d << endl;
	unsigned char* x = (unsigned char*)d;
	cout << x << endl;
	base64Decode(x, strlen((char*)x), &c);
	cout << c << endl;

	//string xxx = "YXNkYWtqZmtsc2pkYWY7J2FzZmRrJ2Rna2onZmRnYXNkJ2ZhcydkZnMnYWRmYXNkZidzYWRmO2xhc2RmO2wA";
	//base64Decode((unsigned char*)xxx.c_str(), (unsigned int)xxx.length(), &c);

	cout << c << endl;
	return 0;
}

