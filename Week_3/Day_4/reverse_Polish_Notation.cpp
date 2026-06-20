#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result;

        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                if (tokens[i] == "+")
                    result = b + a;
                else if (tokens[i] == "-")
                    result = b - a;
                else if (tokens[i] == "*")
                    result = b * a;
                else
                    result = b / a;

                st.push(result);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};

int main() {
    Solution obj;

    vector<string> tokens = {"2", "1", "+", "3", "*"};

    cout << "Answer = " << obj.evalRPN(tokens) << endl;

    return 0;
}