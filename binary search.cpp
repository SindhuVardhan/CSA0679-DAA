#include <stdio.h>

// function to perform binary search
int binary_search(int arr[], int n, int key) {
   int low = 0, high = n - 1;

   while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] == key) {  // if the middle element is the key, we've found it
         return mid;
      } else if (arr[mid] < key) {  // if the middle element is less than the key, search the right half
         low = mid + 1;
      } else {  // if the middle element is greater than the key, search the left half
         high = mid - 1;
      }
   }

   return -1;  // key not found
}

int main() {
   int arr[] = {1, 3, 5, 7, 9, 11, 13};
   int n = sizeof(arr) / sizeof(arr[0]);
   int key;

   printf("Enter a key to search for: ");
   scanf("%d", &key);

   int result = binary_search(arr, n, key);

   if (result == -1) {
      printf("Key not found\n");
   } else {
      printf("Key found at index %d\n", result);
   }

   return 0;
}
