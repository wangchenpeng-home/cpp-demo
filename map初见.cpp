#include<iostream>
using namespace std;
#include<map>

/*
简介:
·map中的所有元素都是pair
·pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
·所有元素都会根据元素的键值自动排序
本质:
·map/multimap属于关联式容器，底层结构是用二叉树实现。
优点:
·可以根据key值快速找到value值map和multimap
区别:
·map不允许容器中有重复key值元素. multimap允许容器中有重复key值元素
map的大小和交换：
    size();返回容器中元素的数目
    empty();判断容器是否为空
    swap(st);交换两个集合容器
查找删除
    find(key);查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    count(key);统计key的元素个数
*/
//利用仿函数，可以改变排序规则
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

    m.insert(pair<int, string>(3, "小猪"));
    m.insert(pair<int, string>(1, "小猫"));
    m.insert(pair<int, string>(2, "小狗"));

    printMap(m);

    //第一种插入方式
	m.insert(pair<int, string>(6, "小鸟"));
	//第二种插入方式
	m.insert(make_pair(5, "小鼠"));
	//第三种插入方式
	m.insert(map<int, string>::value_type(4, "小牛"));
	//第四种插入方式
	m[7] = "小龙";

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//查找
	map<int, string>::iterator pos = m.find(4);
	if(pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first
		<< " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = m.count(3);
	cout << "number of 3 = " << num << endl;

	//清空
	m.erase(m.begin(),m.end());
	m.clear();
	printMap(m);


	//逆序
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
