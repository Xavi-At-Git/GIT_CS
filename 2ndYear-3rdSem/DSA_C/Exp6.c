#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct Node {
    int id;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
Node* createInventory();
void addItemAtStart(Node** head, int id);
void addItemAtEnd(Node** head, int id);
void displayInventory(Node* head);
Node* searchForward(Node* head, int id);
Node* searchBackward(Node* tail, int id);
void freeInventory(Node* head);

// Function to create an inventory (returns the head node)
Node* createInventory() {
    return NULL; // Initially, the inventory is empty
}

// Function to add an item at the start of the list
void addItemAtStart(Node** head, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Function to add a new item at the end of the list
void addItemAtEnd(Node** head, int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to display the inventory
void displayInventory(Node* head) {
    if (head == NULL) {
        printf("Inventory is empty.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("Item ID: %d\n", current->id);
        current = current->next;
    }
}

// Function to search for an item in the list from head to tail
Node* searchForward(Node* head, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for an item in the list from tail to head
Node* searchBackward(Node* tail, int id) {
    Node* current = tail;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->prev;
    }
    return NULL;
}

// Function to free memory allocated for the inventory
void freeInventory(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    Node* inventory = createInventory();
    int choice, id;
    Node* found;

    do {
        printf("\n1. Create a doubly linked list and insert at front\n");
        printf("2. Insert a new node at the end\n");
        printf("3. Display the list\n");
        printf("4. Search in the list (forward)\n");
        printf("5. Search in the list (backward)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID to add at the start: ");
                scanf("%d", &id);
                addItemAtStart(&inventory, id);
                break;
            case 2:
                printf("Enter item ID to add at the end: ");
                scanf("%d", &id);
                addItemAtEnd(&inventory, id);
                break;
            case 3:
                displayInventory(inventory);
                break;
            case 4:
                printf("Enter item ID to search forward: ");
                scanf("%d", &id);
                found = searchForward(inventory, id);
                if (found != NULL) {
                    printf("Item with ID %d found.\n", found->id);
                } else {
                    printf("Item not found.\n");
                }
                break;
            case 5:
                if (inventory == NULL) {
                    printf("Inventory is empty.\n");
                    break;
                }

                // Find the last node (tail)
                Node* tail = inventory;
                while (tail->next != NULL) {
                    tail = tail->next;
                }

                printf("Enter item ID to search backward: ");
                scanf("%d", &id);
                found = searchBackward(tail, id);
                if (found != NULL) {
                    printf("Item with ID %d found.\n", found->id);
                } else {
                    printf("Item not found.\n");
                }
                break;
            case 6:
                printf("Exiting program...\n");
                freeInventory(inventory);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
