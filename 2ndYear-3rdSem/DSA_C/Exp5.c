/*
    Problem Statement
A company uses a warehouse to store items, and they need an automated system to manage and maintain the inventory. The warehouse stores different types of items, each represented by an integer (e.g., product IDs). The company wants to implement an efficient inventory management system that allows the warehouse staff to perform the following operations:
1.	Add Items to the Warehouse:
The staff should be able to add new items to the warehouse. Since the inventory is organized, the items should be stored in a sorted order. Each new item must be inserted at the correct position in the warehouse list to maintain the sorted sequence. This helps in efficient searching and retrieval.
2.	Display the Current Inventory:
The system should allow the staff to view all the items currently stored in the warehouse in ascending order. This gives the staff a clear overview of the inventory.
3.	Search for Items:
The staff should be able to search for a specific item in the warehouse to check whether it is available. The system should perform this search efficiently, considering that the items are stored in a sorted order.
4.	Delete the item: If the product is out of stock then delete the details of the product from the system.
5.	Exit the System: The system should provide an option to exit once the necessary operations are completed.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *next;
} Node;

// Function Prototypes
Node *insertItem(Node *head, int id);
void displayItems(Node *head);
Node *searchItem(Node *head, int id);
Node *deleteItem(Node *head, int id);

int main()
{
    Node *head = NULL;
    int choice, id;

    while (1)
    {
        printf("\nWarehouse Inventory System:\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Search for Item\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n"); 
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the item ID to add: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
            head = insertItem(head, id);
            break;
        case 2:
            displayItems(head);
            break;
        case 3:
            printf("Enter the item ID to search for: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
            if (searchItem(head, id) != NULL)
            {
                printf("Item with ID %d is available.\n", id);
            }
            else
            {
                printf("Item with ID %d is not available.\n", id);
            }
            break;
        case 4:
            printf("Enter the item ID to delete: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
            head = deleteItem(head, id);
            break;
        case 5:
            printf("Exiting the system.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to insert an item in sorted order
Node *insertItem(Node *head, int id)
{
    Node *newItem = (Node *)malloc(sizeof(Node));
    if (newItem == NULL)
    {
        printf("Memory allocation failed. Item not added.\n");
        return head;
    }
    newItem->id = id;
    newItem->next = NULL;

    if (head == NULL || head->id >= id)
    {
        newItem->next = head;
        return newItem;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL && current->next->id < id)
        {
            current = current->next;
        }
        newItem->next = current->next;
        current->next = newItem;
        return head;
    }
}

// Function to display all items in the warehouse
void displayItems(Node *head)
{
    if (head == NULL)
    {
        printf("The warehouse is empty.\n");
        return;
    }

    Node *current = head;
    printf("Current Inventory:\n");
    while (current != NULL)
    {
        printf("Item ID: %d\n", current->id);
        current = current->next;
    }
}

// Function to search for an item
Node *searchItem(Node *head, int id)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete an item
Node *deleteItem(Node *head, int id)
{
    if (head == NULL)
    {
        printf("The warehouse is empty.\n");
        return head;
    }

    if (head->id == id)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Item with ID %d deleted.\n", id);
        return head;
    }

    Node *current = head;
    while (current->next != NULL && current->next->id != id)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Item with ID %d not found.\n", id);
    }
    else
    {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Item with ID %d deleted.\n", id);
    }

    return head;
}
