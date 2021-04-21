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
    //����������
    ofstream ofs;

    //���ļ�
    ofs.open("�����ƶ�д.txt", ios::binary | ios::out);
    //�϶�Ϊһ,ֱ�Ӵ����Ӵ�
    //ofstream ofs("�����ƶ�д.txt", ios::binary | ios::out);

    //��д�ļ�
    //д�ļ�
    Person p = {"����", 18};
    ofs.write((const char *)&p , sizeof(Person));//ǿ��ת����const char *

    //�ر��ļ�
    ofs.close();
}
void test02()
{
    ifstream ifs("�����ƶ�д.txt", ios::in | ios::binary);

    if(!ifs.is_open())
    {
        cout << "�ļ���ʧ�ܣ�\n";
        ifs.close();
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "������ " << p.m_Name << endl;
    cout << "���䣺 " << p.m_Age << endl;

    ifs.close();
}

int main(void)
{
    test01();
    test02();

    return 0;
}
