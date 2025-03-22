#include "ComponentList.h"

ComponentList::ComponentList(): head(nullptr), tail(nullptr), size(0) {}

ComponentList::~ComponentList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->component; // Delete the Component
        delete current;           // Delete the Node
        current = next;
    }
}

bool ComponentList::add(Component* comp) {
    if (comp == nullptr || size >= MAX_COMPONENTS) {
        return false;
    }

    // Check if the component is already in the list
    Node* current = head;
    while (current != nullptr) {
        if (current->component == comp) {
            return false; // Component is already in the list
        }
        current = current->next;
    }

    Node* newNode = new Node(comp);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size++;
    return true;
}

bool ComponentList::add(Component* comp, int index) {
    if (comp == nullptr || index < 0 || index > size) {
        return false;
    }

    // Check if the component is already in the list
    Node* current = head;
    while (current != nullptr) {
        if (current->component == comp) {
            return false; // Component is already in the list
        }
        current = current->next;
    }

    Node* newNode = new Node(comp);

    if (index == size) {
        return add(comp);
    }

    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    size++;
    return true;
}

Component* ComponentList::remove(const std::string& id) {
    Node* current = head;

    while (current != nullptr) {
        if (current->component->getID() == id) {
            // Update the previous node's next pointer
            if (current->prev == nullptr) {
                head = current->next;
            } else {
                current->prev->next = current->next;
            }

            // Update the next node's prev pointer
            if (current->next == nullptr) {
                tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            Component* removedComponent = current->component;
            delete current; // Delete the Node
            size--;

            return removedComponent;
        }

        current = current->next;
    }

    return nullptr;
}

Component* ComponentList::remove(int index) {
    if (index < 0 || index >= size) {
        return nullptr; // Index is invalid
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    // Update the previous node's next pointer
    if (current->prev == nullptr) {
        head = current->next;
    } else {
        current->prev->next = current->next;
    }

    // Update the next node's prev pointer
    if (current->next == nullptr) {
        tail = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    Component* removedComponent = current->component;
    delete current; // Delete the Node
    size--;

    return removedComponent;
}

Component* ComponentList::get(const std::string& id) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->component->getID() == id) {
            return current->component;
        }
        current = current->next;
    }

    return nullptr;
}

Component* ComponentList::get(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->component;
}

int ComponentList::getSize() const {
    return size;
}