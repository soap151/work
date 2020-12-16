#include "User.h"
string User::Name()
{
    return name;
}
string User::Pass()
{
    return password;
}
int User::Level()
{
    return level;
}
void User::Show()
{
    cout << "用户名:" << name << endl;
    cout << "密码:" << password << endl;
    cout << "权限等级:" << level << endl;
}
