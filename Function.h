#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Administrator.h"
#include "Staff.h"
#include "Enterprise.h"
#include "Link_Enterprise.h"
#include "Link_administrator.h"
#include "Link_staff.h"

int Level;                          //登录用户的等级
string Or_reader;                   //记录当前登录的用户
bool Menu_main_control();           //主菜单功能控制
bool FirstLogin();                  //检测是否为第一次登录
void Login();                       //登录系统
void Menu_level(int level);         //等级菜单
void Menu_main();                   //主菜单
void Menu_user();                   //管理员相关子菜单
bool User_Management();             //管理员相关功能
void Menu_staff();                  //用户相关子菜单
bool Staff_Management();            //用户相关功能
void Menu_enterprise();             //企业管理子菜单
void Menu_Search();                 //企业查询子菜单
bool Enterprise_Management();       //企业相关功能
void Menu_tax();                    //税务相关功能
bool Tax_Management();              //税务相关子菜单
//---------------------------------------------------------------
using namespace std;
bool FirstLogin()   //检测是否为第一次登录
{
    ifstream text("Administrator.txt");
    return !text;
}
void Login()        //登录系统
{
    if(FirstLogin())  //如果是第一次登录
    {
        cout << ">>检测到您为第一次登录，现在创建您的系统管理员用户" << endl;
        cout << ">>创建你的账户:" << endl;
        Link_administrator admin;       //建立链表
        admin.SetNew();                 //建立第一个系统管理员
        admin.Write();                  //写入文件
        cout << "创建成功！" << endl;
        ofstream text("Tax_rate.txt");
        string name = "税率";
        double value_added_tax;
        double Property_tax;
        double Land_use_tax;
        double resource_tax;
        double stamp_tax;
        double corporate_income_tax;
        bool stamp_tax_date = 0;
        cout << "税率初始化。" << endl;
        cout << "请输入增值税率" << endl;
        cin >> value_added_tax;
        cout << "请输入房产税率" << endl;
        cin >> Property_tax;
        cout << "请输入土地使用税率" << endl;
        cin >> Land_use_tax;
        cout << "请输入资源税率" << endl;
        cin >> resource_tax;
        cout << "请输入印花税率" << endl;
        cin >> stamp_tax;
        cout << "请输入企业所得税率" << endl;
        cin >> corporate_income_tax;
        text << name << " " << value_added_tax << " " << Property_tax << " " << Land_use_tax << " " << resource_tax << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
        cout << "输入完成" << endl;
        exit(0);
    }
    //如果不是第一次登录
    Link_administrator admin;
    Link_staff staff;
    admin.Read();       //读出系统管理员文件
    staff.Read();       //读出用户文件
    string Name;
    string Password;
    bool login = false;
    cout << ">>登入系统" << endl;
    for(int i=0; i<3 && !login; i++)
    {
        cout << "用户名:";
        cin >> Name;
        cout << "密码:";
        cin >> Password;
        if(admin.Verify(Name,Password))     //如果成功登入系统管理员
        {
            cout << "登入成功!" << endl;
            Level = 2;
            break;
        }
        else if(staff.Verify(Name,Password))
        {
            cout << "登入成功!" << endl;
            Or_reader = Name;           //记住当前用户
            Level = 1;
            break;
        }
        else
        {
            if(!login && i != 2)
                cout << ">用户名或密码错误，还剩下" << 2 - i << "次机会" << endl;
            else if(i == 2 && !login)
            {
                cout << ">机会已用完!" << endl;
                exit(0);
            }
        }
    }
}
void Menu_level(int level)
{
    if(level == 2)  cout << ">您的身份为系统管理员" << endl;
    if(level == 1)  cout << ">欢迎回来!" << Or_reader << endl;
}

void Menu_main()         //主菜单
{
    system("cls");
    cout << "                   企业税务管理系统" << endl;
    Menu_level(Level);
    cout << endl;
    cout << "1.管理员相关" << endl;
    cout << "2.用户相关" << endl;
    cout << "3.企业相关" << endl;
    cout << "0.退出系统" << endl;
}
void Menu_user()
{
    system("cls");
    cout << "1.管理员信息输入" << endl;
    cout << "2.管理员信息修改" << endl;
    cout << "3.管理员信息删除" << endl;
    cout << "4.管理员信息显示" << endl;
    cout << "5.管理员密码修改" << endl;
    cout << "0.返回主菜单" << endl;
}
void Menu_staff()
{
    system("cls");
    cout << "1.用户信息输入" << endl;
    cout << "2.用户信息修改" << endl;
    cout << "3.用户信息删除" << endl;
    cout << "4.用户信息查询" << endl;
    cout << "5.用户信息显示" << endl;
    cout << "0.返回主菜单" << endl;
}
void Menu_enterprise()
{
    system("cls");
    cout << "1.企业信息输入" << endl;
    cout << "2.企业信息修改" << endl;
    cout << "3.企业信息查询" << endl;
    cout << "4.汇总统计" << endl;
    cout << "5.税率相关" << endl;
    cout << "6.税务统计" << endl;
    cout << "0.返回主菜单" << endl;
}
void Menu_tax()
{
    system("cls");
    cout << "1.税率展示" << endl;
    cout << "2.税率修改" << endl;
    cout << "3.印花税审交状态修改" << endl;
    cout << "0.返回上级菜单" << endl;
}

//主菜单操作-----------------------------------------------------------------
bool Menu_main_control()
{
    char order;
    bool Continue = true;
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        while(Continue)
        {
            if(Level == 1)          //如果权限等级等于1
            {
                cout << "请求被拒绝！" << endl;
                goto re;
            }
            Menu_user();            //调用用户操作菜单
            Continue = User_Management();
        }
        return true;                //返回真值，继续执行程序
    case '2':
        while(Continue)
        {
            Menu_staff();          //调用用户操作菜单
            Continue = Staff_Management();
        }
        return true;
    case '3':
        while(Continue)
        {
            Menu_enterprise();          //调用企业操作菜单
            Continue = Enterprise_Management();
        }
        return true;
    case '0':
        break;
    default:
        cout << "无效操作！" << endl;
        goto re;      //重新输入
    }
    return false;                   //返回假值，结束执行
}
//管理员相关功能---------------------------------------------------
bool User_Management()
{
    char order;
    Link_administrator admin;
    admin.Read();       //读出系统管理员文件
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        if(Level == 2)
        {
            cout << "1.创建一个系统管理员" << endl;
            cout << endl << "0.返回" << endl;
            Rein1:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Add();
                admin.Write();
                cout << "添加成功" << endl;
                break;
            case '0':
                break;
            default:
                cout << "无效操作！" << endl;
                goto Rein1;      //重新输入
            }
            break;
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
    case '2':
        if(Level == 2)
        {
            cout << "1.修改系统管理员的信息" << endl;
            cout << endl << "0.返回" << endl;
            Rein2:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Change();
                admin.Write();
                cout << "修改成功" << endl;
                break;
            case '0':
                break;
            default:
                cout << "无效操作！" << endl;
                goto Rein2;      //重新输入
            }
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
        break;
    case '3':
        if(Level == 2)
        {
            cout << "1.删除系统管理员" << endl;
            cout << endl << "0.返回" << endl;
            Rein3:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Delete();
                admin.Write();
                cout << "删除成功" << endl;
                break;
            case '0':
                break;
            default:
                cout << "无效操作！" << endl;
                goto Rein3;      //重新输入
            }
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
        break;
    case '4':
        if(Level == 2)
        {
            char End;
            cout << "系统管理员的信息展示" << endl;
            admin.Show();
            cout << endl << "0.返回" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "无效操作!" << endl;
            }
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
        break;
    case '5':
        if(Level == 2)
        {
            cout << "1.修改系统管理员的密码" << endl;
            cout << endl << "0.返回" << endl;
            Rein5:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.ChangePass();
                admin.Write();
                cout << "修改成功" << endl;
                break;
            case '0':
                break;
            default:
                cout << "无效操作！" << endl;
                goto Rein5;      //重新输入
            }
        }
        break;
    case '0':
        return false;       //返回假值,返回主菜单
    default:
        cout << "无效操作！" << endl;
        goto re;
    }
    return true;
}
//用户相关功能----------------------------------------------------
bool Staff_Management()
{
    char order;
    Link_staff staff;
    staff.Read();
    re:
    cin >> order;
    switch(order)
    {
    case '1':
            if(Level == 2)
            {
                staff.Add();
                staff.Write();
                cout << "添加成功" << endl;
            }
            else
            {
                cout << ">请求被拒绝！" << endl;
                goto re;
            }
            break;
    case '2':
            if(Level == 2)
            {
                staff.Change();
                staff.Write();
                cout << "修改成功" << endl;
            }
            else if(Level == 1)
            {
                if(staff.Verify(Or_reader))
                {
                    Staff *note = staff.Head();
                    while(note != NULL)
                    {
                        if(note->Name() == Or_reader)
                        {
                            note->Change();
                            break;
                        }
                        else note = note->Next();
                    }
                    staff.Write();
                    break;
                }
                cout << "修改成功" << endl;
            }
            break;
    case '3':
            if(Level == 2)
            {
                staff.Delete();
                staff.Write();
                cout << "删除成功" << endl;
            }
            else
            {
                cout << ">请求被拒绝！" << endl;
                goto re;
            }
            break;
    case '4':
            if(Level == 2)
            {
                staff.Search();
            }
            else if(Level == 1)
            {
                char End;
                Staff *note = staff.Head();
                while(note != NULL)
                {
                    if(note->Name() == Or_reader)
                    {
                        note->Show();
                        cout << "0.返回" << endl;
                        while(cin >> End)
                        {
                            if(End == '0')      break;
                            else    cout << "无效操作!" << endl;
                        }
                    }
                    else note = note->Next();
                    break;
                }
            }
            break;
    case '5':
            if(Level == 2)
            {
                char End;
                cout << "用户信息展示" << endl;
                staff.Sort();
                cout << endl << "0.返回" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else cout << "无效操作!" << endl;
                }
            }
            else
            {
                cout << ">请求被拒绝！" << endl;
                goto re;
            }
            break;
    case '0':
        return false;       //返回假值,返回主菜单
    default:
        cout << "无效操作！" << endl;
        goto re;
    }
    return true;
}
//企业相关功能---------------------------------------------
bool Enterprise_Management()
{
    char order;
    Link_enterprise link_enterprise;
    link_enterprise.Read();        //读出企业文件
    re:
    cin >> order;
    bool Continue1 = true;
    switch(order)
    {
    case '1':
        if(Level == 2)
        {
            link_enterprise.Add();
            link_enterprise.Write();
            cout << "添加成功" << endl;
            break;
        }
        else
        {
            cout << "请求被拒绝" << endl;
            goto re;
        }
    case '2':
        if(Level == 2)
        {
            link_enterprise.Change();
            link_enterprise.Write();
            cout << "修改成功" << endl;
            break;
        }
        else
        {
            cout << "请求被拒绝" << endl;
            goto re;
        }
    case '3':
        link_enterprise.Search();
        break;

    case '4':
            if(Level == 2)
            {
                char End;
                cout << "企业信息展示" << endl;
                link_enterprise.Sort();
                cout << endl << "0.返回" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else cout << "无效操作!" << endl;
                }
            }
            else
            {
                cout << ">请求被拒绝！" << endl;
                goto re;
            }
            break;
    case '5':
            while(Continue1)
            {
                Menu_tax();           //调用税务操作菜单
                Continue1 = Tax_Management();
            }
            break;
    case '6':
            {

                ifstream text("Tax_rate.txt");
                string name;
                double value_added_tax;
                double property_tax;
                double land_use_tax;
                double resource_tax;
                double stamp_tax;
                double corporate_income_tax;
                bool stamp_tax_date;
                text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
                char End;
                Enterprise* notes;
                notes = link_enterprise.Head();
                string bussiness;                             //企业名称
                string legal_representative;                  //法人代表
                double assets;                                //资产总额
                int employees;                                //职工数
                double land_use_area;                         //土地使用面积
                double original_value_property;               //房产原值
                cout << "请输入你要计算的企业：";
                cin >> bussiness;
                while(notes != NULL)
                {
                    if(notes->Bussiness() == bussiness)
                    {
                        notes->Show();
                        bussiness = notes->Bussiness();                             //返回企业名称
                        legal_representative = notes->Legal_representative();       //返回法人代表
                        assets = notes->Assets();                                   //返回资产总额
                        assets = notes->Employees();                                //返回职工数
                        land_use_area = notes->Land_use_area();                     //返回土地使用面积
                        original_value_property = notes->Original_value_property(); //返回房产原值
                        cout << "0.继续" << endl;
                        while(cin >> End)
                        {
                            if(End == '0')      break;
                            else    cout << "无效操作!" << endl;
                        }
                        break;
                    }
                    else
                    notes = notes->Next();
                }
                double business_income;
                double operating_costs;
                double other_expenses;
                double intput_tax;
                double output_tax;
                cout << endl << "请输入营业收入" << endl;
                cin >> business_income;
                cout << endl << "请输入营业成本" << endl;
                cin >> operating_costs;
                cout << endl << "请输入其他费用" << endl;
                cin >> other_expenses;
                double Value_added_tax;
                double Property_tax;
                double Land_use_tax;
                double Resource_tax;
                double Stamp_tax;
                double Corporate_income_tax;
                cout << "此企业是否为原料生产企业(输入1 0)" << endl;
                bool judge1;
                cin >> judge1;
                if(judge1)
                {
                    Value_added_tax = (business_income - operating_costs - other_expenses) * value_added_tax;
                }
                else
                {
                    cout << endl << "请输入进项税额" << endl;
                    cin >> intput_tax;
                    cout << endl << "请输入销项税额" << endl;
                    cin >> output_tax;
                    Value_added_tax = output_tax - intput_tax;
                    if(Value_added_tax <= 0)
                        Value_added_tax = 0;
                }
                Property_tax = property_tax * original_value_property / 12;
                Land_use_tax = land_use_tax * land_use_area / 12;
                cout << "此企业是否为资源依赖型企业(输入1 0)" << endl;
                bool judge2;
                cin >> judge2;
                if(judge2)
                {
                    Resource_tax = resource_tax * (business_income - operating_costs);
                }
                else Resource_tax = 0;
                if(stamp_tax_date)
                {
                    Stamp_tax = stamp_tax * business_income;
                }
                else Stamp_tax = 0;
                if(employees <= 300 && assets <= 50000000)
                {
                    if(assets <= 1000000)
                      Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax * 0.2;
                    else if(assets > 1000000 && assets <= 3000000)
                        Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax * 0.4;
                    else Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax;
                }

                else Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax;
                cout << "增值税为：" << Value_added_tax << endl;
                cout << "房产税为：" << Property_tax << endl;
                cout << "土地使用税为：" << Land_use_tax << endl;
                cout << "资源税为：" << Resource_tax << endl;
                cout << "印花税为：" << Stamp_tax << endl;
                cout << "企业所得税为：" << Corporate_income_tax << endl;
                cout << "合计：" << Value_added_tax + Property_tax + Land_use_tax + Resource_tax + Stamp_tax + Corporate_income_tax << endl;
                cout << "折后收入为：" << (business_income - operating_costs - other_expenses) - (Value_added_tax + Property_tax + Land_use_tax + Resource_tax + Stamp_tax + Corporate_income_tax) << endl;
                cout << "0.返回" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else    cout << "无效操作!" << endl;
                }
                break;
            }
            break;

    case '0':
        return false;       //返回假值,返回主菜单
    default:
        cout << "无效操作！" << endl;
        goto re;
    }
    return true;
}
//税务相关功能--------------------------------------------
bool Tax_Management()
{
    char order;
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        if(Level <= 2)
        {
            char End;
            cout << "税率信息展示" << endl;
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            cout << "增值税率为：    " << value_added_tax << endl;
            cout << "房产税率为：    " << property_tax << endl;
            cout << "土地使用税率为：" << land_use_tax << endl;
            cout << "资源税率为：    " << resource_tax << endl;
            cout << "印花税率为：    " << stamp_tax << endl;
            cout << "企业所得税率为：" << corporate_income_tax << endl;
            cout << endl << "0.返回" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "无效操作!" << endl;
            }
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
        break;
    case '2':
        if(Level == 2)
        {
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            cout << "增值税率为：" << endl;
            cin >> value_added_tax;
            cout << "房产税率为：" << endl;
            cin >> property_tax;
            cout << "土地使用税率为：" << endl;
            cin >> land_use_tax;
            cout << "资源税率为：" << endl;
            cin >> resource_tax;
            cout << "印花税率为：" << endl;
            cin >> stamp_tax;
            cout << "企业所得税率为：" << endl;
            cin >> corporate_income_tax;
            text.close();
            text.clear();
            ofstream text1("Tax_rate.txt");
            text1 << name << " " << value_added_tax << " " << property_tax << " " << land_use_tax << " " << resource_tax
                 << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
            cout << "修改成功" << endl;
            break;
        }
        else
        {
            cout << "请求被拒绝" << endl;
            goto re;
        }
    case '3':
        if(Level == 2)
        {
            char End;
            cout << "当前审交状况为：";
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            if(stamp_tax_date)
                cout << "审交" << endl;
            else cout << "不审交" << endl;
            cout << "是否更改(1 0)" << endl;
            bool judge;
            cin >> judge;
            text.close();
            text.clear();
            if(judge)
            {
                if(stamp_tax_date)
                    stamp_tax_date = 0;
                else stamp_tax_date = 1;
                ofstream text1("Tax_rate.txt");
                text1 << name << " " << value_added_tax << " " << property_tax << " " << land_use_tax << " " << resource_tax
                    << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
                cout << "修改完成，当前状态为：";
                if(stamp_tax_date)
                    cout << "审交" << endl;
                else cout << "不审交" << endl;
            }
            cout << endl << "0.返回" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "无效操作!" << endl;
            }
        }
        else
        {
            cout << ">请求被拒绝！" << endl;
            goto re;
        }
        break;
    case '0':
        return false;       //返回假值,返回主菜单
    default:
        cout << "无效操作！" << endl;
        goto re;
    }
    return true;
}
