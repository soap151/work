#ifndef STAFF_H
#define STAFF_H

#include <User.h>
class Staff : public User
{
    public:
        Staff(string Name, string Password, string Realname, string Company,
               string Contact);                  //���캯��
        Staff();                                 //���캯��
        void Change();                           //�޸��û���Ϣ
        void ChangePass();                       //�޸�����
        Staff* Next();                           //�õ���һ���ڵ�ĵ�ַ
        void SetNext(Staff *Next);               //�޸���һ���ڵ�ĵ�ַ
        Staff* operator = (Staff &a);            //���صȺ�
        string Realname();                       //������ʵ����
        string Company();                        //���ص�λ
        string Contact();                        //������ϵ��ʽ
        void Show();                             //չʾ��Ϣ
    private:
        string realname;                         //��ʵ����
        string company;                          //��λ
        string contact;                          //��ϵ��ʽ
        Staff *next;                             //��һ���ڵ�ĵ�ַ
};

#endif // STAFF_H
