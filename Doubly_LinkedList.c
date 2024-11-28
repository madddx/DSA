#include<stdio.h>
#include<stdlib.h>

struct dnode {
    int data;
    struct dnode* next;
    struct dnode* prev;
};
typedef struct dnode node;
node* head = NULL;

void insertatbeginning(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertatposition(int pos, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    node* temp = head;

    if (pos == 0) {
        insertatbeginning(val);
        return;
    }

    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Out of Bound\n");
            return;
        }
    }

    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertatend(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

void display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    node* temp = head;
    printf("The elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deletefrombeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Deleted the first element.\n");
}

void deletefromend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted the last element.\n");
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted the last element.\n");
}

void deletefrompos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 0) {
        deletefrombeginning();
        return;
    }

    node* temp = head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Out of Bound\n");
            return;
        }
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Deleted the element at position %d.\n", pos);
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\nOperations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at any position (starts from 0)\n");
        printf("3. Insert at the end\n");
        printf("4. Display\n");
        printf("5. Delete at the beginning\n");
        printf("6. Delete at any position (starts from 0)\n");
        printf("7. Delete at the end\n");
        printf("8. Exit\n");
        printf("Enter a choice (1-8):\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            insertatbeginning(val);
            break;

        case 2:
            printf("Enter the position to insert (starts from 0): \n");
            scanf("%d", &pos);
            if (pos < 0) {
                printf("Invalid position\n");
                break;
            }
            printf("Enter the value: ");
            scanf("%d", &val);
            insertatposition(pos, val);
            break;

        case 3:
            printf("Enter the value: ");
            scanf("%d", &val);
            insertatend(val);
            break;

        case 4:
            display();
            break;

        case 5:
            deletefrombeginning();
            break;

        case 6:
            printf("Enter the position to delete: \n");
            scanf("%d", &pos);
            if (pos < 0) {
                printf("Invalid position\n");
                break;
            }
            deletefrompos(pos);
            break;

        case 7:
            deletefromend();
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Enter a valid option\n");
        }
    }
}
