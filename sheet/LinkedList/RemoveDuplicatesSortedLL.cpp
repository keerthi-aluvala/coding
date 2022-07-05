void removeDuplicates(struct Node* head)
{
    
    if(head==NULL) return NULL;
    while(head->next!=NULL)
    {
        if(head->data==head->next->data)
        {
            head->next=head->next->next;
        }
        else
            head = head->next;
    }
    
}
