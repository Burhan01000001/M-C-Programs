#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

// Renamed the function to avoid conflict with reserved keyword
struct BST* CreateNode() {
    struct BST* new_node = (struct BST*) malloc(sizeof(struct BST));
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) { // When tree is empty
        struct BST* new_node = CreateNode();
        new_node->data = value;
        *RootPtr = new_node;
    } else if (value <= temp->data) { // If value is less than or equal to current node value, insert in the left subtree
        if (temp->left == NULL) {
            struct BST* new_node = CreateNode();
            new_node->data = value;
            temp->left = new_node;
        } else {
            Insert(&(temp->left), value); // Recursively insert into the left subtree
        }
    } else { // If value is greater than current node value, insert in the right subtree
        if (temp->right == NULL) {
            struct BST* new_node = CreateNode();
            new_node->data = value;
            temp->right = new_node;
        } else {
            Insert(&(temp->right), value); // Recursively insert into the right subtree
        }
    }
}

int Search(struct BST* RootPtr, int item) {
    if(RootPtr == NULL) {
        return 0; // Returns 0 if tree is empty
    } else if(item == RootPtr->data) {
        return 1; // Returns 1 when element found
    } else if(item < RootPtr->data) {
        return Search(RootPtr->left, item); // Recursively search in left subtree
    } else {
        return Search(RootPtr->right, item); // Recursively search in right subtree
    }
}

int main() {
    struct BST* RootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        Insert(&RootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(Search(RootPtr, key) == 1) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }

    return 0;
}
