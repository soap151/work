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
    cout << "�û���:" << name << endl;
    cout << "����:" << password << endl;
    cout << "Ȩ�޵ȼ�:" << level << endl;
}
