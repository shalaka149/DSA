#include <iostream>
#include <string>
using namespace std;
class stack
{
private:
    int top;
    char *arr;
    int n;

public:
    stack(int size)
    {
        n = size;
        top = -1;
        arr = new char[n];
    }
    ~stack()
    {
        delete[] arr;
    }
    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    bool IsFull()
    {
        if (top == n - 1)
        {
            return true;
        }
        else
            return false;
    }
    void push(char val)
    {
        if (IsFull())
        {
            cout << "Stack Overflow";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    char pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow";
            return 0;
        }
        else
        {
            int popval = arr[top];
            arr[top] = 0;
            top--;
            return popval;
        }
    }
    char top1()
    {
        if (IsEmpty())
        {
            cout << "The stack is empty.";
        }
        else
        {
            return arr[top];
        }
    }
    void display()
    {
        if (IsEmpty())
        {
            cout << "The stack is empty.";
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};
string reverse(string s)
{
    string t=s;
    int n= s.length();
    stack s1(n);
    for(int i=0;i<n;i++)
    {
        s1.push(s[i]);
    }
    string reversed="";
    while (!s1.IsEmpty())
    {
        reversed+=s1.pop();
    }
    if(t==reversed)
    {
        cout<<"The string is a palindrome."<<endl;
    }
    else
    {
        cout<<"The string is not a palindrome."<<endl;
    }
    return reversed;
}
int main()
{
    string s;
    cout<<"Enter any string: ";
    cin>>s;
    string reversed= reverse(s);
    cout<<"\nThe reversed string is: "<<reversed;
    return 0;
}