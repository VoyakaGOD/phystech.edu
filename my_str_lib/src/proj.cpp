#include "MyStrLib.hpp"

int main()
{
    printf("len of 'pen' is %d\n", strlen("pen"));
    const char *hw = "Hello, world!";
    char str[128];
    strncpy(str, hw, 7);
    mputs(str);
    strncat(str, hw, 7);
    strcat(str, hw);
    mputs(str);

    char *dup = strdup(hw);
    dup[7] = 'W';
    mputs(dup);
    free(dup);

    char input[128];
    mfgets(input, 128, stdin);
    strcat(input, hw);
    mputs(input);

    printf("%d\n", strcmp("ABC", "ABE"));

    getchar();
}