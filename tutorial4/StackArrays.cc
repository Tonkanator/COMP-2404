#include "StackArrays.h"

StackArrays::StackArrays(){
    numTA = 0;
}

StackArrays::~StackArrays(){
    for (int i=0; i<numTA; i++){
        delete pointers[i];
    }
}
TextArea* StackArrays::getObjectArray(){
    return objects;
}

TextArea** StackArrays::getPointerArray(){
    return pointers;
}
TextArea* StackArrays::getPointer(int index){
    return pointers[index];
}

TextArea& StackArrays::getReference(int index){
    return objects[index];
}

void StackArrays::addTextArea(TextArea& ta){
    if (numTA < MAX_ARRAY){
        objects[numTA] = ta;
        pointers[numTA] = new TextArea(ta);
        numTA++;
    }
}