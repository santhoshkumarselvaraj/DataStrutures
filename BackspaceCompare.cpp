class Solution {
public:
    bool backspaceCompare(string s, string t) {
     stack<int> s1, s2;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '#')
            s1.push(i);
        else if (!s1.empty())
            s1.pop();
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] != '#')
            s2.push(i);
        else if (!s2.empty())
            s2.pop();
    }

    if (s1.size() != s2.size())
    return false;

    while (!s1.empty() || !s2.empty())
    {
        if (s[s1.top()] != t[s2.top()])
            return false;

        s1.pop();
        s2.pop();
    }

    return true;	
        }
};
