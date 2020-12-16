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
    Enterprise *seek = head;      //����ָ��
    if(head == NULL)          //���ͷΪ��
    {
        head = fresh;
    }
    else
    {
        while(seek->Next() != NULL)      //ֱ���ҵ�β
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
        for(int i=0; i<length; i++)         //��û���ļ�ĩβʱ
        {
            text >> Bussiness >> Legal_representative >> Assets >> Employees
                 >> Land_use_area >> Original_value_property; //���ļ�
            Enterprise *fresh = new Enterprise(Bussiness,Legal_representative,Assets,
                                               Employees,Land_use_area,Original_value_property);
            Enterprise *seek = head;            //����ָ��
            if(head == NULL)                //���ͷΪ��
            {
                head = fresh;
            }
            else
            {
                while(seek->Next() != NULL) //ֱ���ҵ�β
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
    cout << "Ҫ���ĵ��û���";
    while(cin >> Bussiness)
    {
        if(Verify(Bussiness))        //����ҵ��������
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
            cout << "δ��ѯ������ҵ����ȷ����ҵ���ƺ���������!" << endl;
    }
}

void Link_enterprise::Search()
{
    string Bussiness;
    char End;
    Enterprise *note = head;
    cout << "������ҵ�����ƣ�" << endl;
    cin >> Bussiness;
    while(note != NULL)
    {
        if(note->Bussiness() == Bussiness)
        {
            note->Show();
            cout << "0.����" << endl;
            while(cin >> End)
            {
                if(End == '0')      return;
                else    cout << "��Ч����!" << endl;
            }
        }
        else
            note = note->Next();
    }
    cout << "�޷���ѯ������ҵ" << endl;
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

