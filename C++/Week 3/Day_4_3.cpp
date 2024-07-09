#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);  // Dummy node to simplify code
        ListNode* p = &dummy;  // Pointer to the current node in the result list
        int carry = 0;  // Initialize carry to 0
        
        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // Start with the carry value
            
            if (l1 != nullptr) {
                sum += l1->val;  // Add value from l1 if available
                l1 = l1->next;  // Move to the next node in l1
            }
            
            if (l2 != nullptr) {
                sum += l2->val;  // Add value from l2 if available
                l2 = l2->next;  // Move to the next node in l2
            }
            
            carry = sum / 10;  // Calculate the new carry
            p->next = new ListNode(sum % 10);  // Create a new node with the digit value
            p = p->next;  // Move to the next node in the result list
        }
        
        return dummy.next;  // Return the next node after dummy, which is the head of the result list
    }
};

// Helper function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    
    std::cout << "Result: ";
    printList(result);  // Output should be 7 -> 0 -> 8
    
    return 0;
}
