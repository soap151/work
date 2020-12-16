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
    Staff *seek = head;      //查找指针
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
        for(int i=0; i<length; i++)         //当没到文件末尾时
        {
            text >> Name >> Pass >> Realname >> Company >> Contact; //读文件
            Staff *fresh = new Staff(Name,Pass,Realname,Company,Contact);
            Staff *seek = head;             //跟随指针
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
    cout << "要更改的用户：";
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
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
            cout << "查无此人，请确认信息后重新输入!" << endl;
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
    cout << "要更改的用户：";
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
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
            cout << "查无此人，请确认信息后重新输入!" << endl;
    }
}
void Link_staff::Delete()
{
    string Name;
    Show();
    cout << "要删除的用户：" << endl;
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
        {
            Staff *note = head;
            Staff *die = NULL;
            while(note != NULL)
            {
                if(note->Name() == Name)
                {
                    if(note == head)            //如果删掉头
                        head = note->Next();
                    else                        //不删头
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
            cout << "查无此人，请确认信息后重新输入!" << endl;
    }
}
void Link_staff::Search()
{
    string Name;
    char End;
    Staff *note = head;
    cout << "查找人的用户名：" << endl;
    cin >> Name;
    while(note != NULL)
    {
        if(note->Name() == Name)
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
    cout << "查无此人" << endl;
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

