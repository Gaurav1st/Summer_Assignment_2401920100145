#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> s1count(26, 0), s2window(26, 0);

        for (char c : s1) {
            s1count[c - 'a']++;
        }

        int k = s1.size();

        // first window
        for (int i = 0; i < k; i++) {
            s2window[s2[i] - 'a']++;
        }

        if (s1count == s2window)
            return true;

        // sliding window
        for (int i = k; i < s2.size(); i++) {
            s2window[s2[i] - 'a']++;           // add new char
            s2window[s2[i - k] - 'a']--;       // remove old char

            if (s1count == s2window)
                return true;
        }

        return false;
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (obj.checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}