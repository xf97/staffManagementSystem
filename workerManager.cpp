#include "workerManager.h"

//构造函数
workerManager::workerManager(): staffNum(0), staffArray(nullptr){

}

//析构函数
workerManager::~workerManager(){
    //要释放堆区数据
    if(staffArray != nullptr){
        delete [] staffArray;
        staffArray = nullptr;
    }
}

//菜单显示函数
void workerManager::showMenu(){
    cout<<setfill('*')<<setw(70)<<"*"<<endl;
    cout<<"Welcome to staff management system"<<endl;;
    cout<<"0. quit this system\n";
    cout<<"1. create a new staff\n";
    cout<<"2. show all staffs info\n";
    cout<<"3. delete resigned staff\n";
    cout<<"4. modify a staff's info\n";
    cout<<"5. find the specific staff\n";
    cout<<"6. sort staff order in a specific way\n";
    cout<<"7. clean and remove all staff's data\n";
    cout<<setfill('*')<<setw(70)<<"*"<<endl;
}

//添加新员工函数
void workerManager::addNewStaff(){
    int num = 0;
    cinNum(num, "please enter the new staff number: ");
    if(num > 0){
        
    }
    else{
        cout<<"You input number is wrong.\n";
    }
}