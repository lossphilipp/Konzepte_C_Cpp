#include <stdio.h>

typedef struct {
    void* pNext;
    void* data;
} node_t;

void list_insertFront(node_t** pHead, node_t* pNewNode) {
    if (pNewNode == NULL) return;

    pNewNode->pNext = (void*)*pHead;
    *pHead = pNewNode;
};

void list_foreach(node_t* pHead, void (*func)(node_t*)) {
    node_t* current = pHead;
    while (current) {
        func(current);
        current = (node_t*)current->pNext;
    }
};