#include <iostream>
#include <vector>
#include <cmath>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // Get the length of the linked list
        int len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        // Determine the number of full k-groups
        int reverses = len / k;

        ListNode* start = nullptr;
        ListNode* prevStart = nullptr;
        ListNode* prev = nullptr;
        ListNode* after = nullptr;
        curr = head;

        for (int i = 0; i < reverses; i++) {
            start = curr;
            prev = curr;
            curr = curr->next;
            after = curr->next;
            for (int j = 0; j < k - 1; j++) {
                curr->next = prev;
                prev = curr;
                curr = after;
                if (after != nullptr)
                    after = after->next;
            }
            if (i == 0) {
                head = prev;
            } else {
                prevStart->next = prev;
            }
            prevStart = start;
        }
        prevStart->next = curr;

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

    // Test reverseKGroup
    ListNode* list = createList({1, 2, 3, 4, 5});
    int k = 3;
    ListNode* reversedList = sol.reverseKGroup(list, k);
    cout << "Reversed List in k-Groups: ";
    printList(reversedList);

    return 0;
}
