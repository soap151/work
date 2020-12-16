#ifndef LINK_STAFF_H
#define LINK_STAFF_H
#include "Staff.h"
#include <fstream>
class Link_staff
{
    public:
        Link_staff();           //默认构造函数
        void SetNew();          //第一个管理员的构造函数
        void Add();             //添加新用户
        void Delete();          //删除一个用户
        Staff* Head();          //返回头指针
        void Write();           //写入文件
        void Read();            //读出文件
        bool Verify(string Name, string Pass);          //查找并核实用户
        bool Verify(string Name);                       //查找用户
        void Search();          //查找用户
        int length;             //链表长度
        void Show();            //显示所有信息
        void Change();          //修改用户信息
        void ChangePass();      //修改密码
        void ChangePass(string Name);                   //修改密码
        void Sort();            //对用户进行排序
    private:
        Staff *head;
};

#endif // LINK_STAFF_H
