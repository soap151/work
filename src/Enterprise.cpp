#include "Enterprise.h"

Enterprise::Enterprise(string Bussiness, string Legal_representative, double Assets, int Employees,
               double Land_use_area, double Original_value_property)
{
    bussiness = Bussiness;
    legal_representative = Legal_representative;
    assets = Assets;
    employees = Employees;
    land_use_area = Land_use_area;
    original_value_property = Original_value_property;
    next = NULL;
}
Enterprise::Enterprise()
{
    next = NULL;
}
void Enterprise::Change()
{
    cout << "��ҵ���ƣ�" << endl;
    cin >> bussiness;
    cout << "���˴���" << endl;
    cin >> legal_representative;
    cout << "�ʲ��ܶ�" << endl;
    cin >> assets;
    cout << "ְ����" << endl;
    cin >> employees;
    cout << "����ʹ�����" << endl;
    cin >> land_use_area;
    cout << "����ԭֵ" << endl;
    cin >> original_value_property;
}
Enterprise* Enterprise::Next()
{
    return next;
}
void Enterprise::SetNext(Enterprise *Next)
{
    next = Next;
}

Enterprise* Enterprise::operator = (Enterprise &a)
{
    bussiness = a.bussiness;
    legal_representative = a.legal_representative;
    assets = a.assets;
    employees = a.employees;
    land_use_area = a.land_use_area;
    original_value_property = a.original_value_property;
    return this;
}
string Enterprise::Bussiness()
{
    return bussiness;
}
string Enterprise::Legal_representative()
{
    return legal_representative;
}
double Enterprise::Assets()
{
    return assets;
}
int Enterprise::Employees()
{
    return employees;
}
double Enterprise::Land_use_area()
{
    return land_use_area;
}
double Enterprise::Original_value_property()
{
    return original_value_property;
}
void Enterprise::Show()
{
    cout << "��ҵ���ƣ�" << bussiness << endl;;
    cout << "���˴���" << legal_representative << endl;
    cout << "�ʲ��ܶ" << assets << endl;
    cout << "Ա������" << employees << endl;;
    cout << "����ʹ�������" << land_use_area << endl;
    cout << "����ԭֵ��" << original_value_property << endl;
}
