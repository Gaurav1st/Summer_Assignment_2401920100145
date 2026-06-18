#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* list1prev = NULL;
        ListNode* list1next = list1->next;
        ListNode* list2next = list2->next;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 && temp2)
        {
            if(temp2->val <= temp1->val)
            {
                if(list1prev == NULL)
                {
                    temp2->next = temp1;
                    list1 = temp2;
                }
                else
                {
                    list1prev->next = temp2;
                    temp2->next = temp1;
                }

                list1prev = temp2;
                temp2 = list2next;
                if(list2next)
                    list2next = list2next->next;
            }
            else
            {
                if(list1next == NULL)
                {
                    temp1->next = temp2;
                    return list1;
                }

                list1prev = temp1;
                temp1 = list1next;
                list1next = list1next->next;
            }
        }

        return list1;
    }
};

// Create linked list
ListNode* createList(int arr[], int n) {
    if(n == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(ans);

    return 0;
}