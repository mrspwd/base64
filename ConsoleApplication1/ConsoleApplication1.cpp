#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "url_encypt.h"

using namespace std;

int main()
{
	// 用于*.manifest 更新url 编码 编码格式 url,url,url,url
	//std::string xx = "http://xxx.xxxx.com:8091/version.manifest,http://xxx.xxx.com:8092/version.manifest,http://xxx.xxx.com:8093/xxx.manifest,http://xxxx.xxx.com:8094/version.manifest";


	//char urls[1024];
	////cin >> urls;
	//int idx = 0;

	//string a = "1,2,3,4,5,6,7,8,9";


	//char *d = nullptr;
	//url_encypt::base64Makecode((char *)a.c_str(), &d);

	//cout << d << endl;

	//unsigned char *c = nullptr;
	//url_encypt::base64Cutecode(d, c);
	//cout << c << endl;

	//string xx = url_encypt::getUrlCodeByRandOne(d);
	//cout << xx.c_str() << endl;

	char a[1024];
	ifstream ifile;               //定义输入文件
	ifile.open("url_encypt_source.txt");     //作为输入文件打开
	int i = 0, j, k;
	while (ifile.get(a[i])) {      //读标题,请对比cin.get(),不可用>>,它不能读白字符
		if (a[i] == '\n') break;
		i++;
	}
	a[i] = '\0';
	cout << "原始urls：" << endl;
	cout << a << endl;
	ifile.close();                 //关闭文件

	char *d = nullptr;
	url_encypt::base64Makecode((char *)a, &d);
	cout << "加密后：" << endl;
	cout << d << endl;

	unsigned char *c = nullptr;
	url_encypt::base64Cutecode(d, c);
	cout << "解密后：" << endl;
	cout << c << endl;

	string xx = url_encypt::getUrlCodeByRandOne(d);
	cout << "模拟解密后的随机其中一个url：" << endl;
	cout << xx.c_str() << endl;

	ofstream ofile;               //定义输出文件
	ofile.open("url_encypt.txt");     //作为输出文件打开
	ofile << d << endl;   //标题写入文件
	ofile.close();                //关闭文件


	//unsigned char *c = nullptr;
	//char *d = nullptr;
	////base64Encode((unsigned const char*)xx.c_str(), (unsigned int)xx.length()+1, &d);
	//base64Encode((unsigned const char*)urls, (unsigned int)strlen(urls) + 1, &d);
	//cout << d << endl;
	//unsigned char* x = (unsigned char*)d;
	////cout << x << endl;
	//base64Decode(x, strlen((char*)x), &c);
	//cout << c << endl;


	//cout << c << endl;
	system("pause");

	return 0;
}

