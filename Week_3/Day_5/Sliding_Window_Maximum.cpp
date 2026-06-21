#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove indices whose values are smaller than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Push current index
            dq.push_back(i);

            // Store maximum for each complete window
            if (i >= k - 1)
                v.push_back(nums[dq.front()]);
        }

        return v;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = obj.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}