#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head;

void Display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("Linked list is Empty...\n");
        return;
    }

    printf("Linked list elements are: ");
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void InsertFront(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->link = head;
    head = newNode;
}

void InsertEnd(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = newNode;
}

void InsertAfter(int key, int x) {
    struct node *newNode, *ptr = head;
    while (ptr != NULL && ptr->data != key)
        ptr = ptr->link;

        if (ptr == NULL) {
        printf("Search key not found. Insertion is not possible.\n");
        return;
        }

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->link = ptr->link;
    ptr->link = newNode;
}

void DeleteFront() {
    if (head == NULL) {
        printf("List is Empty. Deletion not possible.\n");
        return;
    }

    struct node *temp = head;
    head = head->link;
    free(temp);
}

void DeleteEnd() {
    if (head == NULL) {
        printf("List is Empty. Deletion not possible.\n");
        return;
    }

    struct node *prev = NULL, *curr = head;
    while (curr->link != NULL) {
        prev = curr;
        curr = curr->link;
    }

    if (prev == NULL)
        head = NULL;
    else
        prev->link = NULL;

    free(curr);
}

void DeleteAny(int key) {
    if (head == NULL) {
        printf("List is Empty. Deletion not possible.\n");
        return;
    }

    struct node *prev = NULL, *curr = head;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == NULL) {
        printf("Search data not found. Deletion is not possible.\n");
        return;
    }

    if (prev == NULL)
        head = curr->link;
    else
        prev->link = curr->link;

    free(curr);
}

int main() {
    int opt, x, key;

    do {
        printf("\nEnter the option:\n");
        printf("1. Insert at Front\n2. Insert at End\n3. Insert After\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete Any\n7. Display\n8. Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the new data: ");
                scanf("%d", &x);
                InsertFront(x);
                break;

            case 2:
                printf("Enter the new data: ");
                scanf("%d", &x);
                InsertEnd(x);
                break;

            case 3:
                printf("Enter the search key: ");
                scanf("%d", &key);
                printf("Enter the new data: ");
                scanf("%d", &x);
                InsertAfter(key, x);
                break;

            case 4:
                DeleteFront();
                break;

            case 5:
                DeleteEnd();
                break;

            case 6:
                printf("Enter the node to be deleted: ");
                scanf("%d", &key);
                DeleteAny(key);
                break;

            case 7:
                Display();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option. Please enter a valid option.\n");
        }
    } while (opt != 8);

    return 0;
}

