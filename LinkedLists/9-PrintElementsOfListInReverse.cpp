//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem


/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    if(head == NULL)
        return;
 
    reversePrint(head->next);
    cout << head -> data << endl;
}