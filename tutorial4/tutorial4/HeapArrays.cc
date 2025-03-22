#include "HeapArrays.h"

HeapArrays::HeapArrays(){
    numTA = 0;
}

HeapArrays::~HeapArrays(){
    for (int i=0; i<numTA; i++){
        delete pointers[i];
    }
}
TextArea* HeapArrays::getObjectArray(){
    return objects;
}

TextArea** HeapArrays::getPointerArray(){
    return pointers;
}
TextArea* HeapArrays::getPointer(int index){
    return pointers[index];
}

TextArea& HeapArrays::getReference(int index){
    return objects[index];
}

void HeapArrays::addTextArea(TextArea& ta){
    if (numTA < MAX_ARRAY){
        objects[numTA] = ta;
        pointers[numTA] = new TextArea(ta);
        numTA++;
    }
}