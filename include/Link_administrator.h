#ifndef LINK_ADMINISTRATOR_H
#define LINK_ADMINISTRATOR_H
#include "Administrator.h"
#include <fstream>
class Link_administrator
{
    public:
        Link_administrator();   //Ĭ�Ϲ��캯��
        void SetNew();          //��һ������Ա�Ĺ��캯��
        void Add();             //����¹���Ա
        void Delete();          //ɾ��һ������Ա
        Administrator* Head();  //����ͷָ��
        void Write();           //д���ļ�
        void Read();            //�����ļ�
        void ChangePass();      //�޸�����
        bool Verify(string Name, string Pass);          //���Ҳ���ʵ����Ա
        bool Verify(string Name);                       //���ҹ���Ա
        void Change();          //�޸Ĺ���Ա��Ϣ
        int length;             //������
        void Show();            //��ʾ������Ϣ

    private:
        Administrator *head;
};

#endif // LINK_ADMINISTRATOR_H
