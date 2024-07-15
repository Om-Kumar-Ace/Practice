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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* temp1;
        ListNode* prev = nullptr;
        head = head->next;
        int cnt = 0;
        
        while (temp != nullptr && temp->next != nullptr) {
            temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = temp;
            if (cnt == 1) {
                prev->next = temp1;
            }
            prev = temp;
            temp = temp->next;
            cnt = 1;
        }
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test swapPairs
    ListNode* list = createList({1, 2, 3, 4});
    ListNode* swappedList = sol.swapPairs(list);
    cout << "Swapped List: ";
    printList(swappedList);

    return 0;
}
