#include<iostream>
using namespace std;
class Person{
public:
//this指针本质 指针常量 指针的指向不可休课改
//const Person * const this;
//在成员函数后加const，修饰的是thisi指向，让指针指向的值也不可修改
    int m_A = 0;
    mutable int m_B = 0;
//常函数
    void showPerson() const{
        // this 指向本次调用所用的 Person 对象，类型为 const Person*。
        // this->m_A = 100;  // 编译错误：不能通过 this 修改普通成员。
        // this = nullptr;   // 编译错误：this 本身不能被赋值。
        this->m_B = 100;
    }
};

void test01()
{
    Person p;
    p.showPerson();
}

//常对象
void test02()
{
    const Person p;//在对象前加const变为常对象
    //p.m_A = 200;
    p.m_B = 250;//m_B为特殊值，在常对象下也可以修改
    //常对象只可调用常函数 因为普通成员函数可以修改属性
}

int main(){
    test01();
    test02();
    return 0;
}
