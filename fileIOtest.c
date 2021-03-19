#include "fileIO.h"
#include "dataStructures.h"
#include "simulator.h"

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        printf("No file input\n");
        exit(1);
    }

    traceFileName = argv[1];

    traceptr = openTrace(traceFileName);

    struct SystemParameters* sysP = readSysParam(traceptr);

    return 0;

}