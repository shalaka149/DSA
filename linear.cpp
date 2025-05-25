#include <iostream>
#include <string>
using namespace std;
class Q
{
private:
    int front;
    int *arr;
    int rear;
    int n;
public:
    Q(int size)
    {
        n = size;
        front= -1;
        rear=-1;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
    }
    bool IsEmpty()
    {
        if (front == -1 && rear==-1)
        {
            return true;
        }
        else
            return false;
    }
    bool IsFull()
    {
        if (rear== n - 1)
        {
            return true;
        }
        else
            return false;
    }
    void enqueue(int val)
    {
        if (IsFull())
        {
            cout << "Queue Overflow";
            return;
        }
        else if(IsEmpty())
        {
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else
        {
            rear++;
        }
            arr[rear] = val;
    }
    int dequeue()
    {
        int x;
        if (IsEmpty())
        {
            cout << "Queue underflow";
            return 0;
        }
        else if(front ==rear)
        {
            x=arr[front];
            arr[front]=0;
            rear=-1;
            front=-1;
            return x;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front++;
            return x;
        }
    }
    void display()
    {
        cout<<"All values in the queue are: ";
        for (int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n, choice,value;
    cout << "Number of elements in queue: ";
    cin >> n;
    Q q1(n);
    do
    {
        cout << "\nChoose number for which operation to perform: \n";
        cout << "1.Enqueue 2.dequeue 3.isempty 4.isfull 5.display 6.exit"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // Push operation
            cout << "Enter value to enqueue: ";
            cin >> value;
            q1.enqueue(value);
            break;

        case 2: // Pop operation
            value = q1.dequeue();
            if (value != -1)
            { // If not underflow
                cout << value << " dequeued from queue" << endl;
            }
            break;

        case 3: // Is Empty check
            if (q1.IsEmpty())
            {
                cout << "The queue is empty." << endl;
            }
            else
            {
                cout << "The queue is not empty." << endl;
            }
            break;

        case 4: // Is Full check
            if (q1.IsFull())
            {
                cout << "The queue is full." << endl;
            }
            else
            {
                cout << "The queue is not full." << endl;
            }
            break;

        case 5: // Display operation
            q1.display();
            break;

        case 6: // Exit
            cout << "Exiting..." << endl;
            break;

        default: // Invalid input handling
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}