#include "worker.h"

//employee类
//显示职工信息
void employee::showInfo(){
    cout<<"Staff ID: "<<id<<",\t"
        <<"Staff Name: "<<name<<",\t"
        <<"Department Name: "<<getDepartmentName()<<",\t"
        <<"Job Duty: Completed the tasks that assigned by manager.\n";
}

//返回员工部门
string employee::getDepartmentName(){
    return "Normal staff";
}

//manager类
//显示职工信息
void manager::showInfo(){
    cout<<"Staff ID: "<<id<<",\t"
        <<"Staff Name: "<<name<<",\t"
        <<"Department Name: "<<getDepartmentName()<<",\t"
        <<"Job Duty: Complete his/her own tasks and assign tasks to normal staffs.\n";
}

//返回员工部门
string manager::getDepartmentName(){
    return "Manager";
}

//boss类
//显示职工信息
void boss::showInfo(){
    cout<<"Staff ID: "<<id<<",\t"
        <<"Staff Name: "<<name<<",\t"
        <<"Department Name: "<<getDepartmentName()<<",\t"
        <<"Job Duty: Manage all work of this company.\n";
}

//返回员工部门
string boss::getDepartmentName(){
    return "Boss";
}


