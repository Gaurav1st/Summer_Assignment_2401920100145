#include <iostream>
#include <vector>
#include <algorithm>  // for max

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maximumsum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            maximumsum = max(maximumsum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maximumsum;
    }
};

int main() {
    Solution sol;

   
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

   
    int result = sol.maxSubArray(nums);

   
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}
