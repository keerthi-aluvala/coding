struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head) return NULL;
        node* curr = head;
        node* Next = curr->next;
        node* prev = NULL;
        int count=0;
        while(curr!=NULL and count<k)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        if(Next!=NULL)
            head->next = reverse(Next,k);
        return prev;
    }
