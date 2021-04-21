#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class RecentCounter {
    queue<int> Q;
public:
    RecentCounter() {
    }
 int ping(int t) {
        Q.push(t);
        while(Q.front() < t-3000)
        {
            Q.pop();
        }
        return Q.size();
    }
};
int main(void)
{
    RecentCounter R;
    cout << R.ping(1) << endl;
    cout << R.ping(100) << endl;
    cout << R.ping(3001) << endl;
    cout << R.ping(3002) << endl;
    return 0;
}
