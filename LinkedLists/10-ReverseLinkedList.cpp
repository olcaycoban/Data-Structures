//https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *prev   = NULL;
    SinglyLinkedListNode *current = head;
    SinglyLinkedListNode *next;
    while (current != NULL) {
        next = current -> next;  
        current -> next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}