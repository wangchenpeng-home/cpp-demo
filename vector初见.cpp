/*
容器：     vector
算法：     for_each
迭代器:    vector<int>::iterator
*/

/*
vector的构造函数
    vector<T> v1;

    vector<T> v2(v1.begin(), v1.end());

    vector<T> v3(10, 100);

    vector<T> v4(v3);
vector的赋值操作
    vector<T> v1;
    Vector<T> v2 = v1;

    vector<T> v3;
    v3.assign(v1.begin(), v1.end());

    vector<T> v4;
    v4.assign(10, 100);
vector的容量和大小
    v1.empty();//判空
    v1.capacity();//容量
    v1.size();//大小
    v1.resize(int n);//指定容器长度位num
    v1.resize(int num, elem);
vector的插入删除
    v1.push_back(elem);//后插法
    v1.pop_back();//删除最后一个数
    v1.insert(const_iterator pos, elem);//pos出插入elem.
    v1.insert(const_iterator pos, int num, elem);//插入num个elem
    v1.erase(const_iterator pos);//删除pos处的元素
    v1.erase(const_iterator start, const_iterator end);//删除这个区间的元素
    v1.clear();//清空
vector的数据存取
    v1[i];
    v1.at(i);
    v1.front();//第一个元素
    v1.back();//最后一个元素
    for_each(v.begin(), v.end(), myprint);
vector的容器互换
    v1.swap(v2);
    vector<T>(v1).swap(v1);//巧用收缩容量大小,当大小远小于容量时使用
    vector<T>(v1);//代表匿名拷贝对象，无名
vector的预存容量,减少其扩充次数
    v1.reserve(1000);
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Person
{
public:
    Person(string name, int age)
    {
        myname = name;
        myage = age;
    }
    string myname;
    int myage;
};

void myprint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;

    //像容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
/*
    //通过迭代器访问其中数据
    vector<int>::iterator itBegin = v.begin();//起始迭代器
    vector<int>::iterator itEnd = v.end();//结束迭代器，只想最后一个元素的下一个位置

    //第一种遍历方式
    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    */
    /*
    //第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    */
    //第三种遍历方式 STL提供的for_each 他的头文件是algorithm
    for_each(v.begin(), v.end(), myprint);

}

void test02()
{
    vector<Person> vp;

    Person p1("zhangsan", 12);
    Person p2("lisi", 13);
    Person p3("wangwu", 14);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    for(vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << "姓名： " << it->myname << " 年龄：" << it -> myage << endl;;
    }

}

void test03()
{
    vector<Person*> vp;

    Person p1("zhangsan", 12);
    Person p2("lisi", 13);
    Person p3("wangwu", 14);

    vp.push_back(&p1);
    vp.push_back(&p2);
    vp.push_back(&p3);

    for(vector<Person*>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << "姓名： " << (*it)->myname << " 年龄：" << (*it) -> myage << endl;;
    }

}

//容器嵌套容器
void test04()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //小容器中插入数据
    for(int i = 0; i < 4; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
        v3.push_back(i+2);
        v4.push_back(i+3);
    }

    //向大容器中插入小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //通过大容器遍历
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //(*it)----本省是一个小容器
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << "<" << *vit << "> ";
        }
        cout << endl;
    }//*vit是int类型的

}





int main(void)
{

    test04();

    return 0;
}
