#include <iostream>
#include <string>
#include <cmath>
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
        return top == -1;
    }
    bool IsFull()
    {
        return top == n - 1;
    }
    void push(char val)
    {
        if (IsFull())
        {
            cout << "Stack Overflow\n";
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
            cout << "Stack Underflow\n";
            return 0;
        }
        else
        {
            char popval = arr[top];
            arr[top] = 0;
            top--;
            return popval;
        }
    }
    char top1()
    {
        if (IsEmpty())
        {
            cout << "The stack is empty.\n";
            return 0;
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
            cout << "The stack is empty.\n";
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
    }
};

bool IsOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '^');
}

int precedence(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixtopostfix(stack &s, string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];  // Operand goes directly to postfix
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);  // Push '(' to stack
        }
        else if (infix[i] == ')')
        {
            while ((s.top1() != '(') && (!s.IsEmpty()))  // Pop until '('
            {
                char temp = s.top1();
                postfix += temp;
                s.pop();
            }
            s.pop();  // Pop '('
        }
        else if (IsOperator(infix[i]))  // Operator case
        {
            while ((!s.IsEmpty()) && (precedence(infix[i]) <= precedence(s.top1())))
            {
                char temp = s.top1();
                postfix += temp;
                s.pop();
            }
            s.push(infix[i]);  // Push the operator to stack
        }
    }
    while (!s.IsEmpty())  // Pop all remaining operators
    {
        postfix += s.top1();
        s.pop();
    }
    return postfix;
}

int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0;
    }
}

int evaluatePostfix(string postfix, int operandValues[])
{
    stack s(postfix.length());
    for (char &c : postfix)
    {
        if (isalpha(c))
        {
            s.push(operandValues[c - 'a']);  // Get operand value from array
        }
        else
        {
            int b = s.pop();
            int a = s.pop();
            s.push(applyOperator(a, b, c));  // Apply the operator
        }
    }
    return s.top1();  // Final result
}

int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    stack s(infix.length());
    cout << "Infix expression: " << infix << endl;

    // Array to store operand values for 'a' to 'z'
    int operandValues[26] = {0};

    // Ask for operand values (only once for each unique operand)
    for (char &c : infix)
    {
        if (isalpha(c))  // Check if it's an operand (a-z, A-Z)
        {
            int index = tolower(c) - 'a';  // Get the index (0 for 'a', 1 for 'b', ..., 25 for 'z')
            if (operandValues[index] == 0) // Only ask for value if not already provided
            {
                int value;
                cout << "Enter value for operand '" << c << "': ";
                cin >> value;
                operandValues[index] = value;  // Store the value
            }
        }
    }

    postfix = infixtopostfix(s, infix);  // Convert infix to postfix
    cout << "Postfix expression: " << postfix << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix, operandValues);
    cout << "Result of postfix evaluation: " << result << endl;

    return 0;
}

