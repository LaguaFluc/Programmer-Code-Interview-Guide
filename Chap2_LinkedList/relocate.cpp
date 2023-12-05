

struct Node{
    int val;
    Node* next;
};

void relocate(Node* head){
    if (nullptr == head || nullptr == head->next){
        return ;
    }
    Node* mid = head;
    Node* right = head->next;
    // 快慢指针，最后mid是整个链表的中间节点，如果是偶数则是中间前面的一个节点
    while (right->next != nullptr && right->next->next != nullptr){
        mid = mid->next;
        right = right->next->next;
    }
    // right是后半部分的链表的头
    right = mid->next;
    mid->next = nullptr;
    mergeLR(head, right);
}

void mergeLR(Node* left, Node* right){
    Node* next = nullptr;
    // 相当于是合并两个链表到left链表中去
    // 1. 保存right链表的下一个节点
    // 2. right的下一个节点是left的下一个节点
    // 3. left的下一个节点是right
    // 开始向后移动
    // 4、 left 移动到right的下一个节点中去
    // 5、 right移动到之前保存的next中去
    while (left->next != nullptr){
        next = right->next;
        right->next = left->next;
        left->next = right;
        left = right->next;
        right = next;
    }
    left->next = right;
}