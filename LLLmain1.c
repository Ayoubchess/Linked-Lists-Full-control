#include "LLL.h"
#include <stdio.h>

int main() {
    Node* Head = NULL;
    int choice, value, position;
    
    printf("Linked List Operations:\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert Element\n");
        printf("3. Display List\n");
        printf("4. Count Elements\n");
        printf("5. Remove Element\n");
        printf("6. Destroy List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                DestroyList(&Head); // Clear existing list first
                Create_List(&Head);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                InsertElement(&Head, value);
                break;
            case 3:
                DisplayList(Head);
                break;
            case 4:
                printf("Number of elements: %d\n", Count(Head));
                break;
            case 5:
                printf("Enter value to remove: ");
                scanf("%d", &value);
                Remove(&Head, value);
                break;
            case 6:
                DestroyList(&Head);
                printf("List destroyed\n");
                break;
            case 0:
                DestroyList(&Head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);
    
    return 0;
}