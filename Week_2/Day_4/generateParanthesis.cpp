#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(')
                count++;
            else
                count--;

            if (count < 0)
                return false;
        }

        return count == 0;
    }

    void create(string str, int n, vector<string>& res) {
        if (str.length() == 2 * n) {
            if (isValid(str))
                res.push_back(str);
            return;
        }

        create(str + '(', n, res);
        create(str + ')', n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        create("", n, res);
        return res;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> ans = obj.generateParenthesis(n);

    cout << "Valid Parentheses:\n";
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}