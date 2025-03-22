#include "TAArray.h"

TAArray::TAArray(): numTA(0){
    taArray = new TextArea*[MAX_COMPONENTS];
}

TAArray::~TAArray(){
    delete [] taArray;
}

bool TAArray::add(TextArea* ta){
    if (numTA >= MAX_COMPONENTS){
        return false;
    }
    taArray[numTA] = ta;
    numTA++;
    return true;
}

bool TAArray::add(TextArea* ta, int index){
    if (!ta || index < 0 || numTA >= MAX_COMPONENTS || index > numTA){
        return false;
    }

    for (int i=numTA; i>index; i--){
        taArray[i] = taArray[i-1];
    }

    taArray[index] = ta;
    numTA++;
    return true;
}

TextArea* TAArray::get(int i) const{
    if (i<0 || i>=numTA){
        return nullptr;
    }
    return taArray[i];
}

TextArea* TAArray::get(const std::string &id) const{
    for (int i=0; i<numTA; i++){
        if (taArray[i]->getID() == id){
            return taArray[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(const std::string &id){
    TextArea* temp;

    for (int i=0; i<numTA; i++){
        if (taArray[i]->getID() == id){
            temp = taArray[i];
            for (int j=i; j<numTA-1; j++){
                taArray[j] = taArray[j+1];
            }
            numTA--;
            return temp;
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index){
    if (index < 0 || index >= numTA){
        return nullptr;
    }

    TextArea *temp;
    temp = taArray[index];
    
    for (int i=index; i < numTA-1; i++)
    {
        taArray[i] = taArray[i+1];
    }
    numTA--;
    return temp;
}

int TAArray::getSize() const{
    return numTA;
}