#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string &s)
{
    int i = 0;
    int N = s.size();
    stack<string> st;
    while (i < N)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            st.push(s[i]);
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string converted_str = '(' + t2 + s[i] + t1 + ')';
            st.push(converted_str);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s = "AB-DE+*/";
    cout << postfixToInfix(s);
    // return 0;
}