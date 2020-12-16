#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <string>
#include "User.h"
using namespace std;
class Administrator : public User
{
    public:
        Administrator(string Name, string Password);    //构造函数
        Administrator();                                //构造函数
        void Change();                                  //修改用户信息
        void ChangePass();                              //修改密码
        Administrator* Next();                          //得到下一个节点的地址
        void SetNext(Administrator *Next);              //修改下一个节点的地址
    private:
        Administrator *next;
};

#endif // ADMINISTRATOR_H
