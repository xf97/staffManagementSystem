#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>  //用于输出的格式对齐
#include "worker.h"
#include "publicFeatures.h"

using namespace std;

//管理类
//该类负责：菜单；对职工的增删查改；与文件的读写交互

class workerManager{
public:
    workerManager();    
    ~workerManager();
    void showMenu();    //显示菜单函数
    void addNewStaff(); //添加新员工
private:
    int staffNum;   //当前有多少个在职员工
    abstractWorker ** staffArray;   //保存信息的指针，指向abstractWorker*[]数组
};

#endif