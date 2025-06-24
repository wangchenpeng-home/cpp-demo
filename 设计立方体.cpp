#include <iostream>

using namespace std;

class Cube
{
private:
    double M_L;
    double M_W;
    double M_H;
public:
    double get_L()
    {
        return M_L;
    }
    double get_W()
    {
        return M_W;
    }
    double get_H()
    {
        return M_H;
    }
    void set_ML(double a);
    void set_MW(double a);
    void set_MH(double a);
    double get_area();
    double get_volume();
    const bool IsEqual(Cube &a) const
    {
        if(this->M_H == a.get_H() && M_W == a.get_W() && M_L == a.get_W())
            return true;
        return false;
    }
};

void Cube::set_ML(double a)
{
    M_L = a;
}

void Cube::set_MW(double a)
{
    M_W = a;
}

void Cube::set_MH(double a)
{
    M_H = a;
}

double Cube::get_area()
{
    return 2 * (M_L * M_H + M_L * M_W + M_H * M_W);
}

double Cube::get_volume()
{
    return M_L * M_H * M_W;
}

int main(void)
{
    Cube c1;

    c1.set_ML(2.0);
    c1.set_MW(2.0);
    c1.set_MH(2.0);

    cout << "c1圆的面积： " << c1.get_area() << endl;
    cout << "c1圆的体积： " << c1.get_volume() << endl;

    Cube c2;

    c2.set_ML(2.0);
    c2.set_MW(2.0);
    c2.set_MH(2.0);

    cout << "c2圆的面积： " << c2.get_area() << endl;
    cout << "c2圆的体积： " << c2.get_volume() << endl;

    if(c1.IsEqual(c2))
        cout << "俩圆一样\n";
    else
        cout << "俩圆不等\n";

    return 0;
}
