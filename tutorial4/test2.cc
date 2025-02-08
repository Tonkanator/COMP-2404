#include <istream>
#include <string>

#include "TextArea.h"
#include "RGB.h"

using namespace std;

/*
* NOTE: If you did not const properly, this will not compile.
*/
int main(){

  cout<<endl<<"Testing RGB const"<<endl<<endl;
  
  const RGB red(255,0,0);
  red.getR();
  red.getG();
  red.getB();

  cout<<endl<<"Testing RGB static functions"<<endl<<endl;
  RGB red2 = RGB::RED();
  RGB green = RGB::GREEN();
  RGB blue = RGB::BLUE();
  RGB white = RGB::WHITE();
  RGB black = RGB::BLACK();


  cout<<endl<<"Testing TextArea const"<<endl<<endl;

  TextArea textArea(10,10,100,100,"id","text");
  textArea.setFill(red);
  textArea.setBorder(red);

  const Rectangle rect{10,10,100,100};
  const string id = "id";
  const string text = "text";
  const TextArea textArea2(rect,id,text);

  textArea2.print();

  const TextArea textArea3 = textArea2;
  textArea3.overlaps(textArea2);  

  //check overlaps, getters and constructors, setFill and setBorder
  
}

