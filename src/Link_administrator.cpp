#include "Link_administrator.h"

Link_administrator::Link_administrator()
{
    head = NULL;
    length = 0;
}
void Link_administrator::Add()
{
    length++;
    Administrator *fresh = new Administrator;
    fresh->Change();
    Administrator *seek = head;      //����ָ��
    if(head == NULL)                 //���ͷΪ��
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
Administrator* Link_administrator::Head()
{
    return head;
}
void Link_administrator::Write()
{
    ofstream text("Administrator.txt");
    Administrator *note = head;
    text << length << " ";
    while(note != NULL)
    {
        text << note->Name() << ' ' << note->Pass() << ' ';    //д���ļ�
        note = note->Next();
    }
    text.close();
}
void Link_administrator::Read()
{
    ifstream text("Administrator.txt");
    if(text)
    {
        string Name;
        string Pass;
        text >> length;
        for(int i=0; i<length; i++)     //��û���ļ�ĩβʱ
        {
            text >> Name >> Pass;
            Administrator *fresh = new Administrator(Name,Pass);
            Administrator *seek = head;         //����ָ��
            if(head == NULL)                //���ͷΪ��
            {
                head = fresh;
            }
            else
            {
                while(seek->Next() != NULL)         //ֱ���ҵ�β
                {
                    seek = seek->Next();
                }
                seek->SetNext(fresh);
            }
        }
        text.close();
    }
}
bool Link_administrator::Verify(string Name, string Pass)
{
    Administrator *note = head;
    while(note != NULL)
    {
        if(note->Name() == Name && note->Pass() == Pass)    return true;
        else    note = note->Next();
    }
    return false;
}
void Link_administrator::SetNew()
{
    Administrator *fresh = new Administrator;
    fresh->Change();
    head = fresh;
    length++;
}
void Link_administrator::Show()
{
    Administrator *note = head;
    while(note != NULL)
    {
        note->Show();
        cout << endl;
        note = note->Next();
    }
}
void Link_administrator::ChangePass()
{
    string Name;
    Show();
    cout << "Ҫ���ĵ��û���";
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Administrator *note = head;
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
void Link_administrator::Change()
{
    string Name;
    Show();
    cout << "Ҫ���ĵ��û���";
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Administrator *note = head;
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
bool Link_administrator::Verify(string Name)
{
    Administrator *note = head;
    while(note != NULL)
    {
        if(note->Name() == Name)    return true;
        else    note = note->Next();
    }
    return false;
}
void Link_administrator::Delete()
{
    string Name;
    Show();
    cout << "Ҫɾ�����û���" << endl;
    while(cin >> Name)
    {
        if(Verify(Name))        //����ҵ��������
        {
            Administrator *note = head;
            Administrator *die = NULL;
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
