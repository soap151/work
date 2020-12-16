#include "Link_staff.h"

Link_staff::Link_staff()
{
    head = NULL;
    length = 0;
}
void Link_staff::Add()
{
    length++;
    Staff *fresh = new Staff;
    fresh->Change();
    Staff *seek = head;      //����ָ��
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
Staff* Link_staff::Head()
{
    return head;
}
void Link_staff::Write()
{
    ofstream text("Staff.txt");
    Staff *note = head;
    text << length << " ";
    while(note != NULL)
    {
        text << note->Name() << ' ' << note->Pass() << ' ' << note->Realname() << ' '
        << note->Company() << ' ' << note->Contact() << ' ';
        note = note->Next();
    }
    text.close();
}
void Link_staff::Read()
{
    ifstream text("Staff.txt");
    if(text)
    {
        string Name;
        string Pass;
        string Realname;
        string Company;
        string Contact;
        text >> length;
        for(int i=0; i<length; i++)         //��û���ļ�ĩβʱ
        {
            text >> Name >> Pass >> Realname >> Company >> Contact; //���ļ�
            Staff *fresh = new Staff(Name,Pass,Realname,Company,Contact);
            Staff *seek = head;             //����ָ��
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
bool Link_staff::Verify(string Name, string Pass)
{
    Staff *note = head;
    while(note != NULL)
    {
        if(note->Name() == Name && note->Pass() == Pass)    return true;
        else    note = note->Next();
    }
    return false;
}
bool Link_staff::Verify(string Name)
{
    Staff *note = head;
    while(note != NULL)
    {
        if(note->Name() == Name)    return true;
        else    note = note->Next();
    }
    return false;
}
void Link_staff::SetNew()
{
    Staff *fresh = new Staff;
    fresh->Change();
    head = fresh;
    length++;
}
void Link_staff::Show()
{
    Staff *note = head;
    while(note != NULL)
    {
        note->Show();
        cout << endl;
        note = note->Next();
    }
}
void Link_staff::ChangePass()
{
    string Name;
    Show();
    cout << "Ҫ���ĵ��û���";
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Staff *note = head;
            while(note != NULL)
            {
                if(note->Name() == Name)
                {
                    note->ChangePass();
                    break;
                }
                else    note = note->Next();
            }
            break;
        }
        else
            cout << "���޴��ˣ���ȷ����Ϣ����������!" << endl;
    }
}
void Link_staff::ChangePass(string Name)
{
    Staff *note = head;
    while(note != NULL)
    {
        if(note->Name() == Name)
        {
            note->ChangePass();
            break;
        }
        else    note = note->Next();
    }
}
void Link_staff::Change()
{
    string Name;
    Show();
    cout << "Ҫ���ĵ��û���";
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Staff *note = head;
            while(note != NULL)
            {
                if(note->Name() == Name)
                {
                    note->Change();
                    break;
                }
                else    note = note->Next();
            }
            break;
        }
        else
            cout << "���޴��ˣ���ȷ����Ϣ����������!" << endl;
    }
}
void Link_staff::Delete()
{
    string Name;
    Show();
    cout << "Ҫɾ�����û���" << endl;
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Staff *note = head;
            Staff *die = NULL;
            while(note != NULL)
            {
                if(note->Name() == Name)
                {
                    if(note == head)            //���ɾ��ͷ
                        head = note->Next();
                    else                        //��ɾͷ
                        die->SetNext(note->Next());
                    delete note;
                    length--;
                    break;
                }
                else
                {
                    die = note;
                    note = note->Next();
                }
            }
            break;
        }
        else
            cout << "���޴��ˣ���ȷ����Ϣ����������!" << endl;
    }
}
void Link_staff::Search()
{
    string Name;
    char End;
    Staff *note = head;
    cout << "�����˵��û�����" << endl;
    cin >> Name;
    while(note != NULL)
    {
        if(note->Name() == Name)
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
    cout << "���޴���" << endl;
}
void Link_staff::Sort()
{
    Staff *note = head;
    Staff *jackal = NULL;
    Staff temp;
    while(note != NULL)
    {
        jackal = note;
        while(jackal != NULL)
        {
            if(jackal->Name() < note->Name())
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

