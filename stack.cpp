#include<iostream>
using namespace std;
//stack--�Ƚ����
#include<stack>

/*
���캯��
stack<T> T;
stack<T> T1(T);
��ֵ
T1 = T;
���ݴ�ȡ
pop();
push();
top();ջ��
��С����
empty();
size();
*/

/*
����queue--�Ƚ��ȳ�
������һ��ֻ�д�ȡʱ��top()�� ������back(), front();
*/
void test()
{
    stack<int> S;
    for(int i = 0; i < 5; i++)
    {
        S.push(i);
    }
    cout << "ջ�Ĵ�С��" << S.size() << endl;

    while(!S.empty())
    {
        cout << "ջ��Ԫ�أ�" << S.top() << endl;

        cout << "��ջ\n";
        S.pop();

        cout << "ջ�Ĵ�С��" << S.size() << endl;
    }
}

int main(void)
{
    test();

    return 0;
}
