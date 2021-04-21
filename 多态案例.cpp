#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:

    int result(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if(oper == "-")
        {
            return m_num1 - m_num2;
        }
    }

    int m_num1;
    int m_num2;
};

void test01()
{
    Calculator c;
    c.m_num1 = 2;
    c.m_num2 = 10;

    cout << c.m_num1 << " + " << c.m_num2 << " = " << c.result("+") << endl;

    cout << c.m_num1 << " - " << c.m_num2 << " = " << c.result("-") << endl;
}

//利用多态实现计算器
class AbstractCalculator
{
public:
    virtual int getresult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

class AddCalculator :public AbstractCalculator
{
public:
    int getresult()
    {
        return m_Num1 + m_Num2;
    }
};

class SubCalculator :public AbstractCalculator
{
public:
    int getresult()
    {
        return m_Num1 - m_Num2;
    }
};

void test02()
{
    AbstractCalculator *abc = new AddCalculator;

    abc -> m_Num1 = 10;
    abc ->m_Num2 = 4;

    cout << abc -> m_Num1 << " + " << abc ->m_Num2 << " = " << abc ->getresult() << endl;

    delete abc;

    abc = new SubCalculator;

    abc -> m_Num1 = 100;
    abc -> m_Num2 = 40;

    cout << abc -> m_Num1 << " - " << abc -> m_Num2 << " = " << abc ->getresult() << endl;

    delete abc;

}

int main(void)
{
    //test01();
    test02();
    return 0;
}
