#include "Link_Enterprise.h"

Link_enterprise::Link_enterprise()
{
    head = NULL;
    length = 0;
}
void Link_enterprise::Add()
{
    length++;
    Enterprise *fresh = new Enterprise;
    fresh->Change();
    Enterprise *seek = head;      //查找指针
    if(head == NULL)          //如果头为空
    {
        head = fresh;
    }
    else
    {
        while(seek->Next() != NULL)      //直到找到尾
        {
            seek = seek->Next();
        }
        seek->SetNext(fresh);
    }
}
Enterprise* Link_enterprise::Head()
{
    return head;
}
void Link_enterprise::Write()
{
    ofstream text("Enterprise.txt");
    Enterprise *note = head;
    text << length << " ";
    while(note != NULL)
    {
        text << note->Bussiness() << ' ' << note->Legal_representative() << ' ' << note->Assets() << ' '
        << note->Employees() << ' ' << note->Land_use_area() << ' ' << note->Original_value_property() << ' ';
        note = note->Next();
    }
    text.close();
}
void Link_enterprise::Read()
{
    ifstream text("Enterprise.txt");
    if(text)
    {
        string Bussiness;
        string Legal_representative;
        double Assets;
        int Employees;
        double Land_use_area;
        double Original_value_property;
        text >> length;
        for(int i=0; i<length; i++)         //当没到文件末尾时
        {
            text >> Bussiness >> Legal_representative >> Assets >> Employees
                 >> Land_use_area >> Original_value_property; //读文件
            Enterprise *fresh = new Enterprise(Bussiness,Legal_representative,Assets,
                                               Employees,Land_use_area,Original_value_property);
            Enterprise *seek = head;            //跟随指针
            if(head == NULL)                //如果头为空
            {
                head = fresh;
            }
            else
            {
                while(seek->Next() != NULL) //直到找到尾
                {
                    seek = seek->Next();
                }
                seek->SetNext(fresh);
            }
        }
        text.close();
    }
}

bool Link_enterprise::Verify(string Bussiness)
{
    Enterprise *note = head;
    while(note != NULL)
    {
        if(note->Bussiness() == Bussiness)    return true;
        else    note = note->Next();
    }
    return false;
}

void Link_enterprise::Show()
{
    Enterprise *note = head;
    while(note != NULL)
    {
        note->Show();
        cout << endl;
        note = note->Next();
    }
}

void Link_enterprise::Change()
{
    string Bussiness;
    Show();
    cout << "要更改的用户：";
    while(cin >> Bussiness)
    {
        if(Verify(Bussiness))        //如果找到了这个人
        {
            Enterprise *note = head;
            while(note != NULL)
            {
                if(note->Bussiness() == Bussiness)
                {
                    note->Change();
                    break;
                }
                else    note = note->Next();
            }
            break;
        }
        else
            cout << "未查询到该企业，请确认企业名称后重新输入!" << endl;
    }
}

void Link_enterprise::Search()
{
    string Bussiness;
    char End;
    Enterprise *note = head;
    cout << "查找企业的名称：" << endl;
    cin >> Bussiness;
    while(note != NULL)
    {
        if(note->Bussiness() == Bussiness)
        {
            note->Show();
            cout << "0.返回" << endl;
            while(cin >> End)
            {
                if(End == '0')      return;
                else    cout << "无效操作!" << endl;
            }
        }
        else
            note = note->Next();
    }
    cout << "无法查询到该企业" << endl;
}
void Link_enterprise::Sort()
{
    Enterprise *note = head;
    Enterprise *jackal = NULL;
    Enterprise temp;
    while(note != NULL)
    {
        jackal = note;
        while(jackal != NULL)
        {
            if(jackal->Bussiness() < note->Bussiness())
            {
                temp = *jackal;
                *jackal = *note;
                *note = temp;
            }
            jackal = jackal->Next();
        }
        note->Show();
        cout << endl;
        note = note->Next();
    }
}

