#include "IOLib.hpp"
#include "lineSort.hpp"

const char *SourceFileName = "original.txt";
const char *DestinationFileName = "sorted.txt";

int main()
{
    char *text = ReadFile(SourceFileName);
    if(text == NULL)
    {
        printf("Troubles with input file.");
        return -1;
    }

    long linesCount = 0;
    const char **lines = (const char **)SeparateLines(text, &linesCount);

    SortLines(lines, linesCount);

    if(WriteLines(DestinationFileName, lines, linesCount))
    {
        printf("Troubles with output file.");
        return -1;
    }

    return 0;
}