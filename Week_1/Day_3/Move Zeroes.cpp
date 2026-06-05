#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0;
        int sec=1;
        while(sec<nums.size()&&s<nums.size())
        {
            if(nums[s]==0&&nums[sec]!=0)
            {
                swap(nums[s],nums[sec]);
                s++;
                sec++;
            }
            else if(nums[s]!=0&&nums[sec]!=0|| nums[s]!=0&& nums[sec]==0)
            {
                s++;
                sec++;
            }
            else
            {
                sec++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    sol.moveZeroes(nums);

    cout << "Result: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
