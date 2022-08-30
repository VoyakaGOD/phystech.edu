#include "IOLib.hpp"
#include "lineSort.hpp"

const char *SourceFileName = "original.txt";
const char *DestinationFileName = "sorted.txt";

int main()
{
    size_t linesCount = 0;
    const wchar_t **lines = (const wchar_t **)ReadAllLines(SourceFileName, &linesCount);

    SortLines(lines, linesCount);

    WriteAllLines(DestinationFileName, lines, linesCount);
}