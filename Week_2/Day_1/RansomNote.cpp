#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;

        vector<int> magcount(26, 0);

        for (int i = 0; i < magazine.size(); i++) {
            magcount[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (magcount[ransomNote[i] - 'a'] == 0) {
                return false;
            }
            magcount[ransomNote[i] - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution obj;

    string ransomNote, magazine;

    cout << "Enter ransomNote: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    if (obj.canConstruct(ransomNote, magazine))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}