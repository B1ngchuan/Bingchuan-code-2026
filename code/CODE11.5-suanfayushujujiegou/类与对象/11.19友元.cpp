#include<iostream>
#include<string>
using namespace std;
//友元
//全局函数 类 成员函数都可做友元

// 前置声明：让下面的函数可以把 Building* 写成参数类型。
class Building;

class Visitor{
    void friends1(Building* Building);
    void friends2(Building* Building);
};

class Building
{
    //friend全局函数是Building好友，可以访问其私有成员
   friend void friends(Building *building);

public:
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
public:
    string m_SittingRoom;//客厅

private:
    string m_BedRoom;
};

//全局函数
void friends(Building *building){
    cout << "好朋友全局函数正在访问："<< building->m_SittingRoom << endl;
    cout << "好朋友全局函数正在访问："<< building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    friends(&building);
}

int main(){
    test01();
    return 0;
}