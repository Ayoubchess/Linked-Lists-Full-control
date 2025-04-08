#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int Data;
    struct node* next;
} Node;

bool isEmpty(Node* Head) {
    return (Head == NULL);
}

void Create_List(Node** Head) { // we need to take the double pointer
    *Head = NULL;  
    char resp;
    int x;
    Node* p;
    Node* q;

    do {
        printf("Enter a value: ");
        scanf("%d", &x);

        p = (Node*)malloc(sizeof(Node));
        if (p == NULL) {
            printf("Memory allocation failed!\n");
            return ;
        }
        p->Data = x;
        p->next = NULL;

        if (*Head == NULL) {
            *Head = p;  
        } else {
            q = *Head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;  
        }

        printf("Add another value? (y/n): ");
        scanf(" %c", &resp);  
    } while (resp == 'y' || resp == 'Y');
}

void InsertElement(Node** Head, int x) {
    int ch, pos, k;
    Node* p;
    Node* q;
    
    do {
        printf("Where to insert? (1=beginning, 2=end, 3=position): ");
        scanf("%d", &ch);
    } while(ch < 1 || ch > 3);

    // Create new node
    p = (Node*)malloc(sizeof(Node));
    if(p == NULL) {
        printf("Memory allocation failed\n");
        return;  // no return value for void function
    }
    p->Data = x;
    p->next = NULL;

    switch(ch) {
        case 1: // Insert at beginning
            p->next = *Head;
            *Head = p;
            break;
            
        case 2: // Insert at end
            if(*Head == NULL) {
                *Head = p;
            } else {
                q = *Head;  
                while(q->next != NULL) {
                    q = q->next;
                }
                q->next = p;
            }
            break;
            
        case 3: // Insert at position
            printf("Enter position (>=1): ");
            scanf("%d", &pos);
            
            if(pos < 1) {
                printf("Invalid position\n");
                free(p);
                return;
            }
            
            if(pos == 1) {
                p->next = *Head;
                *Head = p;
            } else {
                q = *Head;  
                k = 1;
                while(q != NULL && k < pos-1) {
                    q = q->next;
                    k++;
                }
                
                if(q == NULL) {
                    printf("Position too large\n");
                    free(p);
                } else {
                    p->next = q->next;
                    q->next = p;
                }
            }
            break;
    }
}

void DisplayList(Node* Head) {
    Node* current = Head;
    
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("List contents: ");
    while (current != NULL) {
        printf("%d", current->Data);  // Print the actual data, not the address
        current = current->next;
        if (current != NULL) {
            printf(" -> ");  // Only print arrow if there's another node
        }
    }
    printf("\n");
}

int Count(Node* Head){
    Node* p = Head ;
    int i = 0 ;
    while(p != NULL){
    i++ ; 
    p = p->next ;
    }
    return i ;
}

void Remove(Node** Head , int x){
    Node* p ;
    Node* temp ; 
        
        if(isEmpty(*Head)) {
        printf("The List is empty!!\n");
        return;
        }
        if((*Head)->Data == x){
            temp = *Head ;
            *Head = (*Head)->next ;
            free(temp);
            return ;
        }
        p = *Head;
        while(p->next != NULL) {
            if(p->next->Data == x) {
                temp = p->next;
                p->next = temp->next;
                free(temp);
                return;
            }
            p = p->next;
        }
        printf("The element with the value %d is not found in the list\n", x);
        
    }

void DestroyList(Node** Head){
    Node* p ;
    while(isEmpty(*Head) == false ){
        p = *Head ;
        *Head = (*Head)->next ;
        free(p);
    }
} 