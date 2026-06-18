#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (count == 1)
            return NULL;

        int run = count - n + 1;

        ListNode* prev = NULL;
        temp = head;
        ListNode* nex = head->next;
        int tempcount = 0;

        if (count == n) {
            return head->next;
        }

        while (tempcount < run) {
            tempcount++;

            if (run == tempcount) {
                prev->next = temp->next;
                return head;
            }

            prev = temp;
            temp = nex;

            if (nex != NULL)
                nex = nex->next;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    cout << "Original List: ";
    printList(head);

    head = obj.removeNthFromEnd(head, 2);

    cout << "After Removing 2nd Node from End: ";
    printList(head);

    return 0;
}