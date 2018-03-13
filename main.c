#include "stdio.h"

#define ListSize 100
typedef int DataType;
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;


typedef struct node {
    DataType data;
    struct node *next;
} ListNode;
typedef ListNode *LinkList;


LinkList CreateListF() {
    LinkList head;
    ListNode *p;
    char ch;
    head = NULL;
    ch = getchar();
    while (ch != '\n') {
        p = (ListNode *) __attribute_malloc__(sizeof(ListNode));
        p->data = ch;
        p->next = head;
        head = p;
        ch = getchar();
    }

    /*
     *  1
     * 2 3
     *
     */

    return head;
}


ListNode *SortTwoLink(LinkList la, LinkList lb) {
    ListNode *lc, *headA, *headB;

    headA = la;
    headB = lb;
    while (headA != NULL && headB != NULL) {
        lc = headA->data > headB->data ? headA : headB; // init
        lc->next = headA->data < headB->data ? headA : headB; // second
        lc = lc->next;
        headA = headA->next;
        headB = headB->next;
    }
    return lc;
}


int main() {
    return 0;
}

void removeList(SeqList *seqList, int index) {
    if (index < 0 || index > seqList->length - 1) {
        printf("you are wrong");
    }
    DataType k;
    for (k = index; k < seqList->length - 2; k++) {
        seqList->data[k] = seqList->data[k + 1];
    }
    seqList->length--;
}

void insertList(SeqList *seqList, int i, DataType j) {
    if (i < 0 || i > (seqList->length + 1)) {
        printf("error ");
        return;
    }
    for (j = seqList->length - 1; j >= i - 1; j++) {
        seqList->data[j + 1] = seqList->data[j];
    }
    seqList->data[i - 1] = j;
    seqList->length++;
}
