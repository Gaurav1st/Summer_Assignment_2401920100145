#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> arr;
        arr.reserve(row * col);
        int fr = 0, lr = row - 1, fc = 0, lc = col - 1, num = 0;

        while (num < row * col) {
            for (int i = fc; i <= lc && num < row * col; i++) {
                arr.push_back(matrix[fr][i]);
                num++;
            }
            fr++;
            for (int i = fr; i <= lr && num < row * col; i++) {
                arr.push_back(matrix[i][lc]);
                num++;
            }
            lc--;
            for (int i = lc; i >= fc && num < row * col; i--) {
                arr.push_back(matrix[lr][i]);
                num++;
            }
            lr--;
            for (int i = lr; i >= fr && num < row * col; i--) {
                arr.push_back(matrix[i][fc]);
                num++;
            }
            fc++;
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.spiralOrder(matrix);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
