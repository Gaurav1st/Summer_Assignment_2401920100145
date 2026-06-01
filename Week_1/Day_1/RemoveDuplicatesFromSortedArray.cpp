#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int wap = 1;
        int idx = 1;

        while (idx < nums.size()) {
            if (nums[idx] == nums[idx - 1]) {
                idx++;
            } else {
                nums[wap] = nums[idx];
                wap++;
                idx++;
            }
        }
        return wap;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    Solution obj;
    int k = obj.removeDuplicates(nums);

    cout << "Number of unique elements = " << k << endl;
    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}