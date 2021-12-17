#include "workerManager.h"

//构造函数
//初值列初始话的顺序要与声明顺序匹配
workerManager::workerManager(){
    //构造函数要注意数据文件已存在的情况
    ifstream ifs(DATA_FILE_PATH, ios::in);
    if(!ifs.is_open()){
        //文件不存在
        cout<<"Don't find local data file.\n";
        staffNum = 0;
        dataFileEmpty = true;
        staffArray = nullptr;
        ifs.close();
    }
    else{
        //读一个字符来判断是否到空字符
        char ch = 'c';
        ifs>>ch;
        //现在可以判断是否到文件尾了
        if(ifs.eof()){
            //空文件
            cout<<"The local data file is empty.\n";
            staffNum = 0;
            dataFileEmpty = true;
            staffArray = nullptr;
            ifs.close();
        }
        else{
            //文件存在且不为空
            //要读取文件并回调指针
            ifs.seekg(0, ios::beg); //读取位置调回首位置
            int num = getStaffNum();    //获取当前已存储了多少个员工的记录，方便申请空间
            staffNum = num; //初始化长度
            //申请空间
            staffArray = new abstractWorker * [staffNum];
            //开始赋值
            int id = 0;
            string name = "";
            int departmentId = 0;
            for(int i = 0; i < staffNum; ++ i){
                ifs>>id>>name>>departmentId;
                //插入id
                ids.insert(id);
                switch (departmentId)
                {
                case 1:
                    staffArray[i] = new employee(id, name, departmentId);
                    break;
                case 2:
                    staffArray[i] = new manager(id, name, departmentId);
                    break;
                case 3:
                    staffArray[i] = new boss(id, name, departmentId);
                    break;
                }
            }
            dataFileEmpty = false;
            cout<<"Already get "<<staffNum<<" staff(s) information.\n";
            ifs.close();
        }
    }
}

//析构函数
workerManager::~workerManager(){
    //要释放堆区数据        
    //释放每一个指针占据的空间
    for(int i = 0; i < staffNum; ++ i){
        if(staffArray[i] != nullptr){
            delete staffArray[i];   //释放空间
            staffArray[i] = nullptr;
        }
        else{
            continue;
        }
    }
    //释放二维指针
    delete [] staffArray;
    staffArray = nullptr;
    //数据置空
    staffNum = 0;
    dataFileEmpty = true;
}

//返回dataFile文件中已记录的员工数量
int workerManager::getStaffNum(){
    ifstream ifs(DATA_FILE_PATH, ios::in);
    int num = 0;    //人数
    string tempContent = "";    //缓存行
    while(!ifs.eof()){
        getline(ifs, tempContent, '\n');
        //要确定不是空行
        num = (tempContent.empty()) ? num : num + 1;    //非空就+1
    }
    ifs.close();
    return num;
}

// bool workerManager::isDataFileExist(){
// }

//菜单显示函数
void workerManager::showMenu(){
    cout<<setfill('*')<<setw(70)<<"*"<<endl;
    cout<<"Welcome to staff management system"<<endl;;
    cout<<"0. quit this system\n";
    cout<<"1. create the new staffs\n";
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
        //计算新空间大小
        int newSize = staffNum + num;
        //重新开辟空间
        abstractWorker ** newStaffArray = new abstractWorker * [newSize];
        //拷贝原始数据到新空间
        if(staffNum > 0){
            for(int i = 0; i < staffNum; ++ i){
                newStaffArray[i] = staffArray[i];   //Worker*的拷贝，要想到需要考虑深拷贝
                //指针拷贝，可以使用单纯的赋值号 
            }
        }
        //添加新空间的信息
        for(int i = 0; i < num; ++ i){
            //给定信息
            int id = 0;
            string name = "";
            int departmentId = 0;

            cinNum(id, "Please enter the #" + to_string(i + 1) + " staff's id: ");
            while(count(ids.begin(), ids.end(), id) >= 1){
                //出现重复id，重新输入
                cinNum(id, "Already have this id, please enter the #" + to_string(i + 1) + " staff's id: ");
            }
            cinStr(name, "Please enter the #" + to_string(i + 1) + " staff's name: ");
            cinNum(departmentId, "Please select the #" + to_string(i + 1) + " department id " +
                   "(1- Normal staff, 2-Manager, 3-Boss): ");
            //申请新空间
            abstractWorker * newStaff = nullptr;
            switch (departmentId)
            {
            case 1:
                newStaff = new employee(id, name, departmentId);
                break;
            case 2:
                newStaff = new manager(id, name, departmentId);
                break;
            case 3:
                newStaff = new boss(id, name, departmentId);
                break;
            default:
                cout<<"Wrong department Id input! please check your input and terminal this operation.\n";
                break;
            }
            //填入新id
            ids.insert(id);
            //指针指向
            //注意不要覆盖原数据
            newStaffArray[staffNum + i] = newStaff;
        }
        //释放原有的空间
        delete [] staffArray;
        //更改指针指向
        staffArray = newStaffArray;
        //更新信息
        staffNum = newSize;
        //提示信息
        cout<<"Successfully add "<<(num)<<" staffs' info!\n";
    }
    else{
        cout<<"You input number is wrong, please redo your operations.\n";
    }
}

//该函数用于在程序退出是保存数据->文件
void workerManager::saveData(){
    //空数组，不保存
    if(staffArray == nullptr){
        return;
    }
    //写文件，输出流
    ofstream ofs(DATA_FILE_PATH, ios::out | ios::binary);
    if(!ofs.is_open()){
        cout<<"Saved data failed in opening data files, please check.\n";
        return;
    }
    //然后开写就可以了
    for(int i = 0; i < staffNum; ++ i){
        //向谁写，箭头就指向谁
        //ofs.write((const char *)&staffArray[i], sizeof((*staffArray[i])));
        ofs<<staffArray[i]->id<<"\t"<<staffArray[i]->name<<"\t"<<staffArray[i]->departmentId<<endl;
    }
    //关闭文件
    ofs.close();
    //提示信息
    cout<<"All data has been saved.\n";
}

//删除职工的信息
void workerManager::deleteStaff(){
    int id = 0;
    //先接收要删除的职工的id
    cinNum(id, "please input the staff' id that you need to delete: ");
    //移到最后，逻辑置空
    int index = isThisStaffExist(id);
    if(index == -1){
        cout<<"The specify staff that you need to delete is not existence.\n";
        return;
    }
    else{
        //把要删除的放到最后去
        abstractWorker * tempPtr = nullptr;
        tempPtr = staffArray[index];
        staffArray[index] = staffArray[staffNum - 1];
        staffArray[staffNum - 1] = tempPtr;
        //id释放
        ids.erase(id);  //按值删除
        -- staffNum;    //指针前移
        //排序
        sortStaff(1);   //默认id升序
        cout<<"Already delete #"<<(id)<<" staff's information.\n";
        return;
    }
}

void workerManager::sortStaff(int){    
    if(staffNum <= 0){
        return;
    }
    else{
        sort(staffArray, staffArray + staffNum, abstractWorkerPtrCmpAsc);
        cout<<"Sort staff order is done.\n";
        return;
    }
}

//判断职工是否存在的函数
int workerManager::isThisStaffExist(const int _id){
    int result = -1;
    for(int i = 0; i < staffNum; ++ i){
        if(staffArray[i]->id == _id){
            return i;
        }
        else{
            continue;
        }
    }
    return result;
}

void workerManager::showStaffInfo(){
    if(staffNum > 0){
        for(int i = 0; i < staffNum; ++ i){
            staffArray[i]->showInfo();  //多态函数
        }
    }
    else{
        cout<<"No staff have been recorded.\n";
    }
    return;
}

//按职工id修改职工信息函数
void workerManager::modifyStaff(){
    if(staffNum <= 0){
        cout<<"No staff have been recorded, so can't modify what.\n";
        return;
    }
    else{
        int id = 0;
        cinNum(id, "please input the staff' id that you need to modify: ");
        int index = isThisStaffExist(id);
        if(index == -1){
            cout<<"The staff you specify to modify is not existence.\n";
            return;
        }
        else{
            //要释放原来的指针
            delete staffArray[index];
            staffArray[index] = nullptr;
            //释放id
            ids.erase(id);
            //填入数据
            int newId = -1;
            string name = "";   
            int departmentId = -1; 
            cinNum(id, "Please enter the #" + to_string(id) + " staff's new id: ");
            while(count(ids.begin(), ids.end(), id) >= 1){
                //出现重复id，重新输入
                cinNum(id, "Already have this id, please enter the original #" + to_string(id) + " staff's id: ");
            }
            cinStr(name, "Please enter the #" + to_string(id) + " staff's new name: ");
            cinNum(departmentId, "Please select the #" + to_string(id) + " new department id " +
                   "(1- Normal staff, 2-Manager, 3-Boss): ");
            switch (departmentId)
            {
                case 1:
                    staffArray[index] = new employee(id, name, departmentId);
                    break;
                case 2:
                    staffArray[index] = new manager(id, name, departmentId);
                    break;
                case 3:
                    staffArray[index] = new boss(id, name, departmentId);
                    break;
            }
            //填入id
            ids.insert(id);
            cout<<"Already modified the original #"<<(id)<<" staff's information.\n";
            return;
        }
    }
}

void workerManager::findStaff(){
    if(staffNum <= 0){
        cout<<"No staff have been recorded, so can't find what.\n";
        return;
    }
    else{
        string keyword = "";    //查询的关键字
        //尝试转成int
        cinStr(keyword, "please input the staff' id or name that you need to query: ");
        try
        {
            // stringstream ss;
            // int id = 0;
            // ss<<keyword;    //读取字符串
            // ss>>id; //输入到数字中，不异常的话开查
            // cout<<id<<endl;
            int id = stoi(keyword); //不是数字的话就报异常
            int index = isThisStaffExist(id);
            if(index == -1){
                cout<<"The staff you specify to query is not existence.\n";
                return;
            }
            else{
                staffArray[index]->showInfo();  //直接调用就好
            }
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';
            cout<<"enable name query.\n";
            //启用名字查询
            //注意，名字可能重名
            vector<int> indexs = isThisStaffExist(keyword);            
            if(indexs.empty()){
                cout<<"No staff you specify to query is not existence.\n";
                return;
            }
            else{
                for(int i : indexs){
                    staffArray[i]->showInfo();  //调用重载函数
                }
            }
        }
        return;
    }
}

vector<int> workerManager::isThisStaffExist(const string & _name){
    vector<int> result;
    for(int i = 0; i < staffNum; ++ i){
        if(staffArray[i]->name == _name){
            result.push_back(i);
        }
        else{
            continue;
        }
    }
    return result;
}

void workerManager::sortStaff(){
    if(staffNum <= 0){
        cout<<"No staff have been recorded, so can't sort what.\n";
        return;
    }
    else{
        int sortType = 1;   //排序类型，1-id升序，2-id降序
        do{
            cinNum(sortType, "Please choose a sort type (1-ascending, 2-escending): ");
        } while(sortType != 1 && sortType != 2);    //要求只能是1或2
        if(sortType == 1){
            sort(staffArray, staffArray + staffNum, abstractWorkerPtrCmpAsc);
        }
        else{
            sort(staffArray, staffArray + staffNum, abstractWorkerPtrCmpEsc);
        }
        cout<<"Sort staff order is done.\n";
        return;
    }
}

void workerManager::cleanData(){
    int retype = 2;
    do{
        cinNum(retype, "Be sure to clean all data (1-yes, 2-no): ");
    } while(retype != 1 && retype != 2);
    if(retype == 1){
        //先删掉文件，其实不删直接写回应该写是覆盖
        ofstream ofs(DATA_FILE_PATH, ios::trunc);
        ofs.close();

        //释放每一个指针占据的空间
        for(int i = 0; i < staffNum; ++ i){
            if(staffArray[i] != nullptr){
                delete staffArray[i];   //释放空间
                staffArray[i] = nullptr;
            }
            else{
                continue;
            }
        }
        //释放二维指针
        delete [] staffArray;
        staffArray = nullptr;
        //数据置空
        staffNum = 0;
        dataFileEmpty = true;
        cout<<"Clean all data -- done!\n";
        return;

    }
    else{
        return;
    }
}