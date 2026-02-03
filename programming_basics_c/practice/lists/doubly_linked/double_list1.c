//1.знаходить книгу з найбільшою кількістю сторінок і перемістити на початок.
//2.знайти книгу яка з найменшою кількістю сторінок і переміщає у кінець.
//3.за автором шукає і видаляє її.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book{
    char m_Name[50];
    char m_Author[50];
    int m_Year;
    int m_Pages;
};
struct Node{
    struct Book Info;
    struct Node* pPrev;
    struct Node* pNext;
};
void FindWithMostPagesAndTookToStart(struct Node** head){
    if(*head == NULL || (*head)->pNext==NULL) return;

    struct Node* cur = *head;

    int max = (*head)->Info.m_Pages;

    while(cur!=NULL){
        if(cur->Info.m_Pages>max){
            max = cur->Info.m_Pages;
        }
        cur = cur->pNext;
    }
    
    if((*head)->Info.m_Pages==max) return;

    cur = *head;

    while(cur!=NULL){
        if(cur->Info.m_Pages==max){
            cur->pPrev->pNext=cur->pNext;
            if(cur->pNext){
                cur->pNext->pPrev=cur->pPrev;
            }

            cur->pPrev=NULL;
            cur->pNext=*head;
            (*head)->pPrev=cur;
            *head = cur;
            return;
        }
        cur = cur->pNext;
    }

}
void FindWithLeastPagesAndTookToEnd(struct Node** head){
    if(*head==NULL || (*head)->pNext==NULL){
        return;
    }
    struct Node* cur = *head;
    int min = (*head)->Info.m_Pages;
    while(cur!=NULL){
        if(cur->Info.m_Pages<min){
            min = cur->Info.m_Pages;
        }
        cur = cur->pNext;
    }
    cur=*head;
    
    struct Node* last =*head;
    while(last->pNext!=NULL){
        last = last->pNext;
    }

    while(cur!=NULL){
        if(cur->Info.m_Pages==min){
            if(cur==last){
                return;
            }

            if(cur==*head){
                *head = cur->pNext;
                (*head)->pPrev=NULL;
            }
            else{
                cur->pPrev->pNext=cur->pNext;
                cur->pNext->pPrev=cur->pPrev;
            }

            last->pNext=cur;
            cur->pPrev=last;
            cur->pNext=NULL;
            return;
        }
        cur=cur->pNext;
    }    
}
void DeleteByAuthor(struct Node** head, char* author){
    if(*head==NULL) return;
    struct Node* cur = *head;

    while(cur!=NULL){
        if(strcmp(cur->Info.m_Author, author)==0){
            if(cur==*head && (*head)->pNext==NULL){
                *head = NULL;
            }
            else if(cur==*head){
                *head = cur->pNext;
                (*head)->pPrev=NULL;

            }
            else if(cur->pNext!=NULL){
                cur->pPrev->pNext=cur->pNext;
                cur->pNext->pPrev=cur->pPrev;
            }
            else{
                cur->pPrev->pNext=NULL;
            }
            free(cur);
            return;
        }

        cur=cur->pNext;
    }
}