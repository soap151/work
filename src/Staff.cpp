#include "Staff.h"

Staff::Staff(string Name, string Password, string Realname, string Company,
               string Contact)
{
    name = Name;
    password = Password;
    realname = Realname;
    company = Company;
    contact = Contact;
    level = 1;
    next = NULL;
}
Staff::Staff()
{
    level = 1;
    next = NULL;
}
void Staff::Change()
{
    cout << "用户名：" << endl;
    cin >> name;
    cout << "密码：" << endl;
    cin >> password;
    cout << "姓名" << endl;
    cin >> realname;
    cout << "单位" << endl;
    cin >> company;
    cout << "联系方式" << endl;
    cin >> contact;
}
Staff* Staff::Next()
{
    return next;
}
void Staff::SetNext(Staff *Next)
{
    next = Next;
}
void Staff::ChangePass()
{
    bool right = true;
    string newpass1;
    string newpass2;
    while(right)
    {
        cout << "新密码:";
        cin >> newpass1;
        cout << "再次确认你的密码：" << endl;
        cin >> newpass2;
        if(newpass1 == newpass2)
        {
            password = newpass1;
            right = false;
        }
        else
        {
            cout << "两次密码不一致，请重新输入!" << endl;
        }
    }
}

Staff* Staff::operator = (Staff &a)
{
    name = a.name;
    password = a.password;
    realname = a.realname;
    company = a.company;
    contact = a.contact;
    return this;
}
string Staff::Realname()
{
    return realname;
}
string Staff::Company()
{
    return company;
}
string Staff::Contact()
{
    return contact;
}
void Staff::Show()
{
    User::Show();
    cout << "姓名：" << realname << endl;;
    cout << "单位：" << company << endl;
    cout << "联系方式：" << contact << endl;

}
