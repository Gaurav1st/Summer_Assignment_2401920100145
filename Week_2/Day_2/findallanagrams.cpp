#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string p, string s) {

        if (s.size() > p.size())
            return {};

        vector<int> scount(26, 0), pwindow(26, 0);
        vector<int> v;

        for (char c : s) {
            scount[c - 'a']++;
        }

        int k = s.size();

        // first window
        for (int i = 0; i < k; i++) {
            pwindow[p[i] - 'a']++;
        }

        if (scount == pwindow)
            v.push_back(0);

        // sliding window
        for (int i = k; i < p.size(); i++) {
            pwindow[p[i] - 'a']++;       
            pwindow[p[i - k] - 'a']--;   

            if (scount == pwindow)
                v.push_back(i - k + 1);
        }

        return v;
    }
};

int main() {
    Solution obj;

    string p, s;
    cin >> p >> s;

    vector<int> ans = obj.findAnagrams(p, s);

    for (int i : ans) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}