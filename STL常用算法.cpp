#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
/*
*常用遍历算法
for_each     //遍历容器
for_each(iterator beg, iterator end, _func);
//_func 函数或者函数对象

transform  //搬运容器到另一个容器中
transform(iterator beg1, iterator end1, iterator beg2, _func);

*常用查找算法
find                   //查找元素
find(iterator beg, iterator end, value);

find_if             //按条件查找元素
find_if(iterator beg, iterator end, _Pred);
// _Pred 函数或者谓词（返回bool类型的仿函数）

adjacent_find   //查找相邻重复元素
adjacent_find(iterator beg, iterator end);

binary_search    //二分查找法
bool binary_search(iterator beg, iterator end, value);

count                   //统计元素个数
count(iterator beg, iterator end, value);

count_if           //按条件统计元素个数
count_if(iterator beg, iterator end, _Pred);

*常用排序算法
sort           //对容器内元素进行排序
sort(iterator beg, iterator end, _Pred);

random_shuffle //洗牌   指定范围内的元素随机调整次序
random_shuffle(iterator beg, iterator end);

merge          // 容器元素合并，并存储到另一容器中
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

reverse        // 反转指定范围的元素
reverse(iterator beg, iterator end);

*常用拷贝和替换算法
copy                    // 容器内指定范围的元素拷贝到另一容器中
copy(iterator beg, iterator end, iterator dest);

replace               // 将容器内指定范围的旧元素修改为新元素
replace(iterator beg, iterator end, oldvalue, newvalue);

replace_if          // 容器内指定范围满足条件的元素替换为新元素
replace_if(iterator beg, iterator end, _pred, newvalue);

swap                    // 互换两个容器的元素
swap(container c1, container c2);

*常用算术生成算法
accumulate     // 计算容器元素累计总和
accumulate(iterator beg, iterator end, value);
//accumulate使用时头文件注意是 numeric，这个算法很实用

fill                 // 向容器中填充指定的元素
fill(iterator beg, iterator end, value);

*常用集合算法
set_intersection          // 求两个容器的交集
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//dest  新容器

set_union                      // 求两个容器的并集
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

set_difference              // 求两个容器的差集
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
*/

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test()
{
    vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}

	vector<int> vTarget;
	//取两个里面较大的值给目标容器开辟空间
	vTarget.resize( max(v1.size() , v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	cout << "v1与v2的差集为： " << endl;
	vector<int>::iterator itEnd =
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2与v1的差集为： " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main(void)
{
    test();

    return 0;
}
