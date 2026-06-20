#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> prevSmallest(vector<int>& heights, int n)
{
    vector<int> v;
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        v.push_back(st.top());
        st.push(i);
    }

    return v;
}

vector<int> nextSmallest(vector<int>& heights, int n)
{
    vector<int> v(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        v[i] = st.top();
        st.push(i);
    }

    return v;
}

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();

        vector<int> prev = prevSmallest(heights, n);
        vector<int> next = nextSmallest(heights, n);

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            if (next[i] == -1)
                next[i] = n;

            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;

            int area = length * breadth;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution obj;

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area = "
         << obj.largestRectangleArea(heights);

    return 0;
}