#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Administrator.h"
#include "Staff.h"
#include "Enterprise.h"
#include "Link_Enterprise.h"
#include "Link_administrator.h"
#include "Link_staff.h"

int Level;                          //��¼�û��ĵȼ�
string Or_reader;                   //��¼��ǰ��¼���û�
bool Menu_main_control();           //���˵����ܿ���
bool FirstLogin();                  //����Ƿ�Ϊ��һ�ε�¼
void Login();                       //��¼ϵͳ
void Menu_level(int level);         //�ȼ��˵�
void Menu_main();                   //���˵�
void Menu_user();                   //����Ա����Ӳ˵�
bool User_Management();             //����Ա��ع���
void Menu_staff();                  //�û�����Ӳ˵�
bool Staff_Management();            //�û���ع���
void Menu_enterprise();             //��ҵ�����Ӳ˵�
void Menu_Search();                 //��ҵ��ѯ�Ӳ˵�
bool Enterprise_Management();       //��ҵ��ع���
void Menu_tax();                    //˰����ع���
bool Tax_Management();              //˰������Ӳ˵�
//---------------------------------------------------------------
using namespace std;
bool FirstLogin()   //����Ƿ�Ϊ��һ�ε�¼
{
    ifstream text("Administrator.txt");
    return !text;
}
void Login()        //��¼ϵͳ
{
    if(FirstLogin())  //����ǵ�һ�ε�¼
    {
        cout << ">>��⵽��Ϊ��һ�ε�¼�����ڴ�������ϵͳ����Ա�û�" << endl;
        cout << ">>��������˻�:" << endl;
        Link_administrator admin;       //��������
        admin.SetNew();                 //������һ��ϵͳ����Ա
        admin.Write();                  //д���ļ�
        cout << "�����ɹ���" << endl;
        ofstream text("Tax_rate.txt");
        string name = "˰��";
        double value_added_tax;
        double Property_tax;
        double Land_use_tax;
        double resource_tax;
        double stamp_tax;
        double corporate_income_tax;
        bool stamp_tax_date = 0;
        cout << "˰�ʳ�ʼ����" << endl;
        cout << "��������ֵ˰��" << endl;
        cin >> value_added_tax;
        cout << "�����뷿��˰��" << endl;
        cin >> Property_tax;
        cout << "����������ʹ��˰��" << endl;
        cin >> Land_use_tax;
        cout << "��������Դ˰��" << endl;
        cin >> resource_tax;
        cout << "������ӡ��˰��" << endl;
        cin >> stamp_tax;
        cout << "��������ҵ����˰��" << endl;
        cin >> corporate_income_tax;
        text << name << " " << value_added_tax << " " << Property_tax << " " << Land_use_tax << " " << resource_tax << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
        cout << "�������" << endl;
        exit(0);
    }
    //������ǵ�һ�ε�¼
    Link_administrator admin;
    Link_staff staff;
    admin.Read();       //����ϵͳ����Ա�ļ�
    staff.Read();       //�����û��ļ�
    string Name;
    string Password;
    bool login = false;
    cout << ">>����ϵͳ" << endl;
    for(int i=0; i<3 && !login; i++)
    {
        cout << "�û���:";
        cin >> Name;
        cout << "����:";
        cin >> Password;
        if(admin.Verify(Name,Password))     //����ɹ�����ϵͳ����Ա
        {
            cout << "����ɹ�!" << endl;
            Level = 2;
            break;
        }
        else if(staff.Verify(Name,Password))
        {
            cout << "����ɹ�!" << endl;
            Or_reader = Name;           //��ס��ǰ�û�
            Level = 1;
            break;
        }
        else
        {
            if(!login && i != 2)
                cout << ">�û�����������󣬻�ʣ��" << 2 - i << "�λ���" << endl;
            else if(i == 2 && !login)
            {
                cout << ">����������!" << endl;
                exit(0);
            }
        }
    }
}
void Menu_level(int level)
{
    if(level == 2)  cout << ">�������Ϊϵͳ����Ա" << endl;
    if(level == 1)  cout << ">��ӭ����!" << Or_reader << endl;
}

void Menu_main()         //���˵�
{
    system("cls");
    cout << "                   ��ҵ˰�����ϵͳ" << endl;
    Menu_level(Level);
    cout << endl;
    cout << "1.����Ա���" << endl;
    cout << "2.�û����" << endl;
    cout << "3.��ҵ���" << endl;
    cout << "0.�˳�ϵͳ" << endl;
}
void Menu_user()
{
    system("cls");
    cout << "1.����Ա��Ϣ����" << endl;
    cout << "2.����Ա��Ϣ�޸�" << endl;
    cout << "3.����Ա��Ϣɾ��" << endl;
    cout << "4.����Ա��Ϣ��ʾ" << endl;
    cout << "5.����Ա�����޸�" << endl;
    cout << "0.�������˵�" << endl;
}
void Menu_staff()
{
    system("cls");
    cout << "1.�û���Ϣ����" << endl;
    cout << "2.�û���Ϣ�޸�" << endl;
    cout << "3.�û���Ϣɾ��" << endl;
    cout << "4.�û���Ϣ��ѯ" << endl;
    cout << "5.�û���Ϣ��ʾ" << endl;
    cout << "0.�������˵�" << endl;
}
void Menu_enterprise()
{
    system("cls");
    cout << "1.��ҵ��Ϣ����" << endl;
    cout << "2.��ҵ��Ϣ�޸�" << endl;
    cout << "3.��ҵ��Ϣ��ѯ" << endl;
    cout << "4.����ͳ��" << endl;
    cout << "5.˰�����" << endl;
    cout << "6.˰��ͳ��" << endl;
    cout << "0.�������˵�" << endl;
}
void Menu_tax()
{
    system("cls");
    cout << "1.˰��չʾ" << endl;
    cout << "2.˰���޸�" << endl;
    cout << "3.ӡ��˰��״̬�޸�" << endl;
    cout << "0.�����ϼ��˵�" << endl;
}

//���˵�����-----------------------------------------------------------------
bool Menu_main_control()
{
    char order;
    bool Continue = true;
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        while(Continue)
        {
            if(Level == 1)          //���Ȩ�޵ȼ�����1
            {
                cout << "���󱻾ܾ���" << endl;
                goto re;
            }
            Menu_user();            //�����û������˵�
            Continue = User_Management();
        }
        return true;                //������ֵ������ִ�г���
    case '2':
        while(Continue)
        {
            Menu_staff();          //�����û������˵�
            Continue = Staff_Management();
        }
        return true;
    case '3':
        while(Continue)
        {
            Menu_enterprise();          //������ҵ�����˵�
            Continue = Enterprise_Management();
        }
        return true;
    case '0':
        break;
    default:
        cout << "��Ч������" << endl;
        goto re;      //��������
    }
    return false;                   //���ؼ�ֵ������ִ��
}
//����Ա��ع���---------------------------------------------------
bool User_Management()
{
    char order;
    Link_administrator admin;
    admin.Read();       //����ϵͳ����Ա�ļ�
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        if(Level == 2)
        {
            cout << "1.����һ��ϵͳ����Ա" << endl;
            cout << endl << "0.����" << endl;
            Rein1:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Add();
                admin.Write();
                cout << "��ӳɹ�" << endl;
                break;
            case '0':
                break;
            default:
                cout << "��Ч������" << endl;
                goto Rein1;      //��������
            }
            break;
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
    case '2':
        if(Level == 2)
        {
            cout << "1.�޸�ϵͳ����Ա����Ϣ" << endl;
            cout << endl << "0.����" << endl;
            Rein2:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Change();
                admin.Write();
                cout << "�޸ĳɹ�" << endl;
                break;
            case '0':
                break;
            default:
                cout << "��Ч������" << endl;
                goto Rein2;      //��������
            }
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
        break;
    case '3':
        if(Level == 2)
        {
            cout << "1.ɾ��ϵͳ����Ա" << endl;
            cout << endl << "0.����" << endl;
            Rein3:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.Delete();
                admin.Write();
                cout << "ɾ���ɹ�" << endl;
                break;
            case '0':
                break;
            default:
                cout << "��Ч������" << endl;
                goto Rein3;      //��������
            }
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
        break;
    case '4':
        if(Level == 2)
        {
            char End;
            cout << "ϵͳ����Ա����Ϣչʾ" << endl;
            admin.Show();
            cout << endl << "0.����" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "��Ч����!" << endl;
            }
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
        break;
    case '5':
        if(Level == 2)
        {
            cout << "1.�޸�ϵͳ����Ա������" << endl;
            cout << endl << "0.����" << endl;
            Rein5:
            cin >> order;
            switch(order)
            {
            case '1':
                admin.ChangePass();
                admin.Write();
                cout << "�޸ĳɹ�" << endl;
                break;
            case '0':
                break;
            default:
                cout << "��Ч������" << endl;
                goto Rein5;      //��������
            }
        }
        break;
    case '0':
        return false;       //���ؼ�ֵ,�������˵�
    default:
        cout << "��Ч������" << endl;
        goto re;
    }
    return true;
}
//�û���ع���----------------------------------------------------
bool Staff_Management()
{
    char order;
    Link_staff staff;
    staff.Read();
    re:
    cin >> order;
    switch(order)
    {
    case '1':
            if(Level == 2)
            {
                staff.Add();
                staff.Write();
                cout << "��ӳɹ�" << endl;
            }
            else
            {
                cout << ">���󱻾ܾ���" << endl;
                goto re;
            }
            break;
    case '2':
            if(Level == 2)
            {
                staff.Change();
                staff.Write();
                cout << "�޸ĳɹ�" << endl;
            }
            else if(Level == 1)
            {
                if(staff.Verify(Or_reader))
                {
                    Staff *note = staff.Head();
                    while(note != NULL)
                    {
                        if(note->Name() == Or_reader)
                        {
                            note->Change();
                            break;
                        }
                        else note = note->Next();
                    }
                    staff.Write();
                    break;
                }
                cout << "�޸ĳɹ�" << endl;
            }
            break;
    case '3':
            if(Level == 2)
            {
                staff.Delete();
                staff.Write();
                cout << "ɾ���ɹ�" << endl;
            }
            else
            {
                cout << ">���󱻾ܾ���" << endl;
                goto re;
            }
            break;
    case '4':
            if(Level == 2)
            {
                staff.Search();
            }
            else if(Level == 1)
            {
                char End;
                Staff *note = staff.Head();
                while(note != NULL)
                {
                    if(note->Name() == Or_reader)
                    {
                        note->Show();
                        cout << "0.����" << endl;
                        while(cin >> End)
                        {
                            if(End == '0')      break;
                            else    cout << "��Ч����!" << endl;
                        }
                    }
                    else note = note->Next();
                    break;
                }
            }
            break;
    case '5':
            if(Level == 2)
            {
                char End;
                cout << "�û���Ϣչʾ" << endl;
                staff.Sort();
                cout << endl << "0.����" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else cout << "��Ч����!" << endl;
                }
            }
            else
            {
                cout << ">���󱻾ܾ���" << endl;
                goto re;
            }
            break;
    case '0':
        return false;       //���ؼ�ֵ,�������˵�
    default:
        cout << "��Ч������" << endl;
        goto re;
    }
    return true;
}
//��ҵ��ع���---------------------------------------------
bool Enterprise_Management()
{
    char order;
    Link_enterprise link_enterprise;
    link_enterprise.Read();        //������ҵ�ļ�
    re:
    cin >> order;
    bool Continue1 = true;
    switch(order)
    {
    case '1':
        if(Level == 2)
        {
            link_enterprise.Add();
            link_enterprise.Write();
            cout << "��ӳɹ�" << endl;
            break;
        }
        else
        {
            cout << "���󱻾ܾ�" << endl;
            goto re;
        }
    case '2':
        if(Level == 2)
        {
            link_enterprise.Change();
            link_enterprise.Write();
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        else
        {
            cout << "���󱻾ܾ�" << endl;
            goto re;
        }
    case '3':
        link_enterprise.Search();
        break;

    case '4':
            if(Level == 2)
            {
                char End;
                cout << "��ҵ��Ϣչʾ" << endl;
                link_enterprise.Sort();
                cout << endl << "0.����" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else cout << "��Ч����!" << endl;
                }
            }
            else
            {
                cout << ">���󱻾ܾ���" << endl;
                goto re;
            }
            break;
    case '5':
            while(Continue1)
            {
                Menu_tax();           //����˰������˵�
                Continue1 = Tax_Management();
            }
            break;
    case '6':
            {

                ifstream text("Tax_rate.txt");
                string name;
                double value_added_tax;
                double property_tax;
                double land_use_tax;
                double resource_tax;
                double stamp_tax;
                double corporate_income_tax;
                bool stamp_tax_date;
                text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
                char End;
                Enterprise* notes;
                notes = link_enterprise.Head();
                string bussiness;                             //��ҵ����
                string legal_representative;                  //���˴���
                double assets;                                //�ʲ��ܶ�
                int employees;                                //ְ����
                double land_use_area;                         //����ʹ�����
                double original_value_property;               //����ԭֵ
                cout << "��������Ҫ�������ҵ��";
                cin >> bussiness;
                while(notes != NULL)
                {
                    if(notes->Bussiness() == bussiness)
                    {
                        notes->Show();
                        bussiness = notes->Bussiness();                             //������ҵ����
                        legal_representative = notes->Legal_representative();       //���ط��˴���
                        assets = notes->Assets();                                   //�����ʲ��ܶ�
                        assets = notes->Employees();                                //����ְ����
                        land_use_area = notes->Land_use_area();                     //��������ʹ�����
                        original_value_property = notes->Original_value_property(); //���ط���ԭֵ
                        cout << "0.����" << endl;
                        while(cin >> End)
                        {
                            if(End == '0')      break;
                            else    cout << "��Ч����!" << endl;
                        }
                        break;
                    }
                    else
                    notes = notes->Next();
                }
                double business_income;
                double operating_costs;
                double other_expenses;
                double intput_tax;
                double output_tax;
                cout << endl << "������Ӫҵ����" << endl;
                cin >> business_income;
                cout << endl << "������Ӫҵ�ɱ�" << endl;
                cin >> operating_costs;
                cout << endl << "��������������" << endl;
                cin >> other_expenses;
                double Value_added_tax;
                double Property_tax;
                double Land_use_tax;
                double Resource_tax;
                double Stamp_tax;
                double Corporate_income_tax;
                cout << "����ҵ�Ƿ�Ϊԭ��������ҵ(����1 0)" << endl;
                bool judge1;
                cin >> judge1;
                if(judge1)
                {
                    Value_added_tax = (business_income - operating_costs - other_expenses) * value_added_tax;
                }
                else
                {
                    cout << endl << "���������˰��" << endl;
                    cin >> intput_tax;
                    cout << endl << "����������˰��" << endl;
                    cin >> output_tax;
                    Value_added_tax = output_tax - intput_tax;
                    if(Value_added_tax <= 0)
                        Value_added_tax = 0;
                }
                Property_tax = property_tax * original_value_property / 12;
                Land_use_tax = land_use_tax * land_use_area / 12;
                cout << "����ҵ�Ƿ�Ϊ��Դ��������ҵ(����1 0)" << endl;
                bool judge2;
                cin >> judge2;
                if(judge2)
                {
                    Resource_tax = resource_tax * (business_income - operating_costs);
                }
                else Resource_tax = 0;
                if(stamp_tax_date)
                {
                    Stamp_tax = stamp_tax * business_income;
                }
                else Stamp_tax = 0;
                if(employees <= 300 && assets <= 50000000)
                {
                    if(assets <= 1000000)
                      Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax * 0.2;
                    else if(assets > 1000000 && assets <= 3000000)
                        Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax * 0.4;
                    else Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax;
                }

                else Corporate_income_tax = (business_income - operating_costs - other_expenses) * corporate_income_tax;
                cout << "��ֵ˰Ϊ��" << Value_added_tax << endl;
                cout << "����˰Ϊ��" << Property_tax << endl;
                cout << "����ʹ��˰Ϊ��" << Land_use_tax << endl;
                cout << "��Դ˰Ϊ��" << Resource_tax << endl;
                cout << "ӡ��˰Ϊ��" << Stamp_tax << endl;
                cout << "��ҵ����˰Ϊ��" << Corporate_income_tax << endl;
                cout << "�ϼƣ�" << Value_added_tax + Property_tax + Land_use_tax + Resource_tax + Stamp_tax + Corporate_income_tax << endl;
                cout << "�ۺ�����Ϊ��" << (business_income - operating_costs - other_expenses) - (Value_added_tax + Property_tax + Land_use_tax + Resource_tax + Stamp_tax + Corporate_income_tax) << endl;
                cout << "0.����" << endl;
                while(cin >> End)
                {
                    if(End == '0')      break;
                    else    cout << "��Ч����!" << endl;
                }
                break;
            }
            break;

    case '0':
        return false;       //���ؼ�ֵ,�������˵�
    default:
        cout << "��Ч������" << endl;
        goto re;
    }
    return true;
}
//˰����ع���--------------------------------------------
bool Tax_Management()
{
    char order;
    re:
    cin >> order;
    switch(order)
    {
    case '1':
        if(Level <= 2)
        {
            char End;
            cout << "˰����Ϣչʾ" << endl;
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            cout << "��ֵ˰��Ϊ��    " << value_added_tax << endl;
            cout << "����˰��Ϊ��    " << property_tax << endl;
            cout << "����ʹ��˰��Ϊ��" << land_use_tax << endl;
            cout << "��Դ˰��Ϊ��    " << resource_tax << endl;
            cout << "ӡ��˰��Ϊ��    " << stamp_tax << endl;
            cout << "��ҵ����˰��Ϊ��" << corporate_income_tax << endl;
            cout << endl << "0.����" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "��Ч����!" << endl;
            }
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
        break;
    case '2':
        if(Level == 2)
        {
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            cout << "��ֵ˰��Ϊ��" << endl;
            cin >> value_added_tax;
            cout << "����˰��Ϊ��" << endl;
            cin >> property_tax;
            cout << "����ʹ��˰��Ϊ��" << endl;
            cin >> land_use_tax;
            cout << "��Դ˰��Ϊ��" << endl;
            cin >> resource_tax;
            cout << "ӡ��˰��Ϊ��" << endl;
            cin >> stamp_tax;
            cout << "��ҵ����˰��Ϊ��" << endl;
            cin >> corporate_income_tax;
            text.close();
            text.clear();
            ofstream text1("Tax_rate.txt");
            text1 << name << " " << value_added_tax << " " << property_tax << " " << land_use_tax << " " << resource_tax
                 << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
            cout << "�޸ĳɹ�" << endl;
            break;
        }
        else
        {
            cout << "���󱻾ܾ�" << endl;
            goto re;
        }
    case '3':
        if(Level == 2)
        {
            char End;
            cout << "��ǰ��״��Ϊ��";
            string name;
            double value_added_tax;
            double property_tax;
            double land_use_tax;
            double resource_tax;
            double stamp_tax;
            double corporate_income_tax;
            bool stamp_tax_date;
            ifstream text("Tax_rate.txt");
            text >> name >> value_added_tax >> property_tax >> land_use_tax >> resource_tax >> stamp_tax >> corporate_income_tax >> stamp_tax_date;
            if(stamp_tax_date)
                cout << "��" << endl;
            else cout << "����" << endl;
            cout << "�Ƿ����(1 0)" << endl;
            bool judge;
            cin >> judge;
            text.close();
            text.clear();
            if(judge)
            {
                if(stamp_tax_date)
                    stamp_tax_date = 0;
                else stamp_tax_date = 1;
                ofstream text1("Tax_rate.txt");
                text1 << name << " " << value_added_tax << " " << property_tax << " " << land_use_tax << " " << resource_tax
                    << " " << stamp_tax << " " << corporate_income_tax << " " << stamp_tax_date << endl;
                cout << "�޸���ɣ���ǰ״̬Ϊ��";
                if(stamp_tax_date)
                    cout << "��" << endl;
                else cout << "����" << endl;
            }
            cout << endl << "0.����" << endl;
            while(cin >> End)
            {
                if(End == '0')      break;
                else    cout << "��Ч����!" << endl;
            }
        }
        else
        {
            cout << ">���󱻾ܾ���" << endl;
            goto re;
        }
        break;
    case '0':
        return false;       //���ؼ�ֵ,�������˵�
    default:
        cout << "��Ч������" << endl;
        goto re;
    }
    return true;
}
