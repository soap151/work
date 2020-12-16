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
    Administrator *seek = head;      //查找指针
    if(head == NULL)                 //如果头为空
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
        text << note->Name() << ' ' << note->Pass() << ' ';    //写入文件
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
        for(int i=0; i<length; i++)     //当没到文件末尾时
        {
            text >> Name >> Pass;
            Administrator *fresh = new Administrator(Name,Pass);
            Administrator *seek = head;         //跟随指针
            if(head == NULL)                //如果头为空
            {
                head = fresh;
            }
            else
            {
                while(seek->Next() != NULL)         //直到找到尾
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
    cout << "要更改的用户：";
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
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
            cout << "查无此人，请确认信息后重新输入!" << endl;
    }
}
void Link_administrator::Change()
{
    string Name;
    Show();
    cout << "要更改的用户：";
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
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
            cout << "查无此人，请确认信息后重新输入!" << endl;
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
    cout << "要删除的用户：" << endl;
    while(cin >> Name)
    {
        if(Verify(Name))        //如果找到了这个人
        {
            Administrator *note = head;
            Administrator *die = NULL;
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
