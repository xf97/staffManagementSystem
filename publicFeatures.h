#ifndef PUBLICFEATURES_H
#define PUBLICFEATURES_H

/*
该头文件用于集成一些公共接口函数
*/

#include <iostream>
#include <string>

using namespace std;

void cinNum(int & num, const string & coutTip);

void cinStr(string & str, const string & coutTip);

#endif