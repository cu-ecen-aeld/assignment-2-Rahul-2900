#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#define MAX 1024

void write_to_file(const char *string, const char *filename) {
     FILE *file = fopen(filename, "w");  //open file
     if(file == NULL) {
	     syslog(LOG_ERR, "Error in Open filename : %s",filename);
	     perror("Error Opening file");
	     exit(EXIT_FAILURE);
     }

     if(fputs(string, file) == EOF) {
	     syslog(LOG_ERR, "Error writing filename : %s", filename);
	     perror("Error Writing file");
	     fclose(file);
	     exit(EXIT_FAILURE);
     }

     syslog(LOG_DEBUG, "Writing \"%s\" to %s",string, filename);

     fclose(file);

}

int main(int argc, char *argv[]) {
	openlog("writer", LOG_PID | LOG_CONS, LOG_USER); //initialise syslog

	if(argc !=3) {
		syslog(LOG_ERR, "Invalid Args usage : %s", argv[0]);
		closelog();
		return EXIT_FAILURE;
	}

	const char *str_to_write = argv[1];
	const char *file_name = argv[2];
	write_to_file(str_to_write, file_name);
	closelog();
	return EXIT_SUCCESS;
}


