#include <stdlib.h>

// Standard node for a doubly linked list
typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head; // Sentinel head
    Node *tail; // Sentinel tail
    int size;
} MyLinkedList;

/** Initializes the MyLinkedList object */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->head->prev = NULL;
    obj->tail->next = NULL;
    obj->size = 0;
    return obj;
}

/** Helper to get node at specific index */
Node* getNodeAtIndex(MyLinkedList* obj, int index) {
    Node* curr;
    // Optimization: start from head or tail depending on index proximity
    if (index < obj->size / 2) {
        curr = obj->head->next;
        for (int i = 0; i < index; i++) curr = curr->next;
    } else {
        curr = obj->tail->prev;
        for (int i = 0; i < obj->size - 1 - index; i++) curr = curr->prev;
    }
    return curr;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    return getNodeAtIndex(obj, index)->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
    newNode->next = obj->head->next;
    newNode->prev = obj->head;
    
    obj->head->next->prev = newNode;
    obj->head->next = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
    newNode->next = obj->tail;
    newNode->prev = obj->tail->prev;
    
    obj->tail->prev->next = newNode;
    obj->tail->prev = newNode;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;
    if (index < 0) index = 0;
    
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node* successor = getNodeAtIndex(obj, index);
    Node* predecessor = successor->prev;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
    newNode->next = successor;
    newNode->prev = predecessor;
    predecessor->next = newNode;
    successor->prev = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    
    Node* toDelete = getNodeAtIndex(obj, index);
    Node* predecessor = toDelete->prev;
    Node* successor = toDelete->next;
    
    predecessor->next = successor;
    successor->prev = predecessor;
    
    free(toDelete);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}