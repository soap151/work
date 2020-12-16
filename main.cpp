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
    Login();                                //登录
    bool EXECUTE = true;                    //执行
    while(EXECUTE)                          //循环
    {
        Menu_main();                        //主菜单
        EXECUTE = Menu_main_control();      //结束
    }
    return 0;
}
