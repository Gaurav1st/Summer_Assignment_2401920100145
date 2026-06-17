#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> arr2; 
        ListNode* temp = head;
        while (temp) {
            arr2.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int j = arr2.size() - 1;
        while (temp) {
            temp->val = arr2[j];
            temp = temp->next;
            j--;
        }
        return head;
    }
};

int main() {
    
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;
    ListNode* result = sol.reverseList(n1);

    ListNode* temp = result;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
