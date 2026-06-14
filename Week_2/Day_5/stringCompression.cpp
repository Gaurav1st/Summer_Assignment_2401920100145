#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int res = 0;

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[res++] = ch;

            if (count > 1) {
                string digit = to_string(count);

                for (char c : digit) {
                    chars[res++] = c;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    Solution obj;
    int len = obj.compress(chars);

    cout << "Length = " << len << endl;
    cout << "Compressed Array: ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}