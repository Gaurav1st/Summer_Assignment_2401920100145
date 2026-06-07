#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];
        int idx = 0;
        while (idx < s1.size() && idx < s2.size()) {
            if (s1[idx] == s2[idx]) {
                idx++;
            } else {
                break;
            }
        }
        return s1.substr(0, idx);
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
