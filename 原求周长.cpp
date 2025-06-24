#include <iostream>

const double PI = 3.14;

using namespace std;

class Circle
{
public:
    //属性
    //半径
    int cir_r;

    //行为
    //获取周长
    double circle_perimeter();
};

double Circle::circle_perimeter()
{
    return 2 * PI * cir_r;
}

int main(void)
{
    Circle cir1 = {2};
    double i = cir1.circle_perimeter();

    cout << i;

    return 0;
}
