#include <iostream>

using namespace std;

class Person
{
public:
    //构造函数
    Person()
    {
        cout << "Person的无参数构造函数调用\n";
    }
    Person(int a)
    {
        age = a;
        cout << "Person的有参数构造函数调用\n";
    }

    //拷贝构造函数
    Person(const Person &p)
    {
        cout << "Person的拷贝构造函数调用\n";
        //将传入的参数拷贝一哈
        age = p.age;
    }

    ~Person()
    {
        cout << "Person的析构函数调用\n";
    }
    int age;
};

void text01()
{
    //1.括号法
    Person p1;
    Person p2(10);
    Person p3(p2);
    //2.显示法
    Person p4;
    Person p5 = Person(10);
    Person p6 = Person(p5);//匿名对象会被使用完后回收,不是程序结束后才析构
    //3.隐式转换法
    Person p7 = 10;
    Person p8 = p7;
}

int main(void)
{
    text01();
    return 0;
}
