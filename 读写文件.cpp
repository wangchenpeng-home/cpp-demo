#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ofstream ofs;

    ofs.open("文本测试.txt", ios::out);

    ofs << "姓名： 张三\n";
    ofs << "年龄： 18\n";

    ofs.close();
}

void test02()
{
    ifstream ifs;
    ifs.open("文本测试.txt", ios::in);
    //判断是否成功打开
    if(!ifs.is_open())
    {
        cout << "文件打开失败!\n";
        return;
    }else
    {
        //打印数据
        //四种方法
        //第一种
        /*
        cout << "第一种方式读取数据\n";
        char buf1[1024] = {0};
        while(ifs >> buf1)
        {
            cout << buf1 << endl;
        }
        */
        /*
        //第二种
        cout << "\n第二种方式读取数据\n";

        char buf2[1024] = {0};
        while(ifs.getline(buf2,sizeof(buf2)))
        {
            cout << buf2 << endl;
        }
        */

         //第三种
        cout << "\n第三种方式读取数据\n";
        string buf3;
        while(getline(ifs, buf3))
        {
            cout << buf3 << endl;
        }
        /*
        //第四种
        cout << "\n第四种方式读取数据，极其不推荐\n";
        char a;
        while((a = ifs.get()) != EOF)
        {
           cout << a << endl;
        }
        */
    }

    ifs.close();
}

int main(void)
{
    test01();
    test02();



    return 0;
}
