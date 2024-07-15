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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; } 
        if (!l2) { return l1; }
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;            
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = lists.size();
        while (s > 1) {
            if (s % 2 == 1) { // if lists size is odd, tag the odd one out at the end to the 2nd to last one
                lists[s - 2] = mergeTwoLists(lists[s - 2], lists[s - 1]);
            }
            for (int i = 0; i < s - 1; i += 2) { // merge the even list 2 at a time
                lists[i / 2] = mergeTwoLists(lists[i], lists[i + 1]); // store merged results to the front of the vector
            }
            s = (s + 1) / 2; // halve the search space to the modified contents only 
        }
        return s < 1 ? nullptr : lists[0]; // if lists.empty then ret null, else return lists[0]
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
    
    // Test mergeTwoLists
    ListNode* l1 = createList({1, 3, 5});
    ListNode* l2 = createList({2, 4, 6});
    ListNode* mergedList = sol.mergeTwoLists(l1, l2);
    cout << "Merged Two Lists: ";
    printList(mergedList);

    // Test mergeKLists
    vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    ListNode* mergedKLists = sol.mergeKLists(lists);
    cout << "Merged K Lists: ";
    printList(mergedKLists);

    return 0;
}
