#ifndef WORKER_H
#define WORKER_H

/*
在此文件定义各类职工，使用多态避免代码重复
*/

#include <string>
#include <iostream>

using namespace std;

//职工基类，抽象类
class abstractWorker{
public:
    //显示个人信息，需要重写
    virtual void showInfo() = 0;
    //获取岗位名称，需要重写
    virtual string getDepartmentName() = 0;
    //析构函数
    ~abstractWorker(){
        //无在堆区申请的空间，但是由于是多态基类，那么保险起见，给出析构函数
    };
    //构造函数
    abstractWorker(const int _id, const string & _name, const int _departmentId) :     //换行
                   id(_id), name(_name), departmentId(_departmentId){

                   };
    //公有属性
    int id;     //员工id
    string name;    //员工姓名
    int departmentId;   //部门编号
};

//普通雇员
class employee: public abstractWorker{
public:
    //构造
    employee(const int _id, const string & _name, const int _departmentId) : 
             abstractWorker(_id, _name, _departmentId){

             }
    //析构
    ~employee(){

    }
    //重写函数
    void showInfo();    //cpp中重写
    string getDepartmentName(); //cpp中重写
};

//经理
class manager: public abstractWorker{
public:
    //构造
    manager(const int _id, const string & _name, const int _departmentId) : 
             abstractWorker(_id, _name, _departmentId){

             }
    //析构
    ~manager(){

    }
    //重写函数
    void showInfo();    //cpp中重写
    string getDepartmentName(); //cpp中重写
};

//老板
class boss: public abstractWorker{
public:
    //构造
    boss(const int _id, const string & _name, const int _departmentId) : 
             abstractWorker(_id, _name, _departmentId){

             }
    //析构
    ~boss(){

    }
    //重写函数
    void showInfo();    //cpp中重写
    string getDepartmentName(); //cpp中重写
};


#endif