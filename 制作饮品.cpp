#include<iostream>
using namespace std;

class AbstractDrink
{
public:

    //��ˮ
    virtual void boil() = 0;

    //����
    virtual void brew() = 0;

    //����
    virtual void pourincup() = 0;

    //���븨��
    virtual void putsomething() = 0;

    //������Ʒ
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
     //��ˮ
    virtual void boil()
    {
        cout << "�󿧷�\n";
    }

    //����
    virtual void brew()
    {
        cout << "�忧��\n";
    }

    //����
    virtual void pourincup()
    {
        cout << "������\n";
    }

    //���븨��
    virtual void putsomething()
    {
        cout << "����ţ�̺���\n";
    }

};

class Tea:public AbstractDrink
{
public:
     //��ˮ
    virtual void boil()
    {
        cout << "���Ҷ\n";
    }

    //����
    virtual void brew()
    {
        cout << "���Ҷ\n";
    }

    //����
    virtual void pourincup()
    {
        cout << "����Ҷ\n";
    }

    //���븨��
    virtual void putsomething()
    {
        cout << "��������\n";
    }

};

void dowork(AbstractDrink &abc)
{
    abc.makedrink();
}

void test01()
{
    //������
    Coffee coffee;
    dowork(coffee);
    cout << "����������!\n\n";

    //����
    Tea tea;
    dowork(tea);
    cout << "��������!\n";
}

int main(void)
{
    test01();

    return 0;
}
