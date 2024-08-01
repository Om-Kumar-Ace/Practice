#include <iostream>
using namespace std;

int main() {
    int a=50,b=20;
    if(a>b)
    {
        if(a>100)
            printf ("Ace");
        if(b<100)
            b=50;
    }
    else if(a==b)
    {
       printf ("King");
    }
    else 
    {
        printf ("Queen");
    }
}