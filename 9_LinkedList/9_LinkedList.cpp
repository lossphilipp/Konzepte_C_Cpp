#include <stdlib.h>
#include "LinkedList.c"

void print_node_data_int(node_t* node) {
    printf("Node data: %d\n", *(int*)node->data);
}

int main() {
    node_t* head = NULL;

    for (int i = 1; i <= 3; i++) {
        int* data = (int*)malloc(sizeof(int));
        *data = i;

        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        newNode->data = data;
        list_insertFront(&head, newNode);
    }

    list_foreach(head, print_node_data_int);

    // prevent sonarqube from screaming about memory leaks
    node_t* current = head;
    while (current != NULL) {
        node_t* next = (node_t*)current->pNext;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}
