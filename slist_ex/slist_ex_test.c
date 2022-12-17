#include <stdio.h> /*printf */
#include <assert.h> /* assert */

#include "tests.h"
#include "slist_ex.h"


static void PrintList(node_t *head);
static void TestSlist();


int main()
{
    TestSlist();
    PASS;

    return 0;
}

void TestSlist()
{
    node_t *head = NULL;

    node_t *list_2 = NULL;

    int int_arr[6] = {1, 2, 3, 5, 8, 13};
    
    list_2 = PushNode(list_2, &int_arr[3]);
    list_2 = PushNode(list_2, &int_arr[4]);
    list_2 = PushNode(list_2, &int_arr[5]);

    head = PushNode(head, &int_arr[0]);
    head = PushNode(head, &int_arr[1]);
    head = PushNode(head, &int_arr[2]);

    PrintList(head);
    head = Flip(head);
    puts("**** Print after flip ****");
    PrintList(head);

    TEST("HasLoop", HasLoop(head), 0);

    printf("FindIntersection: should ret NULL %p\n", 
        (void *)FindIntersection(head, list_2));

    printf("FindIntersection: should ret address %p\n", 
        (void *)FindIntersection(head, head));

    Destroy(head);
    Destroy(list_2);
}

void PrintList(node_t *head)
{
    node_t *temp = NULL;

    assert(head);

    temp = head;

    while(temp)
    {
        printf("%d \n", *(int *)temp->data);
        temp = temp->next;
    }
}
