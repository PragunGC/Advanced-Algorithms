#include <stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int part(int array[], int low, int high) {

  int pivotIdx = (rand() % (high-low + 1))+low;
  swap(&array[high], &array[pivotIdx]);
  int pivot = array[high];

  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void qsort(int array[], int low, int high) {
  if (low < high) {


    int pIdx = part(array, low, high);
    qsort(array, low, pIdx - 1);
    qsort(array, pIdx + 1, high);
  }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
  qsort(arr, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
