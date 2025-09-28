#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);
    
 
    if (head == NULL || data < head->data) {
        newNode->next = head;
        return newNode;
    }
    
    
    Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
  
    newNode->next = current->next;
    current->next = newNode;
    
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
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
    
    
    head = insertSorted(head, 5);
    head = insertSorted(head, 3);
    head = insertSorted(head, 8);
    head = insertSorted(head, 1);
    head = insertSorted(head, 6);
    
    printf("Liste triée : ");
    printList(head);
    
   
    freeList(head);
    
    return 0;
}
