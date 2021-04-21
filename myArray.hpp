//�Լ���ͨ��������ģ��
#pragma
#include<iostream>
using namespace std;


template <class T>
class myArray
{
public:
    //�вι���
    myArray(int capacity)
    {
        arryCapacity = capacity;
        arrySize = 0;
        pAddress = new T[arryCapacity];
    }

    //��������
    myArray(const myArray& arr)
    {
        arryCapacity = arr.arryCapacity;
        arrySize = arr.arrySize;
        //pAddress = arr.pAddress; ������ôд������ᵼ���ظ��ͷ�

        pAddress = new T[arryCapacity];

        for(int i = 0; i < arrySize; i++)
        {
            pAddress[i] = arr.pAddress[i];
        }
    }

    //operator=��ֹǳ����
    myArray& operator= (const myArray & arr)
    {
        //���ж��Ƿ����������
        if(pAddress != NULL)
        {
            delete[] pAddress;
            pAddress = NULL;
            arryCapacity = 0;
            arrySize = 0;
        }

        //���
        arryCapacity = arr.arrCapacity;
        arrySize = arr.arrSize;
        pAddress = new T[arryCapacity];

        for(int i = 0; i < arrySize; i++)
        {
            pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //β�巨
    void Push_Back(const T & val)
    {
        if(arrySize == arryCapacity)
        {
            cout << "��������" << endl;
            return;
        }

        pAddress[arrySize] = val;
        arrySize++;
    }

    //βɾ��
    void Pop_Back()
    {
        if(arrySize == 0)
        {
            return;
        }
        arrySize--;
    }

    //ͨ���±����Ԫ�أ���Ҫ���[]  arr[0] = 100;������Ҫ����
    T& operator[] (int index)
    {
        return pAddress[index];
    }

    //���������ʹ�С
    int getCapacity()
    {
        return arryCapacity;
    }
    int getSize()
    {
        return arrySize;
    }


    //��������
    ~myArray()
    {
        if(pAddress != NULL)
        {
            delete[] pAddress;
            pAddress = NULL;
        }
    }

private:
    T * pAddress; // ָ��ָ��������ٵ���ʵ������

    int arryCapacity;//����

    int arrySize;//��С
};
