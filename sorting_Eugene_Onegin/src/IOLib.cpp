#include "IOLib.hpp"

static long GetFileSize(FILE *file)
{
    if(file == NULL)
        return -1;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}

char *ReadFile(const char *fileName, size_t *length)
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
        return NULL;

    long fileSize = GetFileSize(file);
    if(length != NULL)
        *length = fileSize;

    char *text = (char *)calloc(fileSize, sizeof(char));
    fread(text, sizeof(char), fileSize, file);

    fclose(file);
    return text;
}

char **SeparateLines(char *text, long *linesCount)
{
    if(text == NULL)
        return NULL;

    long count = 1;
    for(long i = 0; text[i]; i++)
    {
        if(text[i] == '\n')
            count++;
    }

    long index = 1;
    char **lines = (char **)calloc(count, sizeof(char *));
    lines[0] = text;
    for(long i = 0; text[i]; i++)
    {
        if(text[i] == '\n')
        {
            lines[index++] = text + i + 1;
            text[i] = '\0';
        }
    }

    *linesCount = count;
    return lines;
}

char RestoreLineEndings(char *text, long linesCount)
{
    if(text == NULL)
        return 0;

    linesCount--;
    while(linesCount > 0)
    {
        if(!(*text))
        {
            *text = '\n';
            linesCount--;
        }
        text++;
    }
}

char WriteLines(FILE *file, const char **lines, long linesCount)
{
    if(lines == NULL)
        return 0;

    for(long i = 0; i < linesCount; i++)
    {
        fputs(lines[i], file);
        fputc('\n', file);
    }

    return 0;
}
