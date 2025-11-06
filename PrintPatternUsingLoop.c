#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            int rowDist = i < size - i ? i : size - 1 - i;
            int colDist = j < size - j ? j : size - 1 - j;

            int minDist = rowDist < colDist ? rowDist : colDist;

            printf("%d ", n - minDist);
        }
        printf("\n");
    }

    return 0;
}
