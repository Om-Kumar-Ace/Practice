#include <iostream>
using namespace std;

// Abstract base class
class OM {
protected:
    string title;
    float rating;

public:
    // Constructor to initialize title and rating
    OM(string s, float r) : title(s), rating(r) {}

    // Pure virtual function making this class abstract
    virtual void display() = 0;
};

// Derived class for video content
class OMVideo : public OM {
    float videoLength;

public:
    // Constructor to initialize all members
    OMVideo(string s, float r, float vl) : OM(s, r), videoLength(vl) {}

    // Overriding the display function
    void display() {
        cout << "This is an amazing video with title " << title << endl;
        cout << "Ratings: " << rating << " out of 5 stars" << endl;
        cout << "Length of this video is: " << videoLength << " minutes" << endl;
    }
};

// Derived class for text content
class OMText : public OM {
    int words;

public:
    // Constructor to initialize all members
    OMText(string s, float r, int wc) : OM(s, r), words(wc) {}

    // Overriding the display function
    void display() {
        cout << "This is an amazing text tutorial with title " << title << endl;
        cout << "Ratings of this text tutorial: " << rating << " out of 5 stars" << endl;
        cout << "No of words in this text tutorial is: " << words << " words" << endl;
    }
};

int main() {
    string title;
    float rating, vlen;
    int words;

    // Creating a video object
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    OMVideo djVideo(title, rating, vlen);

    // Creating a text tutorial object
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    OMText djText(title, rating, words);

    // Array of pointers to base class to demonstrate polymorphism
    OM* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    // Displaying the content using base class pointers
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}
