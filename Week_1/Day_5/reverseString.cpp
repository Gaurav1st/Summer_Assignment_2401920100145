#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size() - 1;
        while (st < e) {
            swap(s[st], s[e]);
            st++;
            e--;
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}
