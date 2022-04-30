#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.h"
#include "/home/mtm/public/2122b/ex1/RLEList.h"

#define CHUNK_SIZE 2

/** Enum used for returning error codes **/
typedef enum
{
    SUCCESS,
    ERROR
} Status;

/** prints error message to sdrerr.**/
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
}

Status writeInverted(FILE *streamIn, FILE *streamOut)
{
    char buffer[CHUNK_SIZE];
    while (fgets(buffer, CHUNK_SIZE, streamIn) != NULL)
    {
        if (buffer[0] == '@')
        {
            buffer[0] = ' ';
        }
        else if (buffer[0] == ' ')
        {
            buffer[0] = '@';
        }
        fputs(buffer, streamOut);
    }
    return SUCCESS;
}

Status writeEncoded(FILE *streamIn, FILE *streamOut)
{
    RLEList asciiRleList = asciiArtRead(streamIn);
    if (!asciiRleList)
    {
        return ERROR;
    }
    asciiArtPrintEncoded(asciiRleList, streamOut);
    RLEListDestroy(asciiRleList);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        error("Usage ./AsciiArtTool <flags> <source> <target>");
        return 1;
    }

    if (strcmp(argv[1], "-i") != 0 && strcmp(argv[1], "-e") != 0)
    {
        error("Flags can only be -i or -e.");
        return 1;
    }


    FILE *streamIn = fopen(argv[2], "r");


    if (!streamIn)
    {
        error("Error opening source file.");
        return 1;
    }

    FILE *streamOut = fopen(argv[3], "w");
    if (!streamOut)
    {
        fclose(streamIn);
        error("Error opening target file.");
        return 1;
    }

    if (strcmp(argv[1], "-i") == 0)
    {
        Status writeInvertedStatus = writeInverted(streamIn, streamOut);
        if (writeInvertedStatus == ERROR)
        {
            error("Error writing inverted ascii art.");
        }

    }
    if (strcmp(argv[1], "-e") == 0)
    {
        Status writeEncodedStatus = writeEncoded(streamIn, streamOut);
        if (writeEncodedStatus == ERROR)
        {
            error("Error writing encoded ascii art.");
        }
    }

    fclose(streamIn);
    fclose(streamOut);

    return 0;
}
