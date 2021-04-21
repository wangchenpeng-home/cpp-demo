#include<iostream>
using namespace std;
#include<list>

/*
��С����
size(); empty(); resize(int num);
resize(int num; elem e);ֻ����䣬���ԭ�����ݲ��Ḳ��
����ɾ��
insert(pos, elme);
insert(pos, n, elem);
insert(pos, begin, end);��pos����[begin,end)���������
push_back();
push_front();
pop_back();
pop_front();
clear();
erase(begin, end);
erase(pos);
remove(elem);ɾ��ֵΪelem������
���ݴ�ȡ
front();
back();
��ת������
L.reverse();---vector����һ��reserveԤ���ռ��
L.sort();---Ĭ������
������Ҫ���⺯��
bool compare(int a, int b)
{
    return a > b;
}
L.sort(compare);����
*/

void printList(const list<int>& L)
{
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    //���캯��
    list<int> L1;

    for(int i = 0; i < 10; i++)
    {
        L1.push_back(i);
    }

    printList(L1);

    list<int> L2(L1.begin(), L1.end());

    printList(L2);

    list<int> L3(L2);

    printList(L3);

    list<int> L4(5, 10);

    printList(L4);

    //��ֵ
    L2 = L4;
    printList(L2);
    //����
    L2.swap(L3);
    printList(L2);

    L3.assign(L2.begin(), L2.end());
    printList(L3);

    L3.remove(1);
    printList(L3);
}

int main(void)
{
    test();

    return 0;
}
