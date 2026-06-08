#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(26, 0);

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s = "anagram";
    string t = "nagaram";

    if (sol.isAnagram(s, t)) {
        cout << "Strings are anagrams" << endl;
    } else {
        cout << "Strings are not anagrams" << endl;
    }

    return 0;
}
