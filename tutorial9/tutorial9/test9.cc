#include <istream>
#include <string>
#include <sstream>

#include "defs.h"
#include "Media.h"
#include "Array.h"

using namespace std;

int testAddRemove();

int main(){
  
    return testAddRemove();    
}

int testAddRemove(){
    cout<<"Testing add and remove"<<endl;
    string channelTitle = "My Channel";
    string owner = "The Owner";
    string mediaTitles[10] = {"Media 1", "Media 2", "Media 3", "Media 4", "Media 5", "Media 6", "Media 7", "Media 8", "Media 9", "Media 10"};
    string category = "Category";
    string content = "Content";
    string video = "Video";

    Array<Media*> arr;

    Media* media[10];

    if (arr.getSize()!=0){
      cout<<"Error, getSize of empty array not 0"<<endl;
      return 1;
    }

    cout <<"Adding 10 Media"<<endl;

    for (int i = 0; i < 10; ++i){
        media[i] = new Media(channelTitle, owner, mediaTitles[i], category, content, video);
        arr+=media[i];
        cout<<*media[i]<<endl;
    }
    
    if (arr.getSize()!=10){
      cout<<"Error, getSize of array should be 10, instead it is "<<arr.getSize()<<endl;
      return 1;
    }else{
      cout<<"getSize is 10, correct"<<endl;
    }

    if (arr.isFull()){
      cout<<"Error, array (should be getSize 10) is full. getSize() = "<<arr.getSize()<<endl;
      return 1;
    }else{
      cout<<"Array is not full, correct"<<endl;
    }

    cout<<"Remove every second Media:"<<endl;
    int count = 0;
    for (int i = 0; i < 10; i+=2){
        arr-=media[i];
    }

    if (arr.getSize()!=5){
      cout<<"Error, getSize of array should be 5, instead it is "<<arr.getSize()<<endl;
      return 1;
    }else{
      cout<<"getSize is 5, correct"<<endl;
    }

    for (int i = 0; i < 5; ++i){
        cout<<*arr[i]<<endl;
    }

    cout<<"Remove all but 2 Media:"<<endl;
    for (int i = 0; i < 7; ++i){
        arr-=media[i];
    }

    cout<<"Printing 2 Media:"<<endl;
    stringstream s1, s2;
    for (int i = 0; i < arr.getSize(); ++i){
        cout<<*arr[i]<<endl;
        s1<<*arr[i]<<endl;
    }

    s2 << *media[7] <<endl << *media[9] <<endl;

    if (s1.str() == s2.str()){
      cout<<"Media are correct"<<endl;
    }else{
      cout<<"Media are not correct:"<<endl<<s1.str()<<"Should be:"<<endl<<s2.str()<<endl;
      return 1;
    }

    
    cout <<"Deleting 10 Media"<<endl;

    for (int i = 0; i < 10; ++i){
        delete media[i];
    }
    return 0;
}



