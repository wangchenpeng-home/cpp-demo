#include<iostream>
using namespace std;
#include<set>//按照二叉树进行插入

/*
set大小和交换
size();
empty();
swap(set<auto> S);
set插入删除
insert();
clear();
erase(pos);按位置删除
erase(begin, end);按照区间删除
erase(elem);//按值删除
set查找和统计
find(val);//成功时返回pos迭代器,失败时返回end();
count(val);//只有0或1
set和multiset的区别
1.set不可以插入重复数据multiset可以
2.set插入数据时会返回插入结果，表示成功，
    返回的是pair<set<elemtype>::iterator pos, bool>类型
3.mnultiset不会检测数据，所以可以重复插入

pair对组的创建
1.pair<type, type> p (value1, value2);
2.pair<type, type> p = make_pair(value1, value2);

访问时用p.first和p.second读取

set的容器排序，改变顺序为由大到小
1.对于内置数据类型--通过仿函数-重载();
class Compare
{
public:
    bool operator()(const int v1,const int v2)
    {
        return v1 > v2;
    }
}
构造时应用set<int, Compare> S；
*/


void printSet(set<int> &S)
{
    for(set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    set<int> S;

    //set插入数据只有insert
    S.insert(2);
    S.insert(5);
    S.insert(1);
    S.insert(3);
    S.insert(4);

    printSet(S);

    cout << "再次插入一个4后\n";
    S.insert(4);
    printSet(S);
    //set插入时自动排序，而且没有重复元素
    cout << "S2's  value:\n";
    set<int> S2(S);
    printSet(S2);
    cout << "S3's  value:\n";
    set<int> S3;
    S3 = S2;
    printSet(S3);
}
int main(void)
{
    test();

    return 0;
}
