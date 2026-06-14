#include <bits/stdc++.h>
using namespace std;

bool isanagrams(string s, string t) {
    if (s.size() != t.size())
        return false;

    int freq[26] = {0};

    for (char c : s)
        freq[c - 'a']++;

    for (char c : t)
        freq[c - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)
            return false;
    }

    return true;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<bool> visited(n, false);
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;

            vector<string> type;
            type.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!visited[j] &&
                    isanagrams(strs[i], strs[j])) {
                    type.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            result.push_back(type);
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = obj.groupAnagrams(strs);

    for (auto &group : ans) {
        for (auto &s : group)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}