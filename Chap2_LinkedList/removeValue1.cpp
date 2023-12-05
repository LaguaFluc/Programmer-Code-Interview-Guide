


#include <set>
#include <stack>
struct Node {
    int val;
    Node * next = nullptr;
};

Node* removeVal1(Node* head, int num){
    stack<Node*> stk;
    while (nullptr != head){
        if (head->val != num){
            stack.push(head);
        }
        head = head->next;
    }
    while (!stk.empty()){
        stk.top()->next = head;
        head = stk.top();
        stk.pop();
    }
    return head;
}

Node* removeVal2(Node* head, int num){
    Node* newHead = new Node(head->val);

    while (head != nullptr){
        if (head->val != num){
            break;
        }
        head = head->next;
    }
    Node * cur = head;
    Node* pre = head;
    while (cur != nullptr){
        if (cur->val == num){
            pre->next = cur->next;
        }
        else{
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

