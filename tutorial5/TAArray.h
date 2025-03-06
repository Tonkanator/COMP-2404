#ifndef TAARRAY_H
#define TAARRAY_H
#include "defs.h"
#include "TextArea.h"

class TAArray{
    private:
        TextArea** taArray;
        int numTA;
    public:
        TAArray();
        bool add(TextArea* ta);
        bool add(TextArea* ta, int index);
        
        TextArea *get(int i) const;

        TextArea *get(const std::string &id) const;
        TextArea *remove(const std::string &id);
        TextArea *remove(int index);

        int getSize();
};

#endif