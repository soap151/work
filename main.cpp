#include <iostream>
#include "User.h"
#include "Administrator.h"
#include "Staff.h"
#include "Enterprise.h"
#include "Link_Enterprise.h"
#include "Link_administrator.h"
#include "Link_staff.h"
#include "Function.h"
using namespace std;
int main()
{
    Login();                                //��¼
    bool EXECUTE = true;                    //ִ��
    while(EXECUTE)                          //ѭ��
    {
        Menu_main();                        //���˵�
        EXECUTE = Menu_main_control();      //����
    }
    return 0;
}
