#include <stdio.h>

#define MAX_SIZE 100

void insertNumber(int list[], int* size, int number, int position) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot insert number.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot insert number.\n");
        return;
    }

    // Shift elements to the right from the given position
    for (int i = *size - 1; i >= position; i--) {
        list[i + 1] = list[i];
    }

    // Insert the number at the given position
    list[position] = number;

    // Increment the size of the list
    (*size)++;
}

void printList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0;

    printf("Enter the size of the list (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the numbers in the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    int number, position;
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    printf("Enter the position to insert the number (0 to %d): ", size);
    scanf("%d", &position);

    insertNumber(list, &size, number, position);

    printf("Number %d inserted at position %d.\n", number, position);
    printList(list, size);

    return 0;
}
