#include<iostream>
using namespace std;
#include<list>

/*
大小操作
size(); empty(); resize(int num);
resize(int num; elem e);只是填充，如果原有数据不会覆盖
插入删除
insert(pos, elme);
insert(pos, n, elem);
insert(pos, begin, end);在pos插入[begin,end)区间的数据
push_back();
push_front();
pop_back();
pop_front();
clear();
erase(begin, end);
erase(pos);
remove(elem);删除值为elem的数据
数据存取
front();
back();
反转和排序
L.reverse();---vector中有一个reserve预留空间的
L.sort();---默认增序
降序需要额外函数
bool compare(int a, int b)
{
    return a > b;
}
L.sort(compare);降序
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
    //构造函数
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

    //赋值
    L2 = L4;
    printList(L2);
    //交换
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
