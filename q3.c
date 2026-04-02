#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char rev[100];

    printf("Enter string: ");
    scanf("%s", text);

    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        rev[i] = text[len - i - 1];
    }
    rev[len] = '\0';

    if (strcmp(text, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
