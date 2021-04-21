#include<iostream>


class Base
{
public:

    //只要有一个纯虚函数，这个类就叫做抽象类
    //无法实例化
    //子类如果不重写父类中的纯虚函数，那么子类也属于抽象类
    virtual void func() = 0;//纯虚函数，基类内的函数本来也不调用所以使用纯虚函数

};

class Son : public Base
{
public:

};




void test01()
{
    //Base b; 抽象类无法实例化

}

int main(void)
{
    test01();

    return 0;
}
