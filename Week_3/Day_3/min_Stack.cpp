#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> real;
    stack<int> mini;

    MinStack() {

    }

    void push(int value) {
        if (real.empty())
            mini.push(value);
        else {
            if (value < mini.top())
                mini.push(value);
            else
                mini.push(mini.top());
        }

        real.push(value);
    }

    void pop() {
        if (!real.empty()) {
            real.pop();
            mini.pop();
        }
    }

    int top() {
        return real.top();
    }

    int getMin() {
        return mini.top();
    }
};

int main() {
    MinStack obj;

    obj.push(5);
    obj.push(2);
    obj.push(8);
    obj.push(1);

    cout << "Top: " << obj.top() << endl;
    cout << "Minimum: " << obj.getMin() << endl;

    obj.pop();

    cout << "\nAfter Pop:" << endl;
    cout << "Top: " << obj.top() << endl;
    cout << "Minimum: " << obj.getMin() << endl;

    return 0;
}