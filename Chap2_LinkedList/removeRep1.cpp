
#include <set>

struct Node {
    int val;
    Node* next = nullptr;
};

void removeRep1(Node* head){
    if (nullptr == head){
        return ;
    }
    set<int> s ;
    Node* pre = head;
    Node* cur = head->next;
    set.insert(pre->val);
    while (nullptr != cur){
        if (set.find(cur->val) != set.end()){
            pre->next = cur->next;
        }
        else{
            set.insert(cur->val);
            pre = cur;
        }
        cur = cur->next;
    }
}


void removeRep2(Node* head){
    Node* cur = head;
    Node* pre = nullptr;
    Node* next = nullptr;
    while (nullptr != cur){
        pre = cur;
        next = cur->next;
        while (next != nullptr){
            if (cur->val == next->val){
                pre->next = next->next;
            }
            else{
                pre = next;
            }
            next = next->next;
        }
    }
}