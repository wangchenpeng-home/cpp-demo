#include <bits/stdc++.h>
using namespace std;

/*
��ֵ����ͬvectorһ��
��С����һ��������û������
����ɾ������
    1.ͷ��ͷɾ
        push_front();
        pop_front();
    2.β��
        push_back();
        pop_back();
    3.insert,erase,clear��������vectorһ��
���ݴ�ȡ
    deque<int> dq;
    dq.at();  dq[i]; dq.front()//��һ��Ԫ��; de.end()//���һ��Ԫ��;
deque������
    sort(iterator begin, iterator end);//vectorҲ������
*/
void myprint(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//ֻ��
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    //����deque
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
