#include <stdio.h>

int main() {
    int num;
    char str[18];

    printf("Enter a number and a string: ");
    scanf("%d %s", &num, str);
    printf("You entered: %d & %s\n", num, str);

    char formattedString[50];
    sprintf(formattedString, "The number is %d and the string is %s", num, str);

    int new_num;
    char new_str[18];
    sscanf(formattedString, "The number is %d and the string is %s", &new_num, new_str);
    printf("The new number is %d and the new string is %s\n", new_num, new_str);
}