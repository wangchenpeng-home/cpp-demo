#include <iostream>

using namespace std;

class Person
{
public:
    //���캯��
    Person()
    {
        cout << "Person���޲������캯������\n";
    }
    Person(int a)
    {
        age = a;
        cout << "Person���в������캯������\n";
    }

    //�������캯��
    Person(const Person &p)
    {
        cout << "Person�Ŀ������캯������\n";
        //������Ĳ�������һ��
        age = p.age;
    }

    ~Person()
    {
        cout << "Person��������������\n";
    }
    int age;
};

void text01()
{
    //1.���ŷ�
    Person p1;
    Person p2(10);
    Person p3(p2);
    //2.��ʾ��
    Person p4;
    Person p5 = Person(10);
    Person p6 = Person(p5);//��������ᱻʹ��������,���ǳ�������������
    //3.��ʽת����
    Person p7 = 10;
    Person p8 = p7;
}

int main(void)
{
    text01();
    return 0;
}
