#include "headFiles.h"

/*
该文件将使用CPP制作一个职工管理系统
*/

//需求分析
/*
1. 员工分为三类，普通员工，经理，老板，显示信息时，需要显示员工编号，姓名，岗位，职责
2. 普通员工职责：完成经理交予的任务，经理职责：完成老板交给的任务，并下发给员工，老板：管理公司的所有事务
3. 管理系统中需要实现的功能
i. 退出
ii. 增加职工功能信息，实现批量添加-通过文件，职工信息：编号、姓名、部门编号
iii. 显示所有职工的信息
iv. 删除离职员工，按照员工编号删除
v. 修改职工信息，按照员工编号修改
vi. 按照编号或姓名查找员工信息
vii. 按照编号进行排序，升序降序由用户指定
viiii. 清空所有信息，包括文件，要提供再次确认功能
*/

int main(){
    //cout<<"Hello world.\n";
    //showMenu();
    //声明控制类
    workerManager wm;
    int choice = -1;   //用户选择
    while(choice != 0){
        wm.showMenu();
        cinNum(choice, "Please enter your choice: ");
        //测试
        // abstractWorker * aw = new employee(1, "xiaofeng", 1);
        // aw->showInfo();
        // delete aw;
        // aw = new manager(2, "hejiahua", 2);
        // aw->showInfo();
        // delete aw;
        // aw = new boss(3, "mayun", 3);
        // aw->showInfo();
        // delete aw;
        switch (choice)
        {
        case 0:
            //quit this system
            //应该是退出时保存信息
            wm.saveData();
            break;
        case 1:
            //添加员工，并且保存到文件中
            wm.addNewStaff();
            break;
        case 2:
            //do something
            break;
        case 3:
            //do something
            break;
        case 4:
            //do something
            break;
        case 5:
            //do something
            break;
        case 6:
            //do something
            break;
        case 7:
            //do something
            break;
        default:
            system("cls");
            cout<<"you have entered the wrong number, please enter again.\n";
            break;
        }
    }
    cout<<"Already quit the system!\n";
    return 0;
}