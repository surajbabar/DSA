#include "linkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

List* createList(){
        List* list = calloc(1, sizeof(List));
        return list; 
};
void Free(List* list){
    free(list);
};
int insertNode(List* list , int index , void* data){
        int i=0;
        Node* node = calloc(1,sizeof(Node));
        if (index > list->length) return 0;
        if (index == 0){
            node->next = list->header;
            list->header = node;          
        }
        else if(index == list->length){
            Node* temp = list->header;
            while(temp->next!=NULL) temp =temp->next;
            temp->next =node;
            node->next = NULL;
        } 
        else insertMiddle(list, index, node);
        node->data = data;
        list->length++;
        return 1;
}
void insertMiddle(List* list , int index ,Node* node ){
        Node* temp;
        int i=0;
        temp = list->header;
        while(i++ < index-1) temp =temp->next ;
        node->next=temp->next;
        temp->next =node;
}
void deleteFirst(List* list){
        Node* node = list->header;
        if(list->length == 1) list->header = NULL;
        else list->header = list->header->next;
        free(node);
}
void deleteLast(List* list){
        Node *temp = list->header , *pre;
        while(temp->next!=NULL){
                pre = temp;
                temp = temp->next;
        }
        pre->next = NULL;
        free(temp);
}
void deleteMiddle(List* list , int index){
        int i=0;
        Node *temp = list->header , *node;
        while(i++ < (index - 1)) temp = temp->next ;
        node = temp->next;
        temp->next = node->next;
        free(node);
}
int deleteNode(List* list , int index){
        if(index >= list->length) return 0;
        if(index == 0) deleteFirst(list);
        else if(index == list->length-1)  deleteLast(list);
        else deleteMiddle( list , index);
        list->length--;
        return 1;
}