#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm> // for std::for_each

// Base class A
class A {
public:
    virtual void show() {
        std::cout << "Base class A\n";
    }
};

// Base class B
class B {
public:
    virtual void display() {
        std::cout << "Base class B\n";
    }
};

// Derived class C with multiple inheritance
class C : public A, public B {
public:
    void show() override {
        std::cout << "Derived class C: show()\n";
    }

    void display() override {
        std::cout << "Derived class C: display()\n";
    }
};

// Function to demonstrate vector
void demoVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Function to demonstrate list
void demoList() {
    std::list<std::string> lst = {"apple", "banana", "cherry"};
    std::cout << "List elements: ";
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Function to demonstrate map
void demoMap() {
    std::map<int, std::string> mp = {{1, "one"}, {2, "two"}, {3, "three"}};
    std::cout << "Map elements: ";
    for (const auto& [key, value] : mp) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << "\n";
}

// Main function
int main() {
    // Demonstrate virtual functions
    A *ptrA = new C();
    B *ptrB = new C();

    std::cout << "Demonstrating virtual functions:\n";
    ptrA->show();
    ptrB->display();

    // Clean up
    delete ptrA;
    delete ptrB;

    // Demonstrate STL containers
    std::cout << "\nDemonstrating STL containers:\n";
    demoVector();
    demoList();
    demoMap();

    return 0;
}
