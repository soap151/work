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
    cout << "企业名称：" << endl;
    cin >> bussiness;
    cout << "法人代表：" << endl;
    cin >> legal_representative;
    cout << "资产总额" << endl;
    cin >> assets;
    cout << "职工数" << endl;
    cin >> employees;
    cout << "土地使用面积" << endl;
    cin >> land_use_area;
    cout << "房产原值" << endl;
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
    cout << "企业名称：" << bussiness << endl;;
    cout << "法人代表：" << legal_representative << endl;
    cout << "资产总额：" << assets << endl;
    cout << "员工数：" << employees << endl;;
    cout << "土地使用面积：" << land_use_area << endl;
    cout << "房产原值：" << original_value_property << endl;
}
