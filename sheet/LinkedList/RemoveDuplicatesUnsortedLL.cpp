Node * removeDuplicates( Node *head) 
    {
        unordered_set<int>set;
        Node* temp = head;
        set.insert(head->data);
        while(temp->next!=NULL)
        {
            if(set.find(temp->next->data)!=set.end())
            {
                temp->next = temp->next->next;   
            }
            else
            {
                set.insert(temp->next->data);
                temp = temp->next;
            }
        }
        return head;
    }
