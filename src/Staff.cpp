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
    cout << "�û�����" << endl;
    cin >> name;
    cout << "���룺" << endl;
    cin >> password;
    cout << "����" << endl;
    cin >> realname;
    cout << "��λ" << endl;
    cin >> company;
    cout << "��ϵ��ʽ" << endl;
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
        cout << "������:";
        cin >> newpass1;
        cout << "�ٴ�ȷ��������룺" << endl;
        cin >> newpass2;
        if(newpass1 == newpass2)
        {
            password = newpass1;
            right = false;
        }
        else
        {
            cout << "�������벻һ�£�����������!" << endl;
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
    cout << "������" << realname << endl;;
    cout << "��λ��" << company << endl;
    cout << "��ϵ��ʽ��" << contact << endl;

}
