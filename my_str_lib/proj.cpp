#include "MyStrLib.hpp"

int main()
{
    printf("len of 'pen' is %d\n", strlen("pen"));
    const char *hw = "Hello, world!";
    char str[128];
    strncpy(str, hw, 7);
    printf("%s\n", str);
    strncat(str, hw, 7);
    strcat(str, hw);
    printf("%s\n", str);

    char *dup = strdup(hw);
    dup[7] = 'W';
    printf(dup);

    getchar();
}