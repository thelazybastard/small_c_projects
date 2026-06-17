#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// create linked list for unknown number of basee 2 digits
typedef struct node {
    int value;
    struct node *next;
} node;

void binary_conversion(int num) {
    node *current_ptr = NULL;
    bool first_round = true;
    int num_store = num;

    while (true) {
        if (num_store == 0) {
            break;
        }

        int remainder = num_store % 2;
        num_store /= 2;

        if (first_round) {
            node *new_node = malloc(sizeof(node));
            new_node->value = remainder;
            new_node->next = NULL;
            current_ptr = new_node;
            first_round = false;
        } else {
            node *tmp = current_ptr;
            node *new_node = malloc(sizeof(node));
            new_node->value = remainder;
            new_node->next = tmp;
            current_ptr = new_node;
        }
    }

    printf("The result in binary is: ");
    while (current_ptr != NULL) {
        node *tmp = current_ptr;
        printf("%d", current_ptr->value);
        current_ptr = tmp->next;
    }
    printf("\n");
}
