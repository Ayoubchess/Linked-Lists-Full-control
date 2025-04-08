#ifndef LLL_H
#define LLL_H
#include <stdbool.h>

typedef struct node {
    int Data;
    struct node* next;
} Node;

bool isEmpty(Node* Head);
void Create_List(Node** Head);
void InsertElement(Node** Head, int x);
void DisplayList(Node* Head);
int Count(Node* Head);
void Remove(Node** Head, int x);
void DestroyList(Node** Head);

#endif