#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int i = n / 2; i >= 1; i--) {

            if (n % i == 0) {

                string sub = s.substr(0, i);
                string temp = "";

                for (int j = 0; j < n / i; j++) {
                    temp += sub;
                }

                if (temp == s) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter string: ";
    cin >> s;

    if (obj.repeatedSubstringPattern(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}