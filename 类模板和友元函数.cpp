#include <iostream>
using namespace std;

//ͨ��ȫ�ֺ�����ӡ��Ϣ

//����ʵ����Ҫ��ǰ��֪�������ú�������
template <class T1, class T2>
class Person;


template <class T1, class T2>
void printPerson2(Person<T1, T2> P)
{
    cout << "������ " << P.my_name << " ���䣺 " << P.my_age << endl;
}

template<class T1, class T2>
class Person
{
    //ȫ�ֺ��� ����ʵ��
    friend void printPerson(Person<T1, T2> P)
    {
        cout << "������ " << P.my_name << " ���䣺 " << P.my_age << endl;
    }

    //ȫ�ֺ��� ����ʵ��
    //����ʵ�ּӿ�ģ��
    //����ʵ����Ҫ�ñ�������ǰ֪�����������
    friend void printPerson2<>(Person<T1, T2> P);

public:
    Person(T1 name, T2 age)
    {
        my_name = name;
        my_age = age;
    }



private:
    T1 my_name;
    T2 my_age;

};

//ȫ�ֺ�������ʵ��
void test01()
{
    Person<string,int> P("Tom", 24);
    printPerson(P);

}


//ȫ�ֺ�������ʵ��
void test02()
{
    Person<string,int> P("Tom", 24);
    printPerson2(P);

}

int main(void)
{
    test02();

    return 0;
}
