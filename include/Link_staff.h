#ifndef LINK_STAFF_H
#define LINK_STAFF_H
#include "Staff.h"
#include <fstream>
class Link_staff
{
    public:
        Link_staff();           //Ĭ�Ϲ��캯��
        void SetNew();          //��һ������Ա�Ĺ��캯��
        void Add();             //������û�
        void Delete();          //ɾ��һ���û�
        Staff* Head();          //����ͷָ��
        void Write();           //д���ļ�
        void Read();            //�����ļ�
        bool Verify(string Name, string Pass);          //���Ҳ���ʵ�û�
        bool Verify(string Name);                       //�����û�
        void Search();          //�����û�
        int length;             //������
        void Show();            //��ʾ������Ϣ
        void Change();          //�޸��û���Ϣ
        void ChangePass();      //�޸�����
        void ChangePass(string Name);                   //�޸�����
        void Sort();            //���û���������
    private:
        Staff *head;
};

#endif // LINK_STAFF_H
