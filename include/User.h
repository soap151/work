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
        string Name();      //�õ�����
        string Pass();      //�õ�����
        int Level();        //�õ��ȼ�
        void Show();        //��ʾ�û���Ϣ
};

#endif // USER_H
