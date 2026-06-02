#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>   // for INT_MIN

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxaverage = INT_MIN;
        double sum = 0;

        // Initial window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double average = sum / k;
        maxaverage = max(maxaverage, average);

        // Sliding window
        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - k];
            average = sum / k;
            maxaverage = max(maxaverage, average);
        }
        return maxaverage;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = sol.findMaxAverage(nums, k);

    cout << "Maximum average of subarray of length " << k << " is: " << result << endl;

    return 0;
}
