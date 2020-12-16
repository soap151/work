#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <string>
#include "User.h"
using namespace std;
class Administrator : public User
{
    public:
        Administrator(string Name, string Password);    //���캯��
        Administrator();                                //���캯��
        void Change();                                  //�޸��û���Ϣ
        void ChangePass();                              //�޸�����
        Administrator* Next();                          //�õ���һ���ڵ�ĵ�ַ
        void SetNext(Administrator *Next);              //�޸���һ���ڵ�ĵ�ַ
    private:
        Administrator *next;
};

#endif // ADMINISTRATOR_H
