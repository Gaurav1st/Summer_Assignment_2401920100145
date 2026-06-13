#include <iostream>
#include <string>
using namespace std;

string decode(string &s, int &i)
{
    int num = 0;
    string result = "";

    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        else if (s[i] == '[')
        {
            i++;
            string temp = decode(s, i);

            while (num--)
            {
                result += temp;
            }
            num = 0;
        }
        else if (s[i] == ']')
        {
            i++;
            return result;
        }
        else
        {
            result += s[i];
            i++;
        }
    }

    return result;
}

class Solution
{
public:
    string decodeString(string s)
    {
        int i = 0;
        return decode(s, i);
    }
};

int main()
{
    Solution obj;

    string s = "3[a2[c]]";

    cout << "Decoded String: "
         << obj.decodeString(s) << endl;

    return 0;
}