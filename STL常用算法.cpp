#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
/*
*���ñ����㷨
for_each     //��������
for_each(iterator beg, iterator end, _func);
//_func �������ߺ�������

transform  //������������һ��������
transform(iterator beg1, iterator end1, iterator beg2, _func);

*���ò����㷨
find                   //����Ԫ��
find(iterator beg, iterator end, value);

find_if             //����������Ԫ��
find_if(iterator beg, iterator end, _Pred);
// _Pred ��������ν�ʣ�����bool���͵ķº�����

adjacent_find   //���������ظ�Ԫ��
adjacent_find(iterator beg, iterator end);

binary_search    //���ֲ��ҷ�
bool binary_search(iterator beg, iterator end, value);

count                   //ͳ��Ԫ�ظ���
count(iterator beg, iterator end, value);

count_if           //������ͳ��Ԫ�ظ���
count_if(iterator beg, iterator end, _Pred);

*���������㷨
sort           //��������Ԫ�ؽ�������
sort(iterator beg, iterator end, _Pred);

random_shuffle //ϴ��   ָ����Χ�ڵ�Ԫ�������������
random_shuffle(iterator beg, iterator end);

merge          // ����Ԫ�غϲ������洢����һ������
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

reverse        // ��תָ����Χ��Ԫ��
reverse(iterator beg, iterator end);

*���ÿ������滻�㷨
copy                    // ������ָ����Χ��Ԫ�ؿ�������һ������
copy(iterator beg, iterator end, iterator dest);

replace               // ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
replace(iterator beg, iterator end, oldvalue, newvalue);

replace_if          // ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
replace_if(iterator beg, iterator end, _pred, newvalue);

swap                    // ��������������Ԫ��
swap(container c1, container c2);

*�������������㷨
accumulate     // ��������Ԫ���ۼ��ܺ�
accumulate(iterator beg, iterator end, value);
//accumulateʹ��ʱͷ�ļ�ע���� numeric������㷨��ʵ��

fill                 // �����������ָ����Ԫ��
fill(iterator beg, iterator end, value);

*���ü����㷨
set_intersection          // �����������Ľ���
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//dest  ������

set_union                      // �����������Ĳ���
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

set_difference              // �����������Ĳ
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
	//ȡ��������ϴ��ֵ��Ŀ���������ٿռ�
	vTarget.resize( max(v1.size() , v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	cout << "v1��v2�ĲΪ�� " << endl;
	vector<int>::iterator itEnd =
        set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2��v1�ĲΪ�� " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main(void)
{
    test();

    return 0;
}
