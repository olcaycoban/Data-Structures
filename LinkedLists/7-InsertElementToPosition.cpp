//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) 
{
    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* aux = new SinglyLinkedListNode(data);
    if(position == 0)
    {
        aux->next = temp;
        head = aux;
        return aux;
    }
    int idx = 0;
    while(idx != position - 1)
    {
        idx++;
        temp = temp->next;
    }
    aux->next = temp->next;
    temp->next = aux;
    return head;
}
