#include <stdio.h>

void insertionSort1(int n, int arr[]) {
    int value = arr[n-1];  
    int i = n - 2;

    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];  // shift
        for (int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
        i--;
    }

    arr[i + 1] = value;  

    for (int k = 0; k < n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertionSort1(n, arr);
    return 0;
}
