#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;  
    struct Node* next;  
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    
    
    if (head == NULL) {
        return newNode;
    }
    
    
    if (data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    
    
    Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
   
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    
    return head;
}

void printListForward(Node* head) {
    Node* current = head;
    printf("Parcours avant : ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void printListBackward(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    printf("Parcours arrière : ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}


void freeList(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}


int main() {
    Node* head = NULL;
    
    printf("=== LISTE DOUBLEMENT CHAINEE TRIEE ===\n\n");
    
    printf("Insertion des éléments dans l'ordre: 5, 3, 8, 1, 6\n\n");
    
  
    head = insertSorted(head, 5);
    printf("Après insertion de 5:\n");
    printListForward(head);
    printListBackward(head);
    printf("\n");
    
    head = insertSorted(head, 3);
    printf("Après insertion de 3:\n");
    printListForward(head);
    printListBackward(head);
    printf("\n");
    
    head = insertSorted(head, 8);
    printf("Après insertion de 8:\n");
    printListForward(head);
    printListBackward(head);
    printf("\n");
    
    head = insertSorted(head, 1);
    printf("Après insertion de 1:\n");
    printListForward(head);
    printListBackward(head);
    printf("\n");
    
    head = insertSorted(head, 6);
    printf("Après insertion de 6:\n");
    printListForward(head);
    printListBackward(head);
    printf("\n");
    
    
    printf("=== RESULTAT FINAL ===\n");
    printListForward(head);
    printListBackward(head);
    
    
    freeList(head);
    printf("\nMémoire libérée avec succès.\n");
    
    return 0;
}