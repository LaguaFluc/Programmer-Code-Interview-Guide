

4、反转部分单向链表

```C++
struct ListNode {
    int value;
    ListNode* next;
}

ListNode reversePart(ListNode head, int from, int to){
    int len = 0;
    ListNode node1 = head;
    ListNode fPre = nullptr;
    ListNode tPos = nullptr;
    while (node1 != nullptr){
        ++len;
        fPre = len == from - 1 ? node1 : fPre;
        tPos = len == to + 1 ? node1 : tPos;
        node1 = node1->next;
    }

    if (from > to || to < 1 || from > len){
        return head;
    }

    node1 = fPre == nullptr ? head : fPre->next;
    ListNode node2 = node1->next;
    node1->next = toPos;
    ListNode next = null;
    while (node2 != toPos){
        next = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = next;
    }

    if (fPre != nullptr){
        fPre->next = node1;
        return head;
    }
    return node1;
}
```