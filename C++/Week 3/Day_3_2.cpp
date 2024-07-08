#include <iostream>
#include <list>

using namespace std;

// Function to display the elements of the list
void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list1; // Empty list of 0 length

    // Adding elements to list1
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);

    display(list1); // Displaying elements of list1

    list<int> list2(3); // Empty list of length 3
    list<int>::iterator it = list2.begin();
    *it = 45; // Assigning value to first element
    it++;
    *it = 6; // Assigning value to second element
    it++;
    *it = 9; // Assigning value to third element

    display(list2); // Displaying elements of list2

    list1.pop_back(); // Removing last element from list1
    display(list1); // Displaying elements of list1 after pop_back
    list1.pop_front(); // Removing first element from list1
    display(list1); // Displaying elements of list1 after pop_front
    list1.sort(); // Sorting elements of list1
    display(list1); // Displaying elements of sorted list1

    return 0;
}
