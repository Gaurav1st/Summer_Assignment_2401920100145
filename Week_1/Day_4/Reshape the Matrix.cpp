#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();

        if (r * c != row * col) {
            return mat;
        }

        vector<vector<int>> v(r, vector<int>(c));
        int k = 0;
        for (int i = 0; i < r * c; i++) {
            v[i / c][i % c] = mat[k / col][k % col];
            k++;
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    int r = 1, c = 4;

    vector<vector<int>> result = sol.matrixReshape(mat, r, c);

    for (auto& row : result) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
