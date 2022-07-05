class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* Next;
        while(curr!=NULL)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        int carry = 0;
        Node* sum = NULL;
        while(first!=NULL or second!=NULL or carry==1)
        {
            int newVal = carry;
            if(first) newVal += first->data;
            if(second) newVal += second->data;
            carry = newVal/10;
            newVal = newVal%10;
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
            if(first) first = first->next;
            if(second) second = second->next;
        }
        return sum;
    }
};

