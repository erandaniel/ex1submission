CC = gcc
OBJS = RLEList.o  tool//AsciiArtTool.o  tool//main.o
EXEC = AsciiArtTool
DEBUG_FLAG =# now empty, assign -g for debug
COMP_FLAG = -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG
MATAM_FOLDER = //home//mtm//public//2122b//ex1//
TOOL_FOLDER = tool//


$(EXEC) : $(OBJS)
	$(CC) $(COMP_FLAG) $(DEBUG_FLAG) $(OBJS) -o $@

RLEList.o: RLEList.c $(MATAM_FOLDER)RLEList.h
	$(CC) -c $(COMP_FLAG) $(DEBUG_FLAG) $*.c -o $@
tool//AsciiArtTool.o: $(TOOL_FOLDER)AsciiArtTool.c $(TOOL_FOLDER)AsciiArtTool.h $(MATAM_FOLDER)RLEList.h 
	$(CC) -c -o $*.o $(COMP_FLAG) $(DEBUG_FLAG) $*.c -o $@
tool//main.o: $(TOOL_FOLDER)main.c $(TOOL_FOLDER)AsciiArtTool.h $(MATAM_FOLDER)RLEList.h
	$(CC) -c $(COMP_FLAG) $(DEBUG_FLAG) $*.c -o $@

clean:
	rm -f $(OBJS) $(EXEC)