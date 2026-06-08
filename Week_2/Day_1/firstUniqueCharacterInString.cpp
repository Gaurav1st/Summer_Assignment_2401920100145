#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

    
        for (char c : s) {
            freq[c - 'a']++;
        }

       
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int idx = sol.firstUniqChar(s);
    if (idx != -1) {
        cout << "First unique character is '" << s[idx] 
             << "' at index " << idx << endl;
    } else {
        cout << "No unique character found" << endl;
    }

    return 0;
}
