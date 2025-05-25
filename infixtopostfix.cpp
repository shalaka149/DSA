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
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
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
bool IsOperator(char c)
{
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='/'||c=='*')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
    return -1;
}
string infixtopostfix(stack s, string infix)
{
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
        if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((s.top1()!='(') && (!s.IsEmpty()))
            {
                char temp=s.top1();
                postfix+=temp;
                s.pop();
            }
            s.pop();
        }
        else if(IsOperator(infix[i]))
        {
            if(s.IsEmpty())
            {
                s.push(infix[i]);
            }
            else
            {
                if(precedence(infix[i])>precedence(s.top1()))
                {
                    s.push(infix[i]);
                }
                else if((precedence(infix[i])==precedence(s.top1())) && (infix[i]=='^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while((!s.IsEmpty())&&(precedence(infix[i])<=precedence(s.top1())))
                    {
                        char temp=s.top1();
                        postfix+=temp;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.IsEmpty())
    {
        postfix+=s.top1();
        s.pop();
    }
    return postfix;
}
int main()
{
    string infix,postfix;
    cout<<"Enter an infix expression:";
    cin>>infix;
    stack s(infix.length());
    cout<<"Infix expression: "<<infix<<endl;
    postfix=infixtopostfix(s,infix);
    cout<<endl<<"Postfix expression:"<<postfix;
    return 0;
}