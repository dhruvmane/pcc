#include <stdio.h>

#define MAX_SIZE 100

void insertAtPosition(int arr[], int *size) {
    int element, position;
    printf("Enter Element and Position: ");
    scanf("%d %d", &element, &position);

    if (*size >= MAX_SIZE) {
        // if Array is Full or Overflowing.
        printf("Error: Array is Full.\n");
        return;
    }

    if (position > MAX_SIZE) {
        // if trying to insert at a farther position.
        printf("Error: Cannot insert at a position out of limit.\n");
        return;
    }

    for (int i = *size; i >= position; i--) {
        // Shift every element after the inserted element one element ahead..
        // initial = [1, 2, 3, 4, 5]
        // final = [1, 2, .., 3, 4, 5]
        arr[i] = arr[i-1];
    }
    
    arr[position - 1] = element;
    (*size)++; // increment size variable to keep track of total number of elements in array.

    printf("Status: Element successfully inserted.\n");

}

void displayArray(int arr[], int size) {
    
    if (size == 0) {
        printf("Error: Array is Empty.");
        return;
    }


    printf("Elements of the Array are: \n");
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d,", arr[i]);
    }
    printf("]");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element = 1, position = 1;
    

    while(1) {
        printf("\nMenu\n");
        printf("1. Insert Element\n");
        printf("2. Display Element\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /* code */
            insertAtPosition(arr, &size);
            break;
        
        case 2:
            displayArray(arr, size);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

    }

    return 0;
}
