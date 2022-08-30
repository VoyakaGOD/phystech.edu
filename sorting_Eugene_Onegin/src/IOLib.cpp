#include "IOLib.hpp"

wchar_t *ReadLine(FILE *file)
{
    size_t lineSize = 4;
    size_t index = 0;
    wchar_t *line = (wchar_t *)calloc(lineSize, sizeof(wchar_t));

    wint_t symbol = 0;
    do
    {
        if(index >= lineSize)
        {
            lineSize *= 2;
            line = (wchar_t *)realloc(line, lineSize * sizeof(wchar_t));
        }

        symbol = fgetwc(file);
        line[index] = symbol;
        index++;
    }
    while(symbol != WEOF && symbol != L'\n');
    
    line[index - 1] = L'\0';
    return line;
}

wchar_t **ReadAllLines(const char *fileName, size_t *linesCount)
{
    size_t count = 0;
    wchar_t **lines = NULL;
    FILE *file = fopen(fileName, "r, ccs=UTF-8");
    if(file == NULL)
    {
        printf("Incorrect file!");
        getchar();
        abort();
    }

    while(!feof(file))
    {
        lines = (wchar_t **)realloc(lines, (count + 1) * sizeof(wchar_t *));
        lines[count] = ReadLine(file);
        count++;
    }

    fclose(file);
    *linesCount = count;
    return lines;
}

void WriteAllLines(const char *fileName, const wchar_t **lines, size_t linesCount)
{
    FILE *file = fopen(fileName, "w, ccs=UTF-8");
    if(file == NULL)
    {
        printf("Troubles with output file!");
        getchar();
        abort();
    }

    for(size_t i = 0; i < linesCount; i++)
    {
        fputws(lines[i], file);
        fputwc(L'\n', file);
    }

    fclose(file);
}