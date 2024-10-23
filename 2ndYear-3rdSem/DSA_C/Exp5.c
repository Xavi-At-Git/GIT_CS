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

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;

NODE *createNode(int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

NODE *add(NODE *head, int item)
{
    NODE *newNode = createNode(item);

    if (head == NULL || head->data >= item)
    {
        newNode->next = head;
        return newNode;
    }

    NODE *current = head;
    while (current->next != NULL && current->next->data < item)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void disp(NODE *head)
{
    if (head == NULL)
    {
        printf("Warehouse is empty.\n");
        return;
    }

    printf("Current Warehouse Inventory: ");
    NODE *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(NODE *head, int item)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

NODE *delete_item(NODE *head, int item)
{
    if (head == NULL)
    {
        printf("Warehouse is empty, nothing to delete.\n");
        return head;
    }

    if (head->data == item)
    {
        NODE *temp = head;
        head = head->next;
        free(temp);
        printf("Item %d deleted from the warehouse.\n", item);
        return head;
    }

    NODE *current = head;
    while (current->next != NULL && current->next->data != item)
    {
        current = current->next;
    }

    if (current->next != NULL)
    {
        NODE *temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("Item %d deleted from the warehouse.\n", item);
    }
    else
    {
        printf("Item %d not found in the warehouse.\n", item);
    }

    return head;
}

int main()
{
    NODE *head = NULL;
    int opt, item;

    while (1)
    {
        printf("\n1: Add item    2: Display Warehouse    3: Search item    4: Delete item    5: Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter item to add to warehouse: ");
            scanf("%d", &item);
            head = add(head, item);
            break;

        case 2:
            disp(head);
            break;

        case 3:
            printf("Enter the item to search: ");
            scanf("%d", &item);
            if (search(head, item))
                printf("Item %d is present in the warehouse.\n", item);
            else
                printf("Item %d is NOT present in the warehouse.\n", item);
            break;

        case 4:
            printf("Enter the item to delete: ");
            scanf("%d", &item);
            head = delete_item(head, item);
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong option! Please try again.\n");
        }
    }

    return 0;
}
