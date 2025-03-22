#ifndef COMPONENTLIST_H
#define COMPONENTLIST_H

#include "defs.h"
#include "Component.h"

class ComponentList{
    private:
        struct Node{
            Component* component;
            Node* prev;
            Node* next;
            Node(Component* component) : component(component), prev(nullptr), next(nullptr) {}
        };
        Node* head;
        Node* tail;
        int size;
    public:
        ComponentList();
        ~ComponentList();
        bool add(Component* comp);
        bool add(Component* comp, int index);
        Component* remove(const std::string& id);
        Component* remove(int index);
        Component* get(const std::string& id) const;
        Component* get(int index) const;
        int getSize() const;
};

#endif