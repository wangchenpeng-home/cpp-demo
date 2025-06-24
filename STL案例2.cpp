#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<vector>
#include<ctime>

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
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
        string name = "员工";
        name += str[i];
        Worker worker(name, rand() % 10000 + 10000);
        w.push_back(worker);
    }
}

void setGroup(vector<Worker>&vWorker, multimap<int, Worker>&mWorker)
{
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3; // 0 1 2

		//将员工插入到分组中
		//key部门编号，value具体员工
		mWorker.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGourp(multimap<int,Worker>&m)
{
	cout << "策划部门：" << endl;

	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA); // 统计具体人数
	int index = 0;
	for (; pos != m.end() && index < count; pos++ , index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "美术部门： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "研发部门： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
	}

}

int main(void)
{
    //随机种子，每次运行都不一样
    srand((unsigned int)time(NULL));

    //1、创建员工
    vector<Worker>vWorker;
	createWorker(vWorker);

    //2、员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);

    //3、分组显示员工
    showWorkerByGourp(mWorker);

    return 0;
}
