#include <stdio.h>
#include <string.h>
int main() {
    char inputString[100];  
    scanf("%[^\n]", inputString);
    printf("Hello, World!\n");
    printf("%s", inputString);
    return 0;
}
