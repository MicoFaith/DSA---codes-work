#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int capacity;
    int nextIndex;

public:
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[nextIndex] = val;
            nextIndex++;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << "The removed element is " << peek() << endl;
            nextIndex--;
        }
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    bool isFull()
    {
        return nextIndex == capacity;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[nextIndex - 1];
        }
    }

    void display()
    {
        while (!isEmpty())
        {
            cout << peek() << " " << endl;
            pop();
        }
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack *myStack = new Stack(5);
    cout << "Adding elements in the stack" << endl;
    myStack->push(10);
    myStack->push(20);
    myStack->push(30);
    myStack->push(40);
    myStack->push(50);
    myStack->push(60);
    myStack->push(70);
    cout << "The element at the top is " << myStack->peek() << endl;
    myStack->pop();
    myStack->pop();
    myStack->display();
    return 0;
}











