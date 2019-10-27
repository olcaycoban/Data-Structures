//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* node=head;
    DoublyLinkedListNode* add=new DoublyLinkedListNode(data);
    if(head==NULL){
        head=add;
        return head;
    }
    else if(add->data < head->data){
        add->next=head;
        head->prev=add;
        head=add;
        return head;
    }
    DoublyLinkedListNode* iter=head;
    DoublyLinkedListNode* temp=new DoublyLinkedListNode(0);
    
    while(iter->next!=NULL){
        if(data< (iter->next)->data){
            temp=iter->next;
            iter->next=add;
            add->prev=iter;
            add->next=temp;
            (add->next)->prev=add;
            return head;
        }
        iter=iter->next;
    }
    iter->next=add;
    add->prev=iter;
    
    return head;
}