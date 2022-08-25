#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node * next;
} node_t;

void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}
void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main()
{
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->val = 1;
    head->next = NULL;
    push(1,2 );
    push(2,4 );

    print_list(head);

}


