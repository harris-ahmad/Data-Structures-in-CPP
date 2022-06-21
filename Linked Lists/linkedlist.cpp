#include <iostream>

class Node {
   public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
   public:
    Node *head;
    LinkedList();
    void insertAtHead(int d);
    void insertAtTail(int d);
    void insertInBetween(int d, int before, int after);
    void deleteAtHead(void);
    void deleteTail(void);
    void deleteAny(int d);
    int getLength(void);
    int getElement(int d);
    bool findElement(int d);
    void reverseList(void);
    void display(void);
};

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtHead(int d) {
    Node *new_node = new Node(d);
    new_node->next = head;
    head = new_node;
}

void LinkedList::insertAtTail(int d) {
    Node *new_node = new Node(d);
    if (!head) {
        head = new_node;
        return;
    }
    Node *last_node = head;
    while (last_node->next) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void LinkedList::insertInBetween(int d, int before, int after) {
    Node *new_node = new Node(d);
    Node *prev_node = head;
    Node *next_node = head;
    while (prev_node->data != after) {
        prev_node = prev_node->next;
    }
    while (next_node->data != before) {
        next_node = next_node->next;
    }
    prev_node->next = new_node;
    new_node->next = next_node;
}

void LinkedList::deleteAtHead(void) {
    Node *curr = head;
    if (curr) {
        head = curr->next;
        delete curr;
        return;
    }
}

void LinkedList::deleteTail(void) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {  // if the list has a single element only
        delete head;
        return;
    }
    Node *prev_node = head;
    while (prev_node->next->next) {
        prev_node = prev_node->next;
    }
    delete prev_node->next;
}

void LinkedList::deleteAny(int d) {
    Node *curr = head;
    if (curr && curr->data == d) {
        head = curr->next;
        delete curr;
        return;
    }
    Node *prev = NULL;
    while (curr) {
        if (curr->data == d) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        return;
    }

    prev->next = curr->next;
    delete curr;
}

int LinkedList::getLength(void) {
    int count = 0;

    Node *curr = head;
    while (curr) {
        count += 1;
        curr = curr->next;
    }
    return count;
}

int LinkedList::getElement(int d) {
    Node *curr = head;
    bool found = false;

    while (curr) {
        if (curr->data == d) {
            found = true;
            break;
        }
        curr = curr->next;
    }
    if (found) {
        return d;
    } else {
        return -1;
    }
}

bool LinkedList::findElement(int d) {
    Node *curr = head;
    bool found = false;

    while (curr) {
        if (curr->data == d) {
            found = true;
            break;
        }
        curr = curr->next;
    }
    return found;
}

void LinkedList::reverseList(void) {
    Node *prev = NULL;
    Node *curr = head;

    while (curr) {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}

void LinkedList::display(void) {
    Node *curr = head;
    while (curr) {
        std::cout << curr->data << "-";
        curr = curr->next;
    }
    std::cout << "\n";
}

int main(int argc, char const *argv[]) {
    LinkedList lst;
    auto arr = {1, 2, 3, 4, 5};
    for (auto elem : arr) {
        lst.insertAtTail(elem);
    }
    // lst.insertInBetween(100, 3, 2);
    // lst.deleteAtHead();
    // lst.deleteAny(2);
    // lst.deleteTail();
    lst.display();
    // lst.reverseList();
    // lst.display();
    return 0;
}

