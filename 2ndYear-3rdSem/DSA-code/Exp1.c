#include <stdio.h>

void read_array(int *p, int size);
void display_array(int *p, int size);
void mid_element(int *p, int size);
void reverse_array(int *p, int size);
int sum_array(int *p, int size);

int main() {
    int option;
    int size;
    int p[100];
    printf("Enter the number of elements for the array : ");
    scanf("%d", &size);

    do {
        printf("\nMenu Operation:\n");
        printf("Press 1 - Read Array\n");
        printf("Press 2 - Display Array using pointers\n");
        printf("Press 3 - Find middle element of an Array using pointers\n");
        printf("Press 4 - Reverse the array using pointers\n");
        printf("Press 5 - Sum of elements of an array\n");
        printf("Press 6 - Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                read_array(p, size); // Function call for reading an array
                break;
            case 2:
                display_array(p, size); // Function call for displaying the array
                break;
            case 3:
                mid_element(p, size); // Function call for finding the middle element
                break;
            case 4:
                reverse_array(p, size); // Function call for reversing the array
                break;
            case 5:
                printf("Sum of elements: %d\n", sum_array(p, size)); // Function call for summing the array
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while(option != 6);

    return 0;
}

void read_array(int *p, int size) {
    int i;
    printf("Enter %d elements for the array:\n", size);
    for(i = 0; i < size; i++) {
        printf("Enter a number: ");
        scanf("%d", &p[i]);  // Storing values in the array
    }
}

void display_array(int *p, int size) {
    int i;
    printf("The array values are: ");
    for(i = 0; i < size; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void mid_element(int *p, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else if (size % 2 == 0) {
        printf("The middle elements are: %d and %d\n", p[size/2 - 1], p[size/2]);
    } else {
        printf("The middle element is: %d\n", p[size/2]);
    }
}

void reverse_array(int *p, int size) {
    int i;
    printf("The reversed array is: ");
    for(i = size - 1; i >= 0; i--) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int sum_array(int *p, int size) {
    int i, sum = 0;
    for(i = 0; i < size; i++) {
        sum += p[i];
    }
    return sum;
}
