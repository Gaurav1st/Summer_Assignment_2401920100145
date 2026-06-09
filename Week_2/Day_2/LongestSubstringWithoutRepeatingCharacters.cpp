#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visit;
        int leftofwindow = 0;
        int ans = 0;

        for (int rightofwindow = 0; rightofwindow < s.size(); rightofwindow++) {

            while (visit.count(s[rightofwindow])) {
                visit.erase(s[leftofwindow]);
                leftofwindow++;
            }

            visit.insert(s[rightofwindow]);
            ans = max(ans, rightofwindow - leftofwindow + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}