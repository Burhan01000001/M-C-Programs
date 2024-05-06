#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct LinkedList {
    struct Node *head;
};

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(struct LinkedList *list, int val) {
    struct Node *newNode = createNode(val);
    if (list->head != NULL) {
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    list->head = newNode;
}

void forwardDisplay(struct LinkedList *list) {
    struct Node *temp = list->head;
    printf("\nForward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void reverseDisplay(struct LinkedList *list) {
    struct Node *temp = list->head;
    if (temp == NULL) {
        printf("\nBackward: List is empty\n");
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("\nBackward:\n");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void freeLinkedList(struct LinkedList *list) {
    struct Node *current = list->head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

int main() {
    int n, val;
    struct LinkedList list;
    list.head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        insertAtHead(&list, val);
    }

    forwardDisplay(&list);
    reverseDisplay(&list);

    // Free allocated memory
    freeLinkedList(&list);

    return 0;
}
