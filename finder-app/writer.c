#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main (int argc, char *argv[]){

    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3){
        syslog(LOG_ERR, "INVALID NUMBER OF ARGUMENTS. USAGE: %s <file> <string>", argv[0]);
        closelog();
        // printf("Error: Usage: %s <file> <string>\n", argv[0]);
        return 1;
    }

    const char *filepath = argv[1];
    const char *text = argv[2];

    FILE *fp = fopen(filepath, "w");
    if(fp == NULL){
        syslog(LOG_ERR, "Failed to open file: %s", filepath);
        closelog();
        return 1;
    }

    if(fprintf(fp, "%s", text) < 0){
        syslog(LOG_ERR, "Failed to write to file %s", filepath);
        fclose(fp);
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", text, filepath);

    fclose(fp);
    closelog();


    // syslog(LOG_DEBUG, "Arguments OK. File path: %s | String: %s", argv[1], argv[2]);
    // closelog();
    // printf("File path: %s\n", argv[1]);
    // printf("String to write: %s\n", argv[2]);

    return 0;
};