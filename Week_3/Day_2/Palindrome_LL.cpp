#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL(ListNode* curr)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revpointer = reverseLL(slow);
        slow = head;

        while(slow != NULL && revpointer != NULL)
        {
            if(slow->val != revpointer->val)
                return false;

            slow = slow->next;
            revpointer = revpointer->next;
        }

        return true;
    }
};

// Create linked list from vector
ListNode* createList(vector<int> arr)
{
    if(arr.empty()) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};   // Change input here

    ListNode* head = createList(arr);

    Solution obj;

    if(obj.isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}