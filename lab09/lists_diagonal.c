#include <stdio.h>
#include <stdlib.h>

// Do not edit these structs. You may use them exactly as
// they are but you cannot make changes to them

// A node in a linked list
struct node {
    int data;
    struct node *next;
};

// a list_node in a linked list. Each list_node
// contains a list of nodes.
struct list_node {
    struct node *my_list;
    struct list_node *next;
};

// Treat the linked lists like they're a 2D array
// and return 1 if the first element is repeated
// diagonally through the lists
int has_diagonal(struct list_node *head) {
    int list = 0;
    struct list_node *currList = head;
    struct node *prevNode = NULL;
    
    // Loop through all the lists.
    while (currList != NULL) {
        int i = 0;
        struct node *currNode = currList->my_list;
        // Loop through to the correct node for this list.
        while (i < list) {
            currNode = currNode->next;
            i++;
        }
        
        // If it's not the first time running where prev is null and 
        // for the other runs, if the selected node is not equal in value to
        // the previous selected node, return 0 and end the function.
        if (prevNode != NULL && prevNode->data != currNode->data) {
            return 0;
        }
        
        // After current selected node has been tested, store it in prevNode
        // as it will become the one to test against for the next loop.s
        prevNode = currNode;
        list++;
        currList = currList->next;
    }

    return 1;
}

// This helper function is for the main below and will
// have no effect on your has_diagonal. It does not
// need to be modified.
struct node *make_list(int a, int b, int c);

// This is a main function which could be used
// to test your has_diagonal function.
// It will not be marked.
// Only your has_diagonal function will be marked.
//
// It's recommended to change the int values in this
// main to test whether your has_diagonal is working.
int main(void) {
    struct list_node *head = malloc(sizeof (struct list_node));
    struct list_node *l = head;
    
    // create the first list
    l->my_list = make_list(1, 0, 0);
    
    // create the second list
    l->next = malloc(sizeof (struct list_node));
    l = l->next;
    l->my_list = make_list(0, 5, 0);
    
    // create the third list
    l->next = malloc(sizeof (struct list_node));
    l = l->next;
    l->my_list = make_list(0, 0, 5);
    l->next = NULL;
    
    printf("The result of has_diagonal is: %d\n", has_diagonal(head));
    
    return 0;
}

struct node *make_list(int a, int b, int c) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    n->data = a;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = b;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = c;
    n->next = NULL;
    
    return head;
}
