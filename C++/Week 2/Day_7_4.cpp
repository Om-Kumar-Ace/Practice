#include <iostream>
using namespace std;

class OM{
    protected:
        string title;
        float rating;
    public:
        OM(string s, float r){
            title =  s;
            rating = r;
        }
        virtual void display(){}
};

class OMVideo: public OM
{
    float videoLength;
    public:
        OMVideo(string s, float r, float vl): OM(s, r){
            videoLength = vl;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
        }
};    

class OMText: public OM
{
    int words;
    public:
        OMText(string s, float r, int wc): OM(s, r){
            words = wc;
        }
     void display(){
      cout<<"This is an amazing text tutorial with title "<<title<<endl;
      cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
      cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
         }
};

int main(){
    string title;
    float rating, vlen;
    int words;


    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    OMVideo djVideo(title, rating, vlen);


    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    OMText djText(title, rating, words);

    OM* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;

    tuts[0]->display();
    tuts[1]->display();

    return 0;
}
