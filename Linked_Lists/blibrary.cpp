#include <stdio.h>
#include <stdlib.h>
#include "blibrary.h"

void print(node * r){
        while(r!=NULL){
                printf("%d ",r->x);
                r= r->next;
        }
        printf("\n");
}
void add(node *r, int x){
        while(r->next!=NULL){
                r = r->next;
        }
        r->next = (node*)malloc(sizeof(node));
        r->next->x = x;
        r->next->next = NULL;
}
node * addInOrder(node * r,int x){
        if(r==NULL){ // if the linked list is empty
                r=(node *)malloc(sizeof(node));
                r->next = NULL;
               r->x = x;
                return r;
        }
        if(r->x > x){ // smaller than the first element situation
                        // root is changing
                        node * temp = (node*)malloc(sizeof(node));
                        temp -> x = x;
                        temp -> next =r;
                        return temp;
        }
        node * iter = r;
        while(iter->next != NULL && iter->next->x < x){
                iter= iter->next;
        }
        node * temp = (node*)malloc(sizeof(node));
        temp->next = iter -> next;
        iter -> next = temp;
        temp -> x = x;
        return r;
}
node * remove(node *r,int x){
        node *temp;
        node *iter = r;
        if(r->x == x){
                temp = r;
                r = r->next;
                free(temp);
                return r;
        }
        while (iter->next != NULL && iter->next->x != x){
                iter = iter ->next;
        }
        if(iter->next == NULL){
                printf("number not found.");
                return r;
        }
        temp = iter->next;
        iter->next = iter->next->next;
        free (temp);
        return r;
}

