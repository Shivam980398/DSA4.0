#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}
string invertBracket(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    return s;
}
string infixToPrefix(string &s)
{

    reverse(s.begin(), s.end());
    s = invertBracket(s);
    int i = 0;
    int N = s.size();
    stack<char> st;
    string ans = "";
    while (i < N)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            ans = ans + s[i];

        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }

        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }

            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "(A+B)*C-D+F";
    cout << infixToPrefix(s);
    // return 0;
}