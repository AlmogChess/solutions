#include <stdio.h> /*printf*/
#include <stdlib.h>

typedef struct node
{
	void *data;
	struct node *next;
} node_t;

node_t *Flip(node_t *head)
{
    node_t *prev;
    node_t *curr = head;
    node_t *next;

    while(curr != NULL)
    {

    }
}

int HasLoop(const node_t *head)
{

}

node_t *FindIntersection(node_t *head1, node_t head2)
{

}

void PrintList(node_t *head)
{
    node_t *temp = head;
    puts("while");

    while(temp != NULL)
    {
        puts("hwile");
        printf("%d \n", *(int *)temp->data);
        temp = temp->next;
    }
}


node_t *CreateNode(void *data)
{
    node_t *new_node;
    puts("CreateNode");

    new_node = (node_t *) malloc(sizeof(node_t));
    
    if (new_node == NULL)
    {
        puts("yes");
        return NULL;
    }
    new_node-> next = NULL;
    new_node->data = (void *)data;
    printf("data = %p", new_node->data);

    
    return 0; 
    
}

int main()
{
    node_t *head = NULL;
    int int_arr[6] = {1, 2, 3, 5, 8, 13};
    
    head = CreateNode((int *)int_arr[3]);
    
    printf("data = %d", *(int *)head->data);

    free(head);
    head = NULL;
    /*
	node_t *node1;
    node_t *node2;
	node_t *node3;
	node_t *node4;
	node_t *node5;

	int int_arr[6] = {1, 2, 3, 5, 8, 13};
	
    node1 = (node_t *) malloc(sizeof(node_t));
    if (node1 == NULL)
    {
        return 1;
    }
    node1->data = (void *)&int_arr[0];
    
    node1->next = node2;
    
    node2->data = (void *)&int_arr[1];
    node2->next = node3;
    
    node3->data = (void *)&int_arr[2];
    node3->next = node4;
    
    node4->data = (void *)&int_arr[3];
    node4->next = node5;
    
    node5->data = (void *)&int_arr[4];
    node5->next = NULL;

    printf("%d \n", *(int *)node5->data);

    PrintList(node1);*/

	return 0;
}







