#ifndef LINK_ENTERPRISE_H
#define LINK_ENTERPRISE_H
#include "Enterprise.h"
#include <fstream>
class Link_enterprise
{
    public:
        Link_enterprise();      //Ĭ�Ϲ��캯��
        void Add();             //�����ҵ
        Enterprise* Head();     //����ͷָ��
        void Write();           //д���ļ�
        void Read();            //�����ļ�
        bool Verify(string Name);                  //������ҵ
        void Search();          //������ҵ
        int length;             //������
        void Show();            //��ʾ������Ϣ
        void Change();          //�޸���ҵ��Ϣ
        void Sort();            //���û���������
    private:
        Enterprise *head;
};

#endif // LINK_ENTERPRISE_H
