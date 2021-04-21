#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//一元谓词
class Compare1
{
public:
    bool operator()(int val1)
    {
        return val1 > 20;
    }
};
//二元谓词
class Compare2
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};


void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);

    sort(v.begin(), v.end());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), Compare2());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

int main(void)
{
    test();

    return 0;
}
