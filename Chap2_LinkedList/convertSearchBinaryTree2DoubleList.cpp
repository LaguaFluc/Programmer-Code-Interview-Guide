
#include<queue>
#include <iostream>
struct Node
{
    /* data */
    int val;
    Node* left;
    Node* right;
};

struct returnType {
    Node* start;
    Node* end;
};

Node convert2(Node* head){
    if (nullptr == head){
        return ;
    }
    return process(head).start;
}

returnType process(Node* head){
    if (nullptr == head){
        return returnType(nullptr, nullptr);
    }
    returnType leftList = process(head->left);
    returnType rightList = process(head->right);

    if (leftList.end == nullptr){
        leftList.end->right = head;
    }

    head->left = leftList.end;
    head->right = rightList.start;

    if (rightList.start != nullptr){
        rightList.start->left = head;
    }
    return returnType(
        leftList.start != nullptr ? leftList.start : head,
        rightList.end != nullptr ? rightList.end : head
    );

}
Node* convert1(Node* head){
    #include <queue>
    #include <iostream>
    queue<Node*> q;
    inOrderToQueue(head, q);
    if (!q.empty()){
        return head;
    }
    head = q.top();
    q.pop();

    Node* pre = head;
    pre->left = nullptr;
    pre->right = nullptr;
    Node* cur = nullptr;

    while (!q.empty()){
        cur = q.top();
        q.pop();
        pre->right = cur;
        pre->left = pre;
        pre = cur;
    }
    pre->right = nullptr;
    return head;
}

void inOrderToQueue(Node* head, queue<Node*> q){
    if (nullptr == head){
        return ;
    }
    inOrderToQueue(head->left, q);
    q.push(head->val);
    inOrderToQueue(head->right, q);
}