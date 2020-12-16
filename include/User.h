#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;
class User
{
    protected:
        string name;
        string password;
        int level;
    public:
        string Name();      //得到姓名
        string Pass();      //得到密码
        int Level();        //得到等级
        void Show();        //显示用户信息
};

#endif // USER_H
