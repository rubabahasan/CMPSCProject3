#include <string.h>
#include <inttypes.h>

#include "fileIO.h"



FILE* openTrace(char* traceName){
    FILE *fptr;
    char* foldername = "traces/";

    char* filename = malloc(sizeof(foldername) + sizeof(traceName) + 1 ); /* make space for the new string (should check the return value ...) */
    strcpy(filename, foldername); /* copy name into the new var */
    strcat(filename, traceName); /* add the extension */


    if ((fptr = fopen(filename,"r")) == NULL){
        printf("Error opening file %s.\n", filename);
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    // printf("File opened\n");
    return fptr;
}

int closeTrace(FILE* fptr){
    if(fptr)
    {
        return fclose(fptr);
        // printf("\n File closed\n");
        return 1;
    }
    return 0;
}

struct PCB* readNextTrace(FILE *fptr){
    char* line = NULL;
    ssize_t read;
    size_t len = 0;
    struct PCB* p = NULL;
    char *token;
    char* extension = ".txt";


    if((read = getline(&line, &len, fptr)) != -1)
    {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s", line);
        p = malloc(sizeof(PCBNode));

        token = strtok(line, " ");
        // printf( "token ::%s::\n",token);
        if((strcmp(token, "")==0) || (strcmp(token, "\n")==0) || (strcmp(token, " ")==0))
        {
            printf("Line in tracefile contains no data.\n");
            return NULL;
        }
        p->name = token;
        // printf( "NAME %s::\n", p->name );

        char* filename = malloc(sizeof(token) + sizeof(extension) + 1 ); /* make space for the new string (should check the return value ...) */
        strcpy(filename, token); /* copy name into the new var */
        strcat(filename, extension); /* add the extension */
        p->memoryFilename = filename;
        // printf( "fileNAME %s::\n", p->memoryFilename );

        token = strtok(NULL, " ");
        p->start_time = atoi(token);
        // printf("START TIME %" PRIu64 "\n", p->start_time);

        // token = strtok(NULL, " ");
        // // printf( "TOKEN %s\n", token );
        // p->cpu_time = atof(token);
        // // printf("%lf \n", p->cpu_time);

        p->memReq = gll_init();
        p->hitCount = 0;
        p->missCount = 0;
        p->fracLeft = 0;
        p->user_time = 0;
        p->OS_time = 0;

        
    }
   return p;
}

struct NextMem* readNextMem(FILE* fptr)
{
    char* line = NULL;
    ssize_t read;
    size_t len = 0;

    if(fptr == NULL)
    {
        return NULL;
    }

    if((read = getline(&line, &len, fptr)) != -1)
    {
        //printf("Retrieved line of length %zu:\n", read);
        // printf("%s\n", line);
	struct NextMem* lineRead = (struct NextMem*)malloc(sizeof(struct NextMem));
	line[strcspn(line, "\n")] = '\0'; //removes trailing newline characters, if any

	if (strcmp(line, "NONMEM") == 0) {
	    lineRead->type = "NONMEM";
	    lineRead->address = NULL;
	}
	else {
	    lineRead->type = "MEM";
	    lineRead->address = (char*) malloc(sizeof(strlen(line)-4));
 	    strcpy(lineRead->address, line+4);
 	    // printf("Address returning: %s\n",lineRead->address);
	}
	return lineRead;
    }
    return NULL;
}