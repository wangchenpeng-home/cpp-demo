//自己的通用数组类模板
#pragma
#include<iostream>
using namespace std;


template <class T>
class myArray
{
public:
    //有参构造
    myArray(int capacity)
    {
        arryCapacity = capacity;
        arrySize = 0;
        pAddress = new T[arryCapacity];
    }

    //拷贝构造
    myArray(const myArray& arr)
    {
        arryCapacity = arr.arryCapacity;
        arrySize = arr.arrySize;
        //pAddress = arr.pAddress; 不能这么写，否则会导致重复释放

        pAddress = new T[arryCapacity];

        for(int i = 0; i < arrySize; i++)
        {
            pAddress[i] = arr.pAddress[i];
        }
    }

    //operator=防止浅拷贝
    myArray& operator= (const myArray & arr)
    {
        //先判断是否堆中有数据
        if(pAddress != NULL)
        {
            delete[] pAddress;
            pAddress = NULL;
            arryCapacity = 0;
            arrySize = 0;
        }

        //深拷贝
        arryCapacity = arr.arrCapacity;
        arrySize = arr.arrSize;
        pAddress = new T[arryCapacity];

        for(int i = 0; i < arrySize; i++)
        {
            pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法
    void Push_Back(const T & val)
    {
        if(arrySize == arryCapacity)
        {
            cout << "容量不足" << endl;
            return;
        }

        pAddress[arrySize] = val;
        arrySize++;
    }

    //尾删法
    void Pop_Back()
    {
        if(arrySize == 0)
        {
            return;
        }
        arrySize--;
    }

    //通过下标访问元素，需要冲裁[]  arr[0] = 100;所以需要引用
    T& operator[] (int index)
    {
        return pAddress[index];
    }

    //返回容量和大小
    int getCapacity()
    {
        return arryCapacity;
    }
    int getSize()
    {
        return arrySize;
    }


    //析构函数
    ~myArray()
    {
        if(pAddress != NULL)
        {
            delete[] pAddress;
            pAddress = NULL;
        }
    }

private:
    T * pAddress; // 指针指向堆区开辟的真实的数组

    int arryCapacity;//容量

    int arrySize;//大小
};
