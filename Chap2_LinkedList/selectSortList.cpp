

struct Node{
    int val;
    Node* next;
};

Node* selecttionSort(Node* head){
    Node* tail = nullptr;       // 排序部分尾部
    Node* cur = head;        // 遍历部分, 末排序部分头部
    Node* smallPre = nullptr;   // 最小节点的前一个节点

    Node* small = nullptr;      // 最小的节点

    while (nullptr != cur)
    {
        small = cur;
        smallPre = getSmallestPreNode(cur);
        if (nullptr != smallPre){
            small = smallPre->next;
            smallPre->next = small->next;
        }
        cur = cur == small ? cur->next : cur;

        if (nullptr == tail){
            head = small;
        }
        else{
            tail->next = small;
        }
        tail = small;
    }
    return head;
    
}

Node* getSmallestPreNode(Node* head){
    Node* smallPre = nullptr;
    Node* small = head;
    Node* pre = head;
    Node* cur = head->next;
    while (nullptr != cur){
        if (cur->val < small->val){
            smallPre = small;
            small = cur;
        }
        pre = cur;
        cur = cur->next;
    }
    return smallPre;
}