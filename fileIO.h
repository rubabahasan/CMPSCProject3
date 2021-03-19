#include <stdio.h>
#include "dataStructures.h"





/*Opens the file given the filename. Assumes all files are in traces folder and adds the foldername itself. Just input filename.*/
FILE* openTrace(char* traceName);
/*Closes the file given the file pointer.*/
int closeTrace(FILE* fptr);

/*Reads next line of the trace file and returns a process control block for it. Initializes the name, start_time, cpu_time and memoryFilename in the PCB*/
struct PCB* readNextTrace(FILE* fptr);

/* Reads the next line in the memory file. Returns the address/type of the next MEM/NONMEM access.*/
struct NextMem* readNextMem(FILE* fptr); 

/* Reads the system parameters from the file. Returns a struct containing the values.*/
struct SystemParameters* readSysParam(FILE* fptr);

int writeToFile(char* filename, struct TotalStats resultStats);

