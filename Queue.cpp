// As the name suggests Preprocessors are programs that process our source code before compilation.
//  There are a number of steps involved between writing a program and executing a program in C / C++.
//  Let us have a look at these steps before we actually start learning about Preprocessors.

#include <iostream>
#define N 5
#include <cstdio>
using namespace std;
class Queue
{

private:
    int front, rear;
    int arr[5];

public:
    Queue()
    {

        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {

        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {

        if (rear == N - 1)
            return true;
        else
            return false;
    }

    void push(int item)
    {

        if (isFull())
        {
            /* code */
            cout << "\t Queue is Full\n";
        }
        else if (front == -1 && rear == -1)
        {

            front = rear = 0;
            arr[rear] = item;
            cout << "insertion suceed\n";
        }
        else
        {
            rear++;
            arr[rear] = item;
        }
    }
    //----------------------------------------------------------------insertio  suceeed

    int pop()
    {

        int item;
        if (isEmpty())
        {

            return -1;
        }
        if (front == rear)
        {

            item = arr[front];
            cout << arr[front];
            front = rear = -1;
            return item;
        }
        else
        {
            item = arr[front];
            front++;
            return item;
        }
    }
    //----------------------------------------------------------------extraction  suceeed

    int capacity()
    {

        return ( rear - front)  + 1;
    }
};

int main()
{

    Queue q1;

    while (1)
    {

        int argc, item;
        cout << "0) Exit the Loop\n";
        cout << "1) insert a no\n";
        cout << "2) pop a no\n";
        cout << "3) capacity\n";
        cout << "5) clear screen\n";

        cout << "Enter ur Choise\n";
        cin >> argc;

        switch (argc)
        {

        case 1:
            cout << "enter a no at last";
            cin >> item;
            q1.push(item);

            break;
        case 2:

            item = q1.pop();
            if (item == -1)
            {
                cout << "Queue is Empty!" << endl;
            }
            else
                cout << "dequed value: " << item << endl;

            break;
        case 3:

            cout << "your capacity :" << q1.capacity() << endl;

            break;
        case 0:

            exit(0);
            break;
        case 5:
            system("cls");
            break;
        }
    }

    return 0;
}