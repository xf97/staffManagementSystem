#ifndef PUBLICFEATURES_H
#define PUBLICFEATURES_H

/*
该头文件用于集成一些公共接口函数
*/

#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

void cinNum(int & num, const string & coutTip);

void cinStr(string & str, const string & coutTip);

//指针比较函数，默认升序
bool abstractWorkerPtrCmpAsc(abstractWorker * abw1, abstractWorker * abw2);

//指针比较函数，降序
bool abstractWorkerPtrCmpEsc(abstractWorker * abw1, abstractWorker * abw2);

#endif