//Створити список і додати вузол у кінець і на початок. 
//пошук елемента і його видалення(за значенням)
//розвернути список
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int m_Data;
    struct Node *mNext;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->m_Data= data;
    newNode->mNext= NULL;
    return newNode;
}
void deleteNode(struct Node **head, int data){
    struct Node *temp = *head;
    struct Node *prv = NULL;
    if(temp!=NULL && temp->m_Data==data){
        *head = temp->mNext;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->m_Data!=data){
        prv = temp;
        temp = temp->mNext;
    }
    if(temp==NULL){
        printf("Element is not found\n");
        return;
    }
    prv->mNext = temp->mNext;
    free(temp);
}
void AddToStart (struct Node **head, int data){
    struct Node* firstNode = createNode(data);
    firstNode->mNext= *head;
    *head = firstNode;
}
void AddToEnd (struct Node **head, int data){
    struct Node* lastNode = createNode(data);
    if(*head == NULL){
        *head = lastNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->mNext != NULL){
        temp = temp->mNext;
    }
    temp->mNext=lastNode;

}
void printList(struct Node *head){
    while(head != NULL){
        printf("%d -> ", head->m_Data);
        head = head->mNext;
    }
    printf("NULL\n");
}
void reverseList(struct Node **head){
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while(current != NULL){
        next = current->mNext;   
        current->mNext = prev; 
        prev = current;        
        current = next;         
    }
    *head = prev;
}
int main(){
    struct Node* head=NULL;
    AddToEnd(&head, 10);
    AddToEnd(&head, 20);
    AddToStart(&head, 30);
    AddToStart(&head, 40);

    printList(head);
    reverseList(&head);

    deleteNode(&head, 30);
    printList(head);
    reverseList(&head);

    return 0;
}