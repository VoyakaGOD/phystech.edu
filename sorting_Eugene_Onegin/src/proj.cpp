#include "IOLib.hpp"
#include "lineSort.hpp"

const char *SourceFileName = "original.txt";
const char *DestinationFileName = "sorted.txt";

int main()
{
    size_t fileSize = 0;
    char *text = ReadFile(SourceFileName, &fileSize);
    if(text == NULL)
    {
        printf("Troubles with input file.");
        return -1;
    }

    long linesCount = 0;
    const char **lines = (const char **)SeparateLines(text, &linesCount);

    FILE *outputFile = fopen(DestinationFileName, "w");
    if(outputFile == NULL)
    {
        printf("Troubles with output file.");
        return -1;
    }

    SortLines(lines, linesCount);
    WriteLines(outputFile, lines, linesCount);
    
    SortFlippedLines(lines, linesCount);
    WriteLines(outputFile, lines, linesCount);

    RestoreLineEndings(text, linesCount);
    fwrite(text, sizeof(char), fileSize, outputFile);

    fclose(outputFile);
    return 0;
}