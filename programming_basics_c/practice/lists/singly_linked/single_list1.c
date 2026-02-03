// 1.функція приймає список і число знаходить першого студ з сер менш ніж то число і видаляє
// 2.ф-я шукає студ за ПІБ і переміщає у кінець
// 3.ф-я шукає студ за ПІБ і видаляє
// 4.ф-я знаходить першого студ з сер менш ніж то число і переміщає у кінець
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student
{
    char m_PIB[100];
    char m_Group[20];
    float m_avr;
};
struct Node
{
    struct Student Info;
    struct Node *pNext;
};
void DeleteStudentBelowAvr(struct Node **head, float num)
{
    if (*head == NULL)
        return;
    if ((*head)->Info.m_avr < num)
    {
        struct Node *temp = *head;
        *head = (*head)->pNext;
        free(temp);
        return;
    }
    struct Node *current = (*head)->pNext;
    struct Node *curPrev = *head;
    while (current != NULL)
    {
        if (current->Info.m_avr < num)
        {
            curPrev->pNext = current->pNext;
            free(current);
            return;
        }
        curPrev = current;
        current = current->pNext;
    }
    return;
}

void TakeStundentToEnd(struct Node **head, char *PIB)
{
    if (*head == NULL || (*head)->pNext == NULL)
        return;

    struct Node *current = *head;
    struct Node *curPrev = NULL;
    struct Node *last = *head;

    while (last->pNext != NULL)
    {
        last = last->pNext;
    }

    while (current != NULL)
    {
        if (strcmp(current->Info.m_PIB, PIB) == 0)
        {
            if (current == last)
                return;
            if (curPrev == NULL)
            {
                *head = current->pNext;
            }
            else
            {
                curPrev->pNext = current->pNext;
            }

            last->pNext = current;
            current->pNext = NULL;
            return;
        }
        curPrev = current;
        current = current->pNext;
    }
}
void DeleteStudent(struct Node** head, char *PIB){
    if(*head==NULL) return;

    if(strcmp((*head)->Info.m_PIB, PIB)==0){
        struct Node* temp =*head;
        *head=(*head)->pNext;
        free(temp);
        return;
    }
    struct Node* current = (*head)->pNext;
    struct Node* curPrev = *head;

    while(current != NULL){
        if(strcmp(current->Info.m_PIB, PIB)==0){
            curPrev->pNext = current->pNext;
            free(current);
            return;
        }
        curPrev = current;
        current = current->pNext;
    }
}
void StudWithLowerAvrTakeToEnd(struct Node** head, int num){
    if(*head==NULL || (*head)->pNext==NULL) return;

    struct Node* current = *head;
    struct Node* curPrev = NULL;
    struct Node* last = *head;

    while(last->pNext!=NULL){
        last = last->pNext;
    }

    while(current!=NULL){
        if(current->Info.m_avr<num){
            if(current==last) return;
            if(curPrev==NULL){
                *head = current->pNext;
            }
            else{
                curPrev->pNext = current->pNext;
            }
            last->pNext=current;
            current->pNext=NULL;
            return;
        }

        curPrev=current;
        current=current->pNext;
    }
}