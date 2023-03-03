
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#include "bst.h"


/**
 * Print value of node.
 * @param node
 */
void print_val(struct node *node) {
    printf("node->val = %d\n", node->val);
}

#define NUM_NODES 10

int main() {
    int val;
    int rem[NUM_NODES];
    struct node *root = NULL;
    struct node *node = NULL;

    val = rand() % 100;

    rem[0] = val;
    printf("Insert: %d", val);
    node = new_node(val);
    root = insert_node(NULL, node);

    for (int i = 0; i < (NUM_NODES - 1); i++) {
        val = rand() % 100;
        printf(", %d", val);
        rem[i + 1] = val;
        node = new_node(val);
        insert_node(root, node);
    }


/*
    root = insert_node(root, new_node(55));
    root = insert_node(root, new_node(78));
    root = insert_node(root, new_node(30));
    root = insert_node(root, new_node(14));
    root = insert_node(root, new_node(24));
    root = insert_node(root, new_node(29));
    root = insert_node(root, new_node(25));
    root = insert_node(root, new_node(13));
    root = insert_node(root, new_node(57));
    root = insert_node(root, new_node(83));
    root = insert_node(root, new_node(1));
    root = insert_node(root, new_node(45));
    root = insert_node(root, new_node(79));
    root = insert_node(root, new_node(68));
    root = insert_node(root, new_node(1));
*/
    printf("\n\n");

    printf("Printing in order:\n");
    iterate_in_order(root, print_val);
    printf("\n");

    printf("Printing in pre-order:\n");
    iterate_pre_order(root, print_val);
    printf("\n");

    printf("Printing in post-order:\n");
    iterate_post_order(root, print_val);
    printf("\n");


    // Remove 3 random nodes
    val = rand() % (NUM_NODES - 3);
    for (int i = val; i < val + 3; i++) {
        printf("Remove node with value: %d\n", rem[i]);
        root = remove_node(root, rem[i]);
    }

 /* root = remove_node(root, 24);
    root = remove_node(root, 29);
    root = remove_node(root, 25);
    */
    printf("\n");

    printf("Printing in order:\n");
    iterate_in_order(root, print_val);
    printf("\n");

    printf("Printing in pre-order:\n");
    iterate_pre_order(root, print_val);
    printf("\n");

    printf("Printing in post-order:\n");
    iterate_post_order(root, print_val);
    printf("\n");

    /* Free each node*/
    iterate_post_order(root, free_node);

    return EXIT_SUCCESS;
}
