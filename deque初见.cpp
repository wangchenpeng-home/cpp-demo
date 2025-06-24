#include <bits/stdc++.h>
using namespace std;

/*
赋值操作同vector一样
大小操作一样，但是没有容量
插入删除操作
    1.头插头删
        push_front();
        pop_front();
    2.尾巴
        push_back();
        pop_back();
    3.insert,erase,clear操作都与vector一样
数据存取
    deque<int> dq;
    dq.at();  dq[i]; dq.front()//第一个元素; de.end()//最后一个元素;
deque的排序
    sort(iterator begin, iterator end);//vector也可以用
*/
void myprint(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//只读
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    //构造deque
    deque<int> dq;

    for(int i = 0; i < 10; i++)
    {
        dq.push_back(i);
    }
    myprint(dq);

    deque<int> dq1(dq.begin(), dq.end());
    myprint(dq1);

    deque<int> dq2(10,100);
    myprint(dq2);

    deque<int> dq3(dq2);
    myprint(dq3);
}

int main(void)
{
    test01();

    return 0;
}
