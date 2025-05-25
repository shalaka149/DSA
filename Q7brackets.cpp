#include <iostream>
#include <stack>
using namespace std;

// Function to check if the brackets are balanced
bool isBalanced(string str)
{
    stack<char> s;
    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.empty(); // Stack should be empty if all brackets matched
}

int main()
{
    string input;
    cout << "Enter a string with brackets like ({}[]()): ";
    cin >> input;

    if (isBalanced(input))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }

    return 0;
}
