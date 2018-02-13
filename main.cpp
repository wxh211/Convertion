#include <iostream>
#include <stdlib.h>
#include <ostream>
using namespace std;

#define BINARY        2
#define OCTONARY      8
#define HEXADECIMAL  16


class Coordinate
{
    friend ostream &operator<<(ostream &out,Coordinate &coor);
public:
    Coordinate(int x=0, int y=0);
    void printCoordinate();

private:
    int m_iX;
    int m_iY;
};

Coordinate::Coordinate(int x, int y)
{
    m_iX = x;
    m_iY = y;
}

void Coordinate::printCoordinate()
{
    cout<<"("<<m_iX<<","<<m_iY<<")"<<endl;
}

ostream &operator<<(ostream&out,Coordinate&coor)
{
    out<<"("<<coor.m_iX<<","<<coor.m_iY<<")"<<endl;
    return out;
}
template<typename T>
class MyStack
{
public:
    MyStack(int size);                        //�����ڴ��ʼ��ջ�ռ䣬�趨ջ������ջ��
    ~MyStack();                               //����ջ�ռ��ڴ�
    bool stackEmpty();                        //�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
    bool stackFull();                         //�ж�ջ�Ƿ�������Ϊ������true��δ������false
    void clearStack();                        //���ջ
    int stackLength();                        //����Ԫ�ظ���
    bool push(T elem);                        //Ԫ����ջ��ջ������
    bool pop(T &elem);                        //Ԫ�س�ջ��ջ���½�
    void stackTraverse(bool isFromButton);    //����ջ������Ԫ��
private:
    T *m_pBuffer;                             //ջ�ռ�ָ��
    int m_iSize;                              //ջ����
    int m_iTop;                               //ջ����ջ��Ԫ�ظ���
};

template <typename T>
MyStack<T>::MyStack(int size)
{
    m_iSize = size;
    m_pBuffer = new T[size];
    m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete []m_pBuffer;
}
template<typename T>
bool MyStack<T>::stackEmpty()
{
    if(0 == m_iTop)
    {
        return true;
    }
    return false;
}

template <typename T>
bool MyStack<T>::stackFull()
{
    if(m_iTop == m_iSize)
    {
        return true;
    }
    return false;
}

template <typename T>
void MyStack<T>::clearStack()
{
    m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength()
{
    return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
    if(stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop] = elem;
    m_iTop++;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem)
{
    if(stackEmpty())
    {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];
    return true;
}
/*
char MyStack::pop()
{
    if(stackEmpty())
    {
        throw 1;
    }
    else
    {
        m_iTop--;
        return m_pBuffer[m_iTop];
    }
}
*/

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButton)
{
    if(isFromButton)
    {
        for(int i = 0; i<m_iTop; i++)
        {
            cout<<m_pBuffer[i];
            //m_pBuffer[i].printCoordinate();
        }
    }
    else
    {
        for(int i=m_iTop-1; i>=0; i--)
        {
            cout<<m_pBuffer[i];
            //m_pBuffer[i].printCoordinate();
        }
    }
}

int main(void)
{
    char num [] = "0123456789ABCDEF";

    MyStack<int> *pStack = new MyStack<int>(40);

    int N = 2018;
    int mod = 0;
    while(N != 0)

    {
        mod = N % HEXADECIMAL;
        pStack->push(mod);
        N = N / HEXADECIMAL;
    }

    /*for(int i = pStack->stackLengtn()-1;i>=0;i--)
    {
        num[pStack]
    }*/

    //pStack->stackTraverse(false);

    int elem = 0;
    while(!pStack->stackEmpty())
    {
        pStack->pop(elem);
        cout<<num[elem];
    }

    delete pStack;
    pStack = NULL;

    system("pause");
    return 0;
}
