#ifndef STAFF_H
#define STAFF_H

#include <User.h>
class Staff : public User
{
    public:
        Staff(string Name, string Password, string Realname, string Company,
               string Contact);                  //构造函数
        Staff();                                 //构造函数
        void Change();                           //修改用户信息
        void ChangePass();                       //修改密码
        Staff* Next();                           //得到下一个节点的地址
        void SetNext(Staff *Next);               //修改下一个节点的地址
        Staff* operator = (Staff &a);            //重载等号
        string Realname();                       //返回真实姓名
        string Company();                        //返回单位
        string Contact();                        //返回联系方式
        void Show();                             //展示信息
    private:
        string realname;                         //真实姓名
        string company;                          //单位
        string contact;                          //联系方式
        Staff *next;                             //下一个节点的地址
};

#endif // STAFF_H
