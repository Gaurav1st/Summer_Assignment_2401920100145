#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> v(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                v[i] = st.top() - i;
            }

            st.push(i);
        }

        return v;
    }
};

int main() {
    int n;
    cout << "Enter number of temperatures: ";
    cin >> n;

    vector<int> temperatures(n);

    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    Solution obj;
    vector<int> ans = obj.dailyTemperatures(temperatures);

    cout << "Answer: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}