#include<iostream>
using namespace std;
#include<set>//���ն��������в���

/*
set��С�ͽ���
size();
empty();
swap(set<auto> S);
set����ɾ��
insert();
clear();
erase(pos);��λ��ɾ��
erase(begin, end);��������ɾ��
erase(elem);//��ֵɾ��
set���Һ�ͳ��
find(val);//�ɹ�ʱ����pos������,ʧ��ʱ����end();
count(val);//ֻ��0��1
set��multiset������
1.set�����Բ����ظ�����multiset����
2.set��������ʱ�᷵�ز���������ʾ�ɹ���
    ���ص���pair<set<elemtype>::iterator pos, bool>����
3.mnultiset���������ݣ����Կ����ظ�����

pair����Ĵ���
1.pair<type, type> p (value1, value2);
2.pair<type, type> p = make_pair(value1, value2);

����ʱ��p.first��p.second��ȡ

set���������򣬸ı�˳��Ϊ�ɴ�С
1.����������������--ͨ���º���-����();
class Compare
{
public:
    bool operator()(const int v1,const int v2)
    {
        return v1 > v2;
    }
}
����ʱӦ��set<int, Compare> S��
*/


void printSet(set<int> &S)
{
    for(set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    set<int> S;

    //set��������ֻ��insert
    S.insert(2);
    S.insert(5);
    S.insert(1);
    S.insert(3);
    S.insert(4);

    printSet(S);

    cout << "�ٴβ���һ��4��\n";
    S.insert(4);
    printSet(S);
    //set����ʱ�Զ����򣬶���û���ظ�Ԫ��
    cout << "S2's  value:\n";
    set<int> S2(S);
    printSet(S2);
    cout << "S3's  value:\n";
    set<int> S3;
    S3 = S2;
    printSet(S3);
}
int main(void)
{
    test();

    return 0;
}
