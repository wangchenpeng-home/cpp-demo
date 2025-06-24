#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>
/*
* `template<class T> T plus<T>`          //加法仿函数
* `template<class T> T minus<T>`         //减法仿函数
* `template<class T> T multiplies<T>`    //乘法仿函数
* `template<class T> T divides<T>`       //除法仿函数
* `template<class T> T modulus<T>`       //取模仿函数
* `template<class T> T negate<T>`        //取反仿函数

* `template<class T> bool equal_to<T>`       //等于
* `template<class T> bool not_equal_to<T>`   //不等于
* `template<class T> bool greater<T>`        //大于
* `template<class T> bool greater_equal<T>`  //大于等于
* `template<class T> bool less<T>`           //小于
* `template<class T> bool less_equal<T>`     //小于等于

* `template<class T> bool logical_and<T>`    //逻辑与
* `template<class T> bool logical_or<T>`     //逻辑或
* `template<class T> bool logical_not<T>`    //逻辑非
*/

void test()
{
    negate<int>n;
    cout << n(20) << endl;

    plus<int>p;
    cout << p(10, 20) <<endl;

    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);

    sort(v.begin(), v.end(), greater<int>());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> b;
    b.push_back(true);
    b.push_back(false);
    b.push_back(true);
    b.push_back(false);

    for(vector<bool>::iterator it = b.begin(); it != b.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> b2;
    b2.resize(b.size());
    transform(b.begin(), b.end(), b2.begin(), logical_not<bool>());

    for(vector<bool>::iterator it = b2.begin(); it != b2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(void)
{
    test();

    return 0;
}
