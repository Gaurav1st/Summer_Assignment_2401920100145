#include <iostream>
#include <string>
using namespace std;

bool valid(int ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    return 0;
}

void tolowercase(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            continue;
        else
        {
            s[i] = (s[i] - 'A' + 'a');
        }
    }
}

bool checkpalin(string &s)
{
    int st = 0;
    int e = s.size() - 1;
    while (st <= e)
    {
        if (s[st] != s[e])
            return 0;
        st++;
        e--;
    }
    return 1;
}

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        int st = 0;
        while (st < s.size())
        {
            if (valid(s[st]))
                str.push_back(s[st]);
            st++;
        }
        tolowercase(str);
        return checkpalin(str);
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);
    if (sol.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
    return 0;
}
