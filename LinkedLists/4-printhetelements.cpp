//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

void printLinkedList(SinglyLinkedListNode* head) {
    while(head){
        cout<<head->data<<endl;
        head=head->next;
    }
}