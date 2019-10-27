//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* temp=head;
    if(position==0){
        head=head->next;
    }
    else if(position==1){
        head->next=head->next->next;
    }
    else{
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }

    return head;
}