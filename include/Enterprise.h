#ifndef ENTERPRISE_H
#define ENTERPRISE_H

#include <User.h>
class Enterprise : public User
{
    public:
        Enterprise(string Bussiness, string Legal_representative, double Assets, int Employees,
               double Land_use_area, double Original_value_property);   //���캯��
        Enterprise();                                 //���캯��
        void Change();                                //�޸���ҵ��Ϣ
        Enterprise* Next();                           //�õ���һ���ڵ�ĵ�ַ
        void SetNext(Enterprise *Next);               //�޸���һ���ڵ�ĵ�ַ
        Enterprise* operator = (Enterprise &a);       //���صȺ�
        string Bussiness();                           //������ҵ����
        string Legal_representative();                //���ط��˴���
        double Assets();                              //�����ʲ��ܶ�
        int Employees();                              //����ְ����
        double Land_use_area();                       //��������ʹ�����
        double Original_value_property();             //���ط���ԭֵ
        void Show();                                  //չʾ��Ϣ
    private:
        string bussiness;                             //��ҵ����
        string legal_representative;                  //���˴���
        double assets;                                //�ʲ��ܶ�
        int employees;                                //ְ����
        double land_use_area;                         //����ʹ�����
        double original_value_property;               //����ԭֵ
        Enterprise *next;                             //��һ���ڵ�ĵ�ַ
};

#endif // ENTERPRISE_H
