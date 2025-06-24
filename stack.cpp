#include<iostream>
using namespace std;
//stack--先进后出
#include<stack>

/*
构造函数
stack<T> T;
stack<T> T1(T);
赋值
T1 = T;
数据存取
pop();
push();
top();栈顶
大小操作
empty();
size();
*/

/*
队列queue--先进先出
操作都一样只有存取时无top()， 但是有back(), front();
*/
void test()
{
    stack<int> S;
    for(int i = 0; i < 5; i++)
    {
        S.push(i);
    }
    cout << "栈的大小：" << S.size() << endl;

    while(!S.empty())
    {
        cout << "栈顶元素：" << S.top() << endl;

        cout << "出栈\n";
        S.pop();

        cout << "栈的大小：" << S.size() << endl;
    }
}

int main(void)
{
    test();

    return 0;
}
