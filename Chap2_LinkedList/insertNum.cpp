

struct Node{
    int val;
    Node* next;
};

Node* insertNum(Node* head, int num){
    Node* newNode = new Node(num, nullptr);
    if (nullptr == head){
        newNode->next = newNode;
        return newNode;
    }
    Node* pre = head;
    Node* cur = head->next;
    while (cur != head){
        if (pre->val <= num && num <= cur->val){
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = newNode;
    newNode->next = cur; 
    return head->val < num ? head : newNode;
}