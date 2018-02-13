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
    MyStack(int size);                        //分配内存初始化栈空间，设定栈容量，栈顶
    ~MyStack();                               //回收栈空间内存
    bool stackEmpty();                        //判定栈是否为空，为空返回true，非空返回false
    bool stackFull();                         //判定栈是否已满，为满返回true，未满返回false
    void clearStack();                        //清空栈
    int stackLength();                        //已有元素个数
    bool push(T elem);                        //元素入栈，栈顶上升
    bool pop(T &elem);                        //元素出栈，栈顶下降
    void stackTraverse(bool isFromButton);    //遍历栈中所有元素
private:
    T *m_pBuffer;                             //栈空间指针
    int m_iSize;                              //栈容量
    int m_iTop;                               //栈顶，栈中元素个数
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
