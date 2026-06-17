#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: "
         << obj.longestPalindrome(s) << endl;

    return 0;
}