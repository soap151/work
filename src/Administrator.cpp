#include "Administrator.h"
Administrator::Administrator(string Name, string Password)
{
    name = Name;
    password = Password;
    level = 2;
    next = NULL;
}
Administrator::Administrator()
{
    level = 2;
    next = NULL;
}
void Administrator::Change()
{
    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> password;
}
Administrator* Administrator::Next()
{
    return next;
}
void Administrator::SetNext(Administrator *Next)
{
    next = Next;
}
void Administrator::ChangePass()
{
    cout << "密码修改为：";
    cin >> password;
}
