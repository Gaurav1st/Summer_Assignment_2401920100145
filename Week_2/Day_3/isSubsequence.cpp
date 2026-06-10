#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;

        for (int i = 0; i < t.length(); i++) {
            if (j < s.length() && t[i] == s[j]) {
                j++;
            }
        }

        return s.length() == j;
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter s: ";
    cin >> s;

    cout << "Enter t: ";
    cin >> t;

    if (obj.isSubsequence(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}