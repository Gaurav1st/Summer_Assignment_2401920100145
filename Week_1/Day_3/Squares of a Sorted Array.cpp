#include <iostream>
#include <vector>
#include <cmath>   // for abs
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v(nums.size(), 0);
        int k = nums.size() - 1;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            if (abs(nums[e]) > abs(nums[s])) {
                v[k] = nums[e] * nums[e];
                e--;
                k--;
            } else {
                v[k] = nums[s] * nums[s];
                s++;
                k--;
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sol.sortedSquares(nums);

    cout << "Sorted Squares: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
