#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test01()
{
    ofstream ofs;

    ofs.open("�ı�����.txt", ios::out);

    ofs << "������ ����\n";
    ofs << "���䣺 18\n";

    ofs.close();
}

void test02()
{
    ifstream ifs;
    ifs.open("�ı�����.txt", ios::in);
    //�ж��Ƿ�ɹ���
    if(!ifs.is_open())
    {
        cout << "�ļ���ʧ��!\n";
        return;
    }else
    {
        //��ӡ����
        //���ַ���
        //��һ��
        /*
        cout << "��һ�ַ�ʽ��ȡ����\n";
        char buf1[1024] = {0};
        while(ifs >> buf1)
        {
            cout << buf1 << endl;
        }
        */
        /*
        //�ڶ���
        cout << "\n�ڶ��ַ�ʽ��ȡ����\n";

        char buf2[1024] = {0};
        while(ifs.getline(buf2,sizeof(buf2)))
        {
            cout << buf2 << endl;
        }
        */

         //������
        cout << "\n�����ַ�ʽ��ȡ����\n";
        string buf3;
        while(getline(ifs, buf3))
        {
            cout << buf3 << endl;
        }
        /*
        //������
        cout << "\n�����ַ�ʽ��ȡ���ݣ����䲻�Ƽ�\n";
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
