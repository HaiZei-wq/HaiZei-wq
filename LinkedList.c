/*************************************************************************
	> File Name: LinkedList.c
	> Author: 
	> Mail: 
	> Created Time: 2018年06月06日 星期三 18时17分52秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct LinkNode {
    int data;
    struct LinkNode *next; 
} LinkNode;


typedef struct LinkList {
    LinkNode *head;
    int n;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->head = NULL;
    p->n = 0;
    return p;

}


LinkNode *getNewNode(int data) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = data;
    p->next = NULL;
    return p;
}

void clear(LinkList *l) {
    //LinkNode *current_node = head;
    LinkNode *head = l->head;
    while( head ) {
        LinkNode *next = head->next;
        free(head);
        head = next;
    }
    free(l);
    return ;
}


int insert(LinkList *l,int data, int ind) {
    LinkNode ret, *p;
    ret.next = l->head;
    p = &ret;
    if( ind < 0 || ind > l->n) return 0;
    while (p && ind--) {
        p = p->next;
    }
    LinkNode *new_node = getNewNode(data);
    new_node->next = p->next;
    p->next = new_node;
    l->head = ret.next;
    l->n += 1;
    return 1;

}


void output(LinkList *l) {
    LinkNode *head = l->head;
    while(head) {
        printf("%d ->", head->data);
        head = head->next;

    }
    printf("null\n");
}

int main() {
    LinkList *l = init();
    srand(time(0));
    for (int i = 0; i < 10 ; i++) {
        int data = rand() % 100;
        int ind = rand() % (i + 2) - 3;
        printf("%d : insert(%d, %d) = ",i, data,ind);
        fflush(stdout);
        printf("%d : ",insert(l,data,ind));
        output(l);


    }
    clear(l);
    return 0;
}
