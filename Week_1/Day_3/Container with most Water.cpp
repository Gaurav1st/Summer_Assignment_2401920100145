#include <iostream>
#include <vector>
#include <climits>   // for INT_MIN
#include <algorithm> // for min, max
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size() - 1;
        int sheight;
        int eheight;
        int area;
        int maxwater = INT_MIN;
        while (s < e) {
            sheight = height[s];
            eheight = height[e];
            area = min(sheight, eheight) * (e - s);
            maxwater = max(maxwater, area);
            if (min(sheight, eheight) == sheight)
                s++;
            else
                e--;
        }
        return maxwater;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(height);

    cout << "Maximum water area = " << result << endl;

    return 0;
}
