#include "publicFeatures.h"

void cinNum(int & num, const string & coutTip){
    cout<<coutTip;
    //此处做cin的异常处理，要求cin给入正常类型
    while(true){
        cin>>num;
        if(cin.fail()){
        //如果输入错误，则进入此部分
            cin.clear();    //恢复cin状态
            cin.sync(); //清空输入缓冲区，clear和sync要联合使用
            cout<<"Wrong type input, please re-enter your choice (must be number): ";
            continue;
        }
        //进入到此部分就是正常类型输入
        break;
    }
}