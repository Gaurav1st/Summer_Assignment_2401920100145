#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> v;

        for (int i = 0; i < n1; i++) {
            stack<int> st;

            for (int j = n2 - 1; j >= 0; j--) {
                st.push(nums2[j]);
            }

            int val = nums1[i];

            while (st.top() != val) {
                st.pop();
            }

            while (!st.empty() && st.top() <= val) {
                st.pop();
            }

            if (st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
        }

        return v;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> ans = obj.nextGreaterElement(nums1, nums2);

    cout << "Answer: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}