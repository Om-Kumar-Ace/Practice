#include <iostream>

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
        // Dummy node to act as the starting point of the merged list
        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;

        // Merging the two lists
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // If there are remaining nodes in list1
        if (list1) {
            tail->next = list1;
        }

        // If there are remaining nodes in list2
        if (list2) {
            tail->next = list2;
        }

        // The real head of the merged list
        ListNode* mergedHead = temp->next;
        delete temp;  // Free the dummy node

        return mergedHead;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Test code
int main() {
    // Creating test case linked lists
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Free the allocated memory
    ListNode* current = mergedList;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
