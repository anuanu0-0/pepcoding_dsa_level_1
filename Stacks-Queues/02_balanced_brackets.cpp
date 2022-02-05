#include <bits/stdc++.h>
using namespace std;

bool matches(char open, char close)
{
    if ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}'))
        return true;

    return false;
}

bool hasBalancedBrackets(string str)
{

    stack<char> s;
    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;
            else if (matches(s.top(), ch))
                s.pop();
        }
    }

    return s.empty();
}

int main(int argc, char **argv) {
    string str;
    getline(cin, str);

    cout << boolalpha << hasBalancedBrackets(str) << endl;
    return 0;
}