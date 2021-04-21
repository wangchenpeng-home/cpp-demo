/*
������     vector
�㷨��     for_each
������:    vector<int>::iterator
*/

/*
vector�Ĺ��캯��
    vector<T> v1;

    vector<T> v2(v1.begin(), v1.end());

    vector<T> v3(10, 100);

    vector<T> v4(v3);
vector�ĸ�ֵ����
    vector<T> v1;
    Vector<T> v2 = v1;

    vector<T> v3;
    v3.assign(v1.begin(), v1.end());

    vector<T> v4;
    v4.assign(10, 100);
vector�������ʹ�С
    v1.empty();//�п�
    v1.capacity();//����
    v1.size();//��С
    v1.resize(int n);//ָ����������λnum
    v1.resize(int num, elem);
vector�Ĳ���ɾ��
    v1.push_back(elem);//��巨
    v1.pop_back();//ɾ�����һ����
    v1.insert(const_iterator pos, elem);//pos������elem.
    v1.insert(const_iterator pos, int num, elem);//����num��elem
    v1.erase(const_iterator pos);//ɾ��pos����Ԫ��
    v1.erase(const_iterator start, const_iterator end);//ɾ����������Ԫ��
    v1.clear();//���
vector�����ݴ�ȡ
    v1[i];
    v1.at(i);
    v1.front();//��һ��Ԫ��
    v1.back();//���һ��Ԫ��
    for_each(v.begin(), v.end(), myprint);
vector����������
    v1.swap(v2);
    vector<T>(v1).swap(v1);//��������������С,����СԶС������ʱʹ��
    vector<T>(v1);//��������������������
vector��Ԥ������,�������������
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

    //�������в�������
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
/*
    //ͨ��������������������
    vector<int>::iterator itBegin = v.begin();//��ʼ������
    vector<int>::iterator itEnd = v.end();//������������ֻ�����һ��Ԫ�ص���һ��λ��

    //��һ�ֱ�����ʽ
    while(itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    */
    /*
    //�ڶ��ֱ�����ʽ
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    */
    //�����ֱ�����ʽ STL�ṩ��for_each ����ͷ�ļ���algorithm
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
        cout << "������ " << it->myname << " ���䣺" << it -> myage << endl;;
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
        cout << "������ " << (*it)->myname << " ���䣺" << (*it) -> myage << endl;;
    }

}

//����Ƕ������
void test04()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //С�����в�������
    for(int i = 0; i < 4; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
        v3.push_back(i+2);
        v4.push_back(i+3);
    }

    //��������в���С����
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //ͨ������������
    for(vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //(*it)----��ʡ��һ��С����
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << "<" << *vit << "> ";
        }
        cout << endl;
    }//*vit��int���͵�

}





int main(void)
{

    test04();

    return 0;
}
