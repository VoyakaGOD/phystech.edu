#include "IOLib.hpp"
#include "lineSort.hpp"

const char *SourceFileName = "original.txt";
const char *DestinationFileName = "sorted.txt";

int main()
{
    char **lines = ReadAllLines(SourceFileName);

    SortLines(lines);

    WriteAllLines(DestinationFileNam, lines);
}