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
    cout << "�������û�����" << endl;
    cin >> name;
    cout << "���������룺" << endl;
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
    cout << "�����޸�Ϊ��";
    cin >> password;
}
