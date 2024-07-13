#include <iostream>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
            return head;
        if (n == 0)
            return head;

        // Step 1: Calculate the length of the linked list
        int length = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            length++;
            curr = curr->next;
        }

        // Step 2: Check if we need to remove the head
        if (length == n)
        {
            curr = head->next;
            delete head; // Free the memory of the node being removed
            return curr;
        }

        // Step 3: Find the position of the node to remove
        curr = head;
        int changeFrom = length - n;
        int count = 1;
        while (count < changeFrom && curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        ListNode *nodeToRemove = curr->next;
        curr->next = curr->next->next;
        delete nodeToRemove; // Free the memory of the node being removed
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const std::vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val;
        if (current->next != nullptr)
            std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution solution;

    // Example usage:
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(values);
    std::cout << "Original list: ";
    printLinkedList(head);

    int n = 2;
    head = solution.removeNthFromEnd(head, n);
    std::cout << "After removing " << n << "-th node from the end: ";
    printLinkedList(head);

    return 0;
}
