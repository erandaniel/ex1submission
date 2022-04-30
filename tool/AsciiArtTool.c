#include <stdlib.h>

#include "AsciiArtTool.h"
#include "/home/mtm/public/2122b/ex1/RLEList.h"

RLEList asciiArtRead(FILE *in_stream)
{
    RLEList rleAscii = RLEListCreate();
    char currentChar = ' ';

    do
    {
        currentChar = (char)fgetc(in_stream);
        if (feof(in_stream))
        {
            break;
        }
        RLEListAppend(rleAscii, currentChar);
    } while (1);

    return rleAscii;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    if (!list)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    int sizeOfList = RLEListSize(list);
    char currentChar = '\0';
    for (int i = 0; i < sizeOfList; i++)
    {
        currentChar = RLEListGet(list, i, NULL);
        if (fputc(currentChar, out_stream) < 0)
        {
            printf("Error writing to a file - asciiArtPrint");
        }
    }

    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if (!list)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    char *stringToBeSaved = RLEListExportToString(list, NULL);

    fputs(stringToBeSaved, out_stream);

    free(stringToBeSaved);

    return RLE_LIST_SUCCESS;
}
