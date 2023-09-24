#include <stdio.h>
#include <string.h>

int main() {
    char buf[20];
    int num = 123;

    snprintf(buf, sizeof(buf), "%08d", num);
    printf("%s\n", buf);
}
