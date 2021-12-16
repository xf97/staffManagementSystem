#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>  //用于输出的格式对齐
#include "worker.h"
#include "publicFeatures.h"

using namespace std;

//常量
//数据文件存放位置
const string DATA_FILE_PATH = ".\\storageData\\staffInfoFile.txt";

//管理类
//该类负责：菜单；对职工的增删查改；与文件的读写交互

class workerManager{
public:
    workerManager();    
    ~workerManager();
    void showMenu();    //显示菜单函数
    void addNewStaff(); //添加新员工
    void saveData();    //退出时存储数据
    void showStaffInfo();   //显示所有职工的信息
private:
    int staffNum;   //当前有多少个在职员工
    abstractWorker ** staffArray;   //保存信息的指针，指向abstractWorker*[]数组
    bool dataFileEmpty; //指示现在是否有数据文件，或者数据文件是空的
    int getStaffNum();  //dataFile存在的情况下先统计已经记录了多少人
    //bool isDataFileExist(); //用于检测数据文件是否存在，或者文件是否为空
};

#endif