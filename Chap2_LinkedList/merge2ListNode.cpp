
struct Node {
    int val,
    Node* next;
};


Node* merge(Node* head1, Node* head2){
    if (nullptr == head1 || nullptr == head2){
        return head1 == nullptr ? head2 : head1;
    }
    Node* head = head1->val < head2->val ? head1 : head2;
    Node* cur1 = head == head1 ? head1 : head2;
    Node* cur2 = head == head1 ? head2: head1;
    Node* pre = nullptr;
    Node* next = nullptr;
    while (nullptr != cur1 && nullptr != cur2){
        if (cur1->val <= cur2->val){
            pre = cur1;
            cur1 = cur1->next;
        }
        else{
            next = cur2->next;
            pre->next = cur2;
            cur2->next = cur1;
            pre = cur2;
            cur2 = next;
        }
    }
    pre->next = cur1 == nullptr ? cur2 : cur1;
    return head;
}