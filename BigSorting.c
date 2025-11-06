#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *x = *(char **)a;
    char *y = *(char **)b;

    int len_x = strlen(x);
    int len_y = strlen(y);

    if (len_x != len_y) {
        return len_x - len_y;   
    }

    return strcmp(x, y);        
}

int main() {
    int n;
    scanf("%d", &n);

    char **arr = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(10005);   
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), compare);

    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);

    return 0;
}
