//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* aux = new SinglyLinkedListNode(data);

    if(head == NULL)
    {
        head = aux;
        return aux;
    }
    while(temp ->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next=aux;
    return head;
    
}