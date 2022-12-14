#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char** av) {
    FILE *fp;
    if(ac > 1)
        fp = fopen(av[1],"r");
    if(fp == NULL) {
        perror("Unable to open file");
        exit(1);
    }

    char chunk[128];

    // Store the chunks of text into a line buffer

    size_t len = sizeof(chunk);
    char *line = malloc(len);
    if(line == NULL) {
        perror("Unable to allocate memory for  the line buffer,");
        exit(1);
    }
    line[0] = '\0';

    while(fgets(chunk,sizeof(chunk), fp) != NULL) {
       // Resize the line buffer if necessary  
        if(len - strlen(line) < sizeof(chunk)) {
            len *= 2;
            if((line = realloc(line, len)) == NULL) {
                perror("Unable to reallocate memory for the line Buffer.");
                free(line);
                exit(1);
            }
        }
        // Append the chunk to the end of the line buffer
        strcat(line,chunk);
        //check if line contains '\n', if yes process the line of text
        if(line[strlen(line) - 1] == '\n') {
           fputs(line,stdout);
            // fputs("|*\n", stdout);
            // printf("line length: %zd\n", strlen(line));
            line[0] = '\0';
        }
    }

    fclose(fp);
    free(line);
    //printf("\n\n Max line size: %zd\n",len);
}
