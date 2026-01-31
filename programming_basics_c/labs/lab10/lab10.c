/*Виконати завдання з лабораторної роботи № 9, організувавши послідовність структур 
в однозв’язний список. Реалізувати операцію вставки нового елемента у відсортований 
список і операцію вилучення зі списку даних, які відповідають одній з наступних умов: 
про студентів з двома оцінками 2;*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char surname[50];
    char name[50];
    char birth[12];
    int marks[4];
    double average;
} Student;

typedef struct Node {
    Student data; 
    struct Node *next; 
} Node;

Node* createNode(Student st) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = st; // копія даних студента у вузол
    newNode->next = NULL;
    return newNode;
}

void insertSorted(Node **head, Student st) { 
    Node *newNode = createNode(st);
    if (*head == NULL || st.average < (*head)->data.average) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *cur = *head;
    while (cur->next != NULL && cur->next->data.average < st.average) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

int hasTwoTwos(Student st) {
    int count = 0;
    for (int i = 0; i < 4; i++)
        if (st.marks[i] == 2) count++;
    return count >= 2;
}

void deleteTwoTwos(Node **head) {
    while (*head && hasTwoTwos((*head)->data)) {
        Node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    Node *cur = *head;
    if (!cur) return;

    while (cur->next) {
        if (hasTwoTwos(cur->next->data)) {
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
}

void printList(Node *head) {
    printf("===========================================================\n");
    printf("| %-10s | %-10s | %-12s | %-8s |\n",
           "Lastname", "Name", "Birthdate", "Rating");
    printf("===========================================================\n");

    while (head) {
        printf("| %-10s | %-10s | %-12s | %-8.2f |\n",
               head->data.surname,
               head->data.name,
               head->data.birth,
               head->data.average);
        head = head->next;
    }

    printf("===========================================================\n");
}

int main() {
    FILE *fp = fopen("students.txt", "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    Node *head = NULL;
    Student st;

    while (fscanf(fp, "%s %s %s %d %d %d %d",
                  st.surname, st.name, st.birth,
                  &st.marks[0], &st.marks[1], &st.marks[2], &st.marks[3]) == 7)
    {
        st.average = (st.marks[0] + st.marks[1] + st.marks[2] + st.marks[3]) / 4.0;
        insertSorted(&head, st);
    }

    fclose(fp);

    printf("\n    SORTED LIST OF STUDENTS    \n");
    printList(head);

    deleteTwoTwos(&head);

    printf("\n    LIST AFTER REMOVING STUDENTS WITH TWO MARKS “2”    \n");
    printList(head);
    return 0;
}
