#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<vector>
#include<ctime>

/*
- ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
- Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
- �����10��Ա�����䲿�ź͹���
- ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
- �ֲ�����ʾԱ����Ϣ
*/

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Worker
{
public:
    Worker(string name, int n)
    {
        m_name = name;
        m_salary = n;
    }

    string m_name;
    int m_salary;
};

void createWorker(vector<Worker> &w)
{
    string str = "ABCDEFGHIJ";
    for(int i = 0; i < 10; i++)
    {
        string name = "Ա��";
        name += str[i];
        Worker worker(name, rand() % 10000 + 10000);
        w.push_back(worker);
    }
}

void setGroup(vector<Worker>&vWorker, multimap<int, Worker>&mWorker)
{
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		//����������ű��
		int deptId = rand() % 3; // 0 1 2

		//��Ա�����뵽������
		//key���ű�ţ�value����Ա��
		mWorker.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGourp(multimap<int,Worker>&m)
{
	cout << "�߻����ţ�" << endl;

	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // ͳ�ƾ�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++ , index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_name << " ���ʣ� " << pos->second.m_salary << endl;
	}

}

int main(void)
{
    //������ӣ�ÿ�����ж���һ��
    srand((unsigned int)time(NULL));

    //1������Ա��
    vector<Worker>vWorker;
	createWorker(vWorker);

    //2��Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

    //3��������ʾԱ��
    showWorkerByGourp(mWorker);

    return 0;
}
