#include <iostream>

using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the position of a node with value 'n'
int findNode(Node* head, int n) {
    if (head == NULL)
        return -1;

    Node* curr = head;
    int pos = 0;

    while (curr != NULL) {
        if (curr->data == n)
            return pos;

        curr = curr->next;
        pos++;
    }
    return -1;
}

// Main function to test findNode
int main() {
    // Creating a simple linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    // Test findNode function
    int valueToFind = 30;
    int position = findNode(head, valueToFind);

    if (position != -1) {
        cout << "Value " << valueToFind << " found at position: " << position << endl;
    } else {
        cout << "Value " << valueToFind << " not found in the list." << endl;
    }

    // Cleanup
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
