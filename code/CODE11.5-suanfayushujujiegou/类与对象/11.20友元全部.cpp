#include <iostream>
#include <string>
using namespace std;

//全局函数做友元
namespace p118{

class Building {
    //Building给类外函数goodGay访问私有成员权限
    friend void goodGay(Building* building);

public:
    Building() : m_SittingRoom("客厅"), m_BedRoom("卧室") {}
//
    string m_SittingRoom;

private:
    string m_BedRoom;
};

void goodGay(Building* building){
     // 参数 building 存着一个 Building 对象的地址，用 -> 访问成员。
    cout << "goodGay 访问：" << building->m_SittingRoom << '\n';
    cout << "goodGay 访问：" << building->m_BedRoom << '\n';
}
void test(){
    Building building;
    goodGay(&building);
}
}

// P119 整个类做友元
namespace p119 {

class Building {
    //Building给GoodGay的所有成员函数访问私有成员的权限
    friend class GoodGay;

public:
    Building() : m_SittingRoom("客厅"), m_BedRoom("卧室") {}

    string m_SittingRoom;

private:
    string m_BedRoom;
};

class GoodGay {
public:
     explicit GoodGay(Building& building) : building_(&building) {}

    void visit() {
        cout << "GoodGay::visit 访问：" << building_->m_SittingRoom << '\n';
        cout << "GoodGay::visit 访问：" << building_->m_BedRoom << '\n';
    }

private:
    Building* building_;
};

void test() {
    Building building;
    GoodGay  guest(building);
    guest.visit();
}
}

// P120 只让某个成员函数做友元
namespace p120 {

class Building;  // 先告诉编译器有 Building 这个类型。

class GoodGay {
public:
    explicit GoodGay(Building& building);
    void visit();   // 稍后把这个函数声明为 Building 的友元。
    void visit2();  // 用来对照没有友元权限的情况。

private:
    Building* building_;
};

class Building {
    friend void GoodGay::visit();

public:
    Building() : m_SittingRoom("客厅"), m_BedRoom("卧室") {}

    string m_SittingRoom;

private:
    string m_BedRoom;
};

GoodGay::GoodGay(Building& building){
    building_ = &building;
}
void GoodGay::visit() {
    cout << "GoodGay::visit 访问：" << building_->m_SittingRoom << '\n';
    cout << "GoodGay::visit 访问：" << building_->m_BedRoom << '\n';
}
void GoodGay::visit2() {
    cout << "GoodGay::visit2 访问：" << building_->m_SittingRoom << '\n';
    // cout << building_->m_BedRoom << '\n';  // 编译错误：visit2() 没有友元权限。
}

void test() {
    Building building;
    GoodGay guest(building);
    guest.visit();
    guest.visit2();
}
}
  // namespace p120

int main() {
    cout << "P118 全局函数做友元\n";
    p118::test();

    cout << "\nP119 类做友元\n";
    p119::test();

    cout << "\nP120 成员函数做友元\n";
    p120::test();

    return 0;
}
