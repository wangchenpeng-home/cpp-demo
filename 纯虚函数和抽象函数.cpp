#include<iostream>


class Base
{
public:

    //ֻҪ��һ�����麯���������ͽ���������
    //�޷�ʵ����
    //�����������д�����еĴ��麯������ô����Ҳ���ڳ�����
    virtual void func() = 0;//���麯���������ڵĺ�������Ҳ����������ʹ�ô��麯��

};

class Son : public Base
{
public:

};




void test01()
{
    //Base b; �������޷�ʵ����

}

int main(void)
{
    test01();

    return 0;
}
