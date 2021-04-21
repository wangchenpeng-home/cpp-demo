#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:

    char m_Name[64];
    int m_Age;
};

void test01()
{
    //创建流对象
    ofstream ofs;

    //打开文件
    ofs.open("二进制读写.txt", ios::binary | ios::out);
    //合二为一,直接创建加打开
    //ofstream ofs("二进制读写.txt", ios::binary | ios::out);

    //读写文件
    //写文件
    Person p = {"张三", 18};
    ofs.write((const char *)&p , sizeof(Person));//强制转换成const char *

    //关闭文件
    ofs.close();
}
void test02()
{
    ifstream ifs("二进制读写.txt", ios::in | ios::binary);

    if(!ifs.is_open())
    {
        cout << "文件打开失败！\n";
        ifs.close();
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名： " << p.m_Name << endl;
    cout << "年龄： " << p.m_Age << endl;

    ifs.close();
}

int main(void)
{
    test01();
    test02();

    return 0;
}
