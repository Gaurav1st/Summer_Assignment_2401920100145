#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> st1;
    stack<int> st2;
    bool flag = false;

public:
    MyQueue() {}

    void push(int x) {

        if (!st2.empty()) {
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
            flag = false;
        }

        st1.push(x);
    }

    int pop() {
        if (st1.empty() && st2.empty())
            return -1;

        if (flag == false) {
            if (st2.empty()) {
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                int res = st2.top();
                st2.pop();
                flag = true;
                return res;
            } else {
                while (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
                int res = st1.top();
                st1.pop();
                flag = true;
                return res;
            }
        } else {
            if (st1.empty()) {
                int res = st2.top();
                st2.pop();
                return res;
            } else {
                int res = st1.top();
                st1.pop();
                return res;
            }
        }
    }

    int peek() {
        if (st1.empty() && st2.empty())
            return -1;

        if (flag == false) {
            if (st2.empty()) {
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                flag = true;
                return st2.top();
            } else {
                while (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
                flag = true;
                return st1.top();
            }
        } else {
            if (st1.empty())
                return st2.top();
            else
                return st1.top();
        }
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Front: " << q.peek() << endl;

    q.push(4);

    while (!q.empty()) {
        cout << q.pop() << " ";
    }

    cout << endl;

    return 0;
}