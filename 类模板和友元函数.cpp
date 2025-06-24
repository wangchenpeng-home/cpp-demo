#include <iostream>
using namespace std;

//通过全局函数打印信息

//类外实现需要提前告知编译器该函数存在
template <class T1, class T2>
class Person;


template <class T1, class T2>
void printPerson2(Person<T1, T2> P)
{
    cout << "姓名： " << P.my_name << " 年龄： " << P.my_age << endl;
}

template<class T1, class T2>
class Person
{
    //全局函数 类内实现
    friend void printPerson(Person<T1, T2> P)
    {
        cout << "姓名： " << P.my_name << " 年龄： " << P.my_age << endl;
    }

    //全局函数 类外实现
    //类外实现加空模板
    //类外实现需要让编译器提前知道有这个函数
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

//全局函数类内实现
void test01()
{
    Person<string,int> P("Tom", 24);
    printPerson(P);

}


//全局函数类外实现
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
