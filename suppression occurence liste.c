#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAllOccurrences(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;
    Node* toDelete;

    
    while (current != NULL && current->data == value) {
        toDelete = current;
        *head = current->next;
        current = *head;
        free(toDelete);
    }

    
    while (current != NULL) {
        if (current->data == value) {
            toDelete = current;
            prev->next = current->next;
            current = current->next;
            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* head = NULL;

    
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 4);

    printf("Liste originale:\n");
    displayList(head);

    
    deleteAllOccurrences(&head, 2);
    printf("\nAprès suppression des 2:\n");
    displayList(head);

    return 0;
}