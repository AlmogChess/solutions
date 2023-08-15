node *FlipList(node *head)
{
    node *curr = head;
    node *next = nullptr;
    node *prev = nullptr;
    
    while(curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
