#include <stdio.h>
#include <string.h>

int main() {
    char str_alpha[26];
    char* str_beta = "abcdefgh";
    strncpy(str_alpha, str_beta, 8);
    printf("%s\n", str_alpha);

    char str_gamma[26];
    char* str_delta = "abcdefgh";
    memcpy(str_gamma, str_delta, 8);
    printf("%s\n", str_gamma);

    char str_epsilon[26];
    char str_zeta[26] = "abcdefgh";
    memcpy(str_epsilon, &str_zeta, 8);
    printf("%s\n", str_epsilon);
}
