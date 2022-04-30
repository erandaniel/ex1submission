#ifndef HW1_ASCII_ART_TOOL_H
#define HW1_ASCII_ART_TOOL_H

#include <stdio.h>
#include <stdbool.h>

#include "/home/mtm/public/2122b/ex1/RLEList.h"

RLEList asciiArtRead(FILE* in_stream);

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);

#endif 