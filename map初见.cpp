#include<iostream>
using namespace std;
#include<map>

/*
���:
��map�е�����Ԫ�ض���pair
��pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
������Ԫ�ض������Ԫ�صļ�ֵ�Զ�����
����:
��map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�֡�
�ŵ�:
�����Ը���keyֵ�����ҵ�valueֵmap��multimap
����:
��map���������������ظ�keyֵԪ��. multimap�������������ظ�keyֵԪ��
map�Ĵ�С�ͽ�����
    size();����������Ԫ�ص���Ŀ
    empty();�ж������Ƿ�Ϊ��
    swap(st);����������������
����ɾ��
    find(key);����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
    count(key);ͳ��key��Ԫ�ظ���
*/
//���÷º��������Ըı��������
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void printMap(map<int,string>&m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " name = " << it->second << endl;
	}
	cout << endl;
}

void test()
{
    map<int, string> m;

    m.insert(pair<int, string>(3, "С��"));
    m.insert(pair<int, string>(1, "Сè"));
    m.insert(pair<int, string>(2, "С��"));

    printMap(m);

    //��һ�ֲ��뷽ʽ
	m.insert(pair<int, string>(6, "С��"));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(5, "С��"));
	//�����ֲ��뷽ʽ
	m.insert(map<int, string>::value_type(4, "Сţ"));
	//�����ֲ��뷽ʽ
	m[7] = "С��";

	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//����
	map<int, string>::iterator pos = m.find(4);
	if(pos != m.end())
	{
		cout << "�ҵ���Ԫ�� key = " << (*pos).first
		<< " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = m.count(3);
	cout << "number of 3 = " << num << endl;

	//���
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);


	//����
	map<int, int, MyCompare> m1;

	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));
	m1.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

int main(void)
{
    test();

    return 0;
}
