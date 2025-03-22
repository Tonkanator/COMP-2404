#ifndef STACKARRAYS_H
#define STACKARRAYS_H
#include "TextArea.h"

class StackArrays{
    private:
        TextArea objects[MAX_ARRAY];
        TextArea* pointers[MAX_ARRAY];
        int numTA;
    public:
        StackArrays();
        ~StackArrays();
        TextArea* getObjectArray();
        TextArea** getPointerArray();
        TextArea* getPointer(int index);
        TextArea& getReference(int index);
        void addTextArea(TextArea& ta);
};

#endif