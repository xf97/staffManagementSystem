#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>  //用于输出的格式对齐
#include <sstream>  //用于执行string到int的转换
#include <vector>   //引入数组
#include <set>      //引入集合，防止重复id
#include <algorithm>    //引入算法
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
    void deleteStaff(); //按编号删除员工
    void modifyStaff(); //按编号修改员工信息
    void findStaff();   //按编号或姓名查找员工信息
    void sortStaff();   //根据用户指定的升序/降序进行排序，该函数也会在删除员工后自动调用，默认id升序
    void cleanData();   //清空所有数据
private:
    int staffNum;   //当前有多少个在职员工
    abstractWorker ** staffArray;   //保存信息的指针，指向abstractWorker*[]数组
    bool dataFileEmpty; //指示现在是否有数据文件，或者数据文件是空的
    int getStaffNum();  //dataFile存在的情况下先统计已经记录了多少人
    int isThisStaffExist(const int _staffId);   //判断职工是否存在，返回在staffArray中的位置
    vector<int> isThisStaffExist(const string & _name); //重载函数，通过姓名查询，返回数组
    set<int> ids;   //为保证id唯一
    void sortStaff(int); //内部调用的排序函数，使用占位参数完成重载
    //bool isDataFileExist(); //用于检测数据文件是否存在，或者文件是否为空
};

#endif