#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert a node at the end
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted into the list.\n", value);
}

// Delete a node by value
void delete(int value) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("%d deleted from the list.\n", value);
}

// Display the linked list
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n=== Linked List Menu ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Check if input is a number
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Try again.\n");
                    break;
                }
                insert(value);
                break;

            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Try again.\n");
                    break;
                }
                delete(value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter 1–4.\n");
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}
