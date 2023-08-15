node* FlipList(node* head)
{
    if (head == nullptr)
    {
        return head;
    }

    node* rest = FlipList(head->next);
    
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
