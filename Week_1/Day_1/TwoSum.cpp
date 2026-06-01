#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> v;

        // store value + original index
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        // sort based on value
        sort(v.begin(), v.end());

        int s = 0;
        int e = v.size() - 1;

        while (s < e) {
            int sum = v[s].first + v[e].first;

            if (sum == target) {
                return {v[s].second, v[e].second};
            }
            else if (sum < target) {
                s++;
            }
            else {
                e--;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "Indices: " << ans[0] << " " << ans[1] << endl;

    return 0;
}