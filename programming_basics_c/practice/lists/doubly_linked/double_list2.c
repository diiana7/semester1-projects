//додавання елемент на початок і кінець двозв'язного списку
//роздрукувати в обох напрямках
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int m_Data;
    struct Node* pNext;
    struct Node* pPrev; 
};
void AddNodeToStart(struct Node** head, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->m_Data=data;
    new_node->pPrev=NULL;
    new_node->pNext=*head;

    if(*head != NULL){
        (*head)->pPrev= new_node;
    }
    *head = new_node;
}
void AddNodeToEnd(struct Node** head, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->m_Data=data;
    new_node->pNext=NULL;
    if(*head == NULL){
        new_node->pPrev=NULL;
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while(temp->pNext != NULL){
        temp = temp->pNext;
    }
    temp->pNext= new_node;
    new_node->pPrev=temp;
}
void PrintList(struct Node* head){
    while(head != NULL){
        printf("%d -> ", head->m_Data);
        if(head->pNext == NULL) break;
        head = head->pNext;
    }
    printf("NULL\n");
}
void ReverseList(struct Node* tail){ //tail - останній елемент списку
    while(tail != NULL){
        printf("%d -> ", tail->m_Data);
        tail = tail->pPrev;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head = NULL;

    AddNodeToStart(&head, 20);
    AddNodeToStart(&head, 10);
    AddNodeToEnd(&head, 30);
    AddNodeToEnd(&head, 40);

    printf("Forward: ");
    PrintList(head);

    // знайдемо tail
    struct Node* tail = head;
    while (tail != NULL && tail->pNext != NULL) {
        tail = tail->pNext;
    }

    printf("Backward: ");
    ReverseList(tail);

    return 0;
}