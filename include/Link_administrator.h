#ifndef LINK_ADMINISTRATOR_H
#define LINK_ADMINISTRATOR_H
#include "Administrator.h"
#include <fstream>
class Link_administrator
{
    public:
        Link_administrator();   //默认构造函数
        void SetNew();          //第一个管理员的构造函数
        void Add();             //添加新管理员
        void Delete();          //删除一个管理员
        Administrator* Head();  //返回头指针
        void Write();           //写入文件
        void Read();            //读出文件
        void ChangePass();      //修改密码
        bool Verify(string Name, string Pass);          //查找并核实管理员
        bool Verify(string Name);                       //查找管理员
        void Change();          //修改管理员信息
        int length;             //链表长度
        void Show();            //显示所有信息

    private:
        Administrator *head;
};

#endif // LINK_ADMINISTRATOR_H
