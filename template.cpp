#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

int main(void)
{
    vector<int> v = {-3,1,1,3,4,5};
    vector<int>::iterator it = v.begin();
    v.erase(it);
    cout << *it << endl;
    return 0;
}
