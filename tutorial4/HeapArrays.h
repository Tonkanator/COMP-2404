#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H
#include "defs.h"
#include "TextArea.h"

class HeapArrays{
    private:
        TextArea objects[MAX_ARRAY];
        TextArea* pointers[MAX_ARRAY];
        int numTA;
    public:
        HeapArrays();
        ~HeapArrays();
        TextArea* getObjectArray();
        TextArea** getPointerArray();
        TextArea* getPointer(int index);
        TextArea& getReference(int index);
        void addTextArea(TextArea& ta);
};

#endif