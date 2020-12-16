#ifndef LINK_ENTERPRISE_H
#define LINK_ENTERPRISE_H
#include "Enterprise.h"
#include <fstream>
class Link_enterprise
{
    public:
        Link_enterprise();      //默认构造函数
        void Add();             //添加企业
        Enterprise* Head();     //返回头指针
        void Write();           //写入文件
        void Read();            //读出文件
        bool Verify(string Name);                  //查找企业
        void Search();          //查找企业
        int length;             //链表长度
        void Show();            //显示所有信息
        void Change();          //修改企业信息
        void Sort();            //对用户进行排序
    private:
        Enterprise *head;
};

#endif // LINK_ENTERPRISE_H
