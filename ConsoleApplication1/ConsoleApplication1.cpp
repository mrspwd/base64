#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "url_encypt.h"

using namespace std;

int main()
{
	// ����*.manifest ����url ���� �����ʽ url,url,url,url
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
	ifstream ifile;               //���������ļ�
	ifile.open("url_encypt_source.txt");     //��Ϊ�����ļ���
	int i = 0, j, k;
	while (ifile.get(a[i])) {      //������,��Ա�cin.get(),������>>,�����ܶ����ַ�
		if (a[i] == '\n') break;
		i++;
	}
	a[i] = '\0';
	cout << "ԭʼurls��" << endl;
	cout << a << endl;
	ifile.close();                 //�ر��ļ�

	char *d = nullptr;
	url_encypt::base64Makecode((char *)a, &d);
	cout << "���ܺ�" << endl;
	cout << d << endl;

	unsigned char *c = nullptr;
	url_encypt::base64Cutecode(d, c);
	cout << "���ܺ�" << endl;
	cout << c << endl;

	string xx = url_encypt::getUrlCodeByRandOne(d);
	cout << "ģ����ܺ���������һ��url��" << endl;
	cout << xx.c_str() << endl;

	ofstream ofile;               //��������ļ�
	ofile.open("url_encypt.txt");     //��Ϊ����ļ���
	ofile << d << endl;   //����д���ļ�
	ofile.close();                //�ر��ļ�


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

