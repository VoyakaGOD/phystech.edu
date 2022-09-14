#include "lineSort.hpp"

// for 1251
static int IsRuLetter(char symbol)
{
    return ((unsigned char)192 <= (unsigned char)symbol);
}

static int CompareLines(const void *value1, const void *value2)
{
    assert(value1 && value2);

    const char *string1 = *((const char **)value1);
    const char *string2 = *((const char **)value2);

    size_t index1 = 0;
    size_t index2 = 0;
    while(string1[index1] && string2[index2])
    {
        while(string1[index1] && !IsRuLetter(string1[index1]))
            index1++;
        while(string2[index2] && !IsRuLetter(string2[index2]))
            index2++;
        if(string1[index1] != string2[index2])
            break;
        index1++;
        index2++;
    }

    return string1[index1] - string2[index2];
}

char SortLines(const char **lines, size_t count)
{
    if(lines == NULL)
        return 1;

    qsort(lines, count, sizeof(char *), CompareLines);

    return 0;
}