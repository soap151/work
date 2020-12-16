#ifndef ENTERPRISE_H
#define ENTERPRISE_H

#include <User.h>
class Enterprise : public User
{
    public:
        Enterprise(string Bussiness, string Legal_representative, double Assets, int Employees,
               double Land_use_area, double Original_value_property);   //构造函数
        Enterprise();                                 //构造函数
        void Change();                                //修改企业信息
        Enterprise* Next();                           //得到下一个节点的地址
        void SetNext(Enterprise *Next);               //修改下一个节点的地址
        Enterprise* operator = (Enterprise &a);       //重载等号
        string Bussiness();                           //返回企业名称
        string Legal_representative();                //返回法人代表
        double Assets();                              //返回资产总额
        int Employees();                              //返回职工数
        double Land_use_area();                       //返回土地使用面积
        double Original_value_property();             //返回房产原值
        void Show();                                  //展示信息
    private:
        string bussiness;                             //企业名称
        string legal_representative;                  //法人代表
        double assets;                                //资产总额
        int employees;                                //职工数
        double land_use_area;                         //土地使用面积
        double original_value_property;               //房产原值
        Enterprise *next;                             //下一个节点的地址
};

#endif // ENTERPRISE_H
