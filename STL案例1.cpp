//����ѡ��ABCDE��ʮ����ί��֣�ȥ����߷ֺ���ͷ�ȡƽ����
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>

class Person
{
public:
    Person(string name, int score)
    {
        m_name = name;
        m_score = score;
    }

    string m_name;
    int m_score;
};

void createPerson(vector<Person> &v)
{
    int score = 0;
    const string contestant = "ABCDE";
    for(int i = 0; i < 5; i++)
    {
        string name = "ѡ��";
        name += contestant[i];
        Person p(name, score);

        v.push_back(p);
    }
}

void score(deque<int> &d, vector<Person> &v)
{
    int to_score = 0;
    for(int i = 0; i < 5; i++)
    {
        int average = 0;
        cout << "���"<< v[i].m_name <<"��֣�" << endl;
        for(int j = 0; j < 10; j++)
        {
            cin >> to_score;
            d.push_back(to_score);
        }
        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();
        for(deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
            average += *it;
        }
        average = average / 8;
        v[i].m_score = average;
        d.clear();
    }


}

void printScore(vector<Person> &v)
{
    for(int i = 0; i < 5; i++)
    {
        cout << v[i].m_name << "�����յ÷��ǣ�" << v[i].m_score << endl;
    }
}

int main(void)
{

    vector<Person> v;
    createPerson(v);
    deque<int> de;

    score(de, v);
    printScore(v);

    return 0;
}
