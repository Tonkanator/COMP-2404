#include <istream>
#include <string>

#include "HeapArrays.h"
#include "StackArrays.h"
#include "defs.h"

bool testStackObjectArray();
bool testStackPointerArray();
bool testHeapObjectArray();
bool testHeapPointerArray();
// bool constTest();

extern const string content[12];
extern const string ids[12];
extern const Rectangle rects[12];

int main()
{

  int choice = 0;
  cout << "Enter one of the following options: " << endl;
  cout << "0. Test StackArrays::getObjectArray" << endl;
  cout << "1. Test StackArrays::getPointerArray" << endl;
  cout << "2. Test HeapArrays::getObjectArray" << endl;
  cout << "3. Test HeapArrays::getPointerArray" << endl;
  // cout<<"4. Test const"<<endl;
  cin >> choice;
  bool flag = true;
  switch (choice)
  {
  case 0:
    flag = testStackObjectArray();
    break;
  case 1:
    flag = testStackPointerArray();
    break;
  case 2:
    flag = testHeapObjectArray();
    break;
  case 3:
    flag = testHeapPointerArray();
    break;
    // case 4: flag = constTest(); break;
  }

  if (flag)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

bool testHeapObjectArray()
{
  HeapArrays ha;
  string title;
  cout<<"Enter 3 strings (separated by spaces): "<<endl;
  for (int i = 0; i < 3; ++i)
  {
    cin >> title;
    TextArea ta(rects[i], title, content[i]);
    ha.addTextArea(ta);
  }
  TextArea *ta = ha.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    // ha.getTextAreaReference(i).print();
    ta[i].print();
    if (&ta[i] != &ha.getReference(i))
    {
      cout << "Wrong object returned by getTextAreaReference" << endl;
      return false;
    }
  }
  cout << "testHeapObjectArray passed" << endl;
  return true;
}

bool testHeapPointerArray()
{
  HeapArrays ha;
  string title;
  cout << "Enter 3 strings (separated by spaces): " << endl;

  for (int i = 0; i < 3; ++i)
  {
    cin >> title;
    TextArea ta(rects[i], title, content[i]);
    ha.addTextArea(ta);
  }
  TextArea **ta = ha.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    // ha.getTextAreaPointer(i)->print();
    (*ta[i]).print();
    if (ta[i] != ha.getPointer(i))
    {
      cout << "Wrong object returned by getTextAreaPointer" << endl;
      return false;
    }
  }
  cout << "testHeapPointerArray passed" << endl;
  return true;
}

bool testStackObjectArray()
{
  StackArrays sa;
  string title;
  cout << "Enter 3 strings (separated by spaces): " << endl;
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    cin >> title;
    TextArea ta(rects[i], title, content[i]);
    sa.addTextArea(ta);
  }
  const TextArea *ta = sa.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    // sa.getTextAreaReference(i).print();
    ta[i].print();
    if (&ta[i] != &sa.getReference(i))
    {
      cout << "Wrong object returned by getTextAreaReference" << endl;
      return false;
    }
  }
  cout << "testStackObjectArray passed" << endl;
  return true;
}

bool testStackPointerArray()
{
  StackArrays sa;
  string title;
  cout << "Enter 3 strings (separated by spaces): " << endl;
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    cin >> title;
    TextArea ta(rects[i], title, content[i]);
    sa.addTextArea(ta);
  }
  TextArea **ta = sa.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i)
  {
    // sa.getTextAreaPointer(i)->print();
    (*ta[i]).print();
    if (ta[i] != sa.getPointer(i))
    {
      cout << "Wrong object returned by getPointer" << endl;
      return false;
    }
  }
  cout << "testStackPointerArray passed" << endl;
  return true;
}

const Rectangle rects[12] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {1,1,1,1},{2,2,2,2},{3,3,3,3,},{4,4,4,4},{5,5,5,5},{6,6,6,6},{7,7,7,7},{8,8,8,8},{9,9,9,9}};


const string content[12] = {
    R"(picture
  ___
 / _ \
| (_) |
 \___/
)",

    R"(picture
  ,--.
 /  0 \
|   .  |
 \___/
)",

    R"(picture
  ,--.
 /  0 \
|   |  |
 \___/
)",

    R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

    R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

    R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

    R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

    R"(
  ____
 /  00\
|    0 |
|______|
)",

    R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

    R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)",

    R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

    R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"};