//https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (head == NULL){
        return NULL;
    }
    while(head != NULL){
        DoublyLinkedListNode* i = head->prev;
        head->prev = head->next;
        head->next = i;
        if (head->prev == NULL){
            return head;
        }
        head = head->prev;
    }
    return head;
}
