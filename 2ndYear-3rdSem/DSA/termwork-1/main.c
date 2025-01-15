#include <stdio.h>

void read_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void display_array(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mid_element(int *arr, int size) {
    if (size % 2 == 0) {
        int mid1 = size / 2 - 1;
        int mid2 = size / 2;
        printf("Mid elements are: %d & %d\n", arr[mid1], arr[mid2]);
    } else {
        int mid = size / 2;
        printf("Mid element is: %d\n", arr[mid]);
    }
}

void reverse_array(int *arr, int size) {
    printf("Reversed Array: ");
    for (int i = size - 1; i >= 0; i--) { 
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int *arr, int size) {
    int sum =0; 
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of Array: ");
    read_array(arr, n);

    int option, arrsum = 0;
    do {
        printf("\nMenu Operation:\n");
        printf("1 - Display Array\n");
        printf("2 - Mid Element\n");
        printf("3 - Reverse Array\n");
        printf("4 - Sum of Array elements\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                display_array(arr, n);
                break;
            case 2:
                mid_element(arr, n);
                break;
            case 3:
                reverse_array(arr, n);
                break;
            case 4:
                arrsum = sum_array(arr, n);
                printf("Sum of all Array elements is: %d\n", arrsum);
                break;
            case 5:
                printf("Exiting Program.\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (option != 5);
    return 0;
}