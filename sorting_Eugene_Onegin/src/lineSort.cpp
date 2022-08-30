#include "lineSort.hpp"

static int IsRuLetter(wchar_t symbol)
{
    return ((L'а' <= symbol) && (symbol <= L'я')) || ((L'А' < symbol) && (symbol <= L'Я'));
}

static int CompareLines(const void *value1, const void *value2)
{
    assert(value1 && value2);

    const wchar_t *string1 = *((wchar_t **)value1);
    const wchar_t *string2 = *((wchar_t **)value2);

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

void SortLines(const wchar_t **lines, size_t count)
{
    assert(lines);

    qsort(lines, count, sizeof(wchar_t *), CompareLines);
}