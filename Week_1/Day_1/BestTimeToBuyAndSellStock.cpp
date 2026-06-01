#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if (n <= 1) return 0;

        vector<int> aux(n);

        aux[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            aux[i] = max(aux[i + 1], prices[i]);
        }

        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, aux[i] - prices[i]);
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution obj;
    cout << "Maximum Profit = " << obj.maxProfit(prices) << endl;

    return 0;
}