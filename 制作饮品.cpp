#include<iostream>
using namespace std;

class AbstractDrink
{
public:

    //煮水
    virtual void boil() = 0;

    //冲泡
    virtual void brew() = 0;

    //倒茶
    virtual void pourincup() = 0;

    //加入辅料
    virtual void putsomething() = 0;

    //制作饮品
    void makedrink()
    {
        boil();
        brew();
        pourincup();
        putsomething();
    }
};

class Coffee:public AbstractDrink
{
public:
     //煮水
    virtual void boil()
    {
        cout << "煮咖啡\n";
    }

    //冲泡
    virtual void brew()
    {
        cout << "冲咖啡\n";
    }

    //倒茶
    virtual void pourincup()
    {
        cout << "倒咖啡\n";
    }

    //加入辅料
    virtual void putsomething()
    {
        cout << "加入牛奶和糖\n";
    }

};

class Tea:public AbstractDrink
{
public:
     //煮水
    virtual void boil()
    {
        cout << "煮茶叶\n";
    }

    //冲泡
    virtual void brew()
    {
        cout << "冲茶叶\n";
    }

    //倒茶
    virtual void pourincup()
    {
        cout << "倒茶叶\n";
    }

    //加入辅料
    virtual void putsomething()
    {
        cout << "加入其他\n";
    }

};

void dowork(AbstractDrink &abc)
{
    abc.makedrink();
}

void test01()
{
    //做咖啡
    Coffee coffee;
    dowork(coffee);
    cout << "咖啡做好了!\n\n";

    //做茶
    Tea tea;
    dowork(tea);
    cout << "茶做好了!\n";
}

int main(void)
{
    test01();

    return 0;
}
