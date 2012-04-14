/* 
 * commandline.cpp
 * Written By Ethan House
 *
 * Contains bulk of the program logic. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "commandline.h"

// Global Variables
static int thr_id;
pthread_t p_thread;

void start_gstreamer(){
	// Creates thread for audio playback
	thr_id = pthread_create(&p_thread,NULL,thread_init,NULL);
}

void *thread_init(void *){
	// Gstreamer init function. 
	init_gstreamer();
}

void terminate(int status){
	// status(0) : Exit Cleanly
	// status(1) : incompatible flags
	// status(2) : File or Stream doesn't exist
	// status(3) : Memory Allocation Error

	switch(status){
		case 0:
			break;
		case 1:
			fprintf(stderr,"Incompatible Flags, exiting\n");
			break;
		case 2:
			fprintf(stderr,"File or Stream doesn't exist, exiting\n");
			break;
		case 3:
			fprintf(stderr,"Memory Allocation Error, exiting\n");
			break;
		default:
			fprintf(stderr,"I Just don't know what went wrong, exiting\n");
			break;
	}
	exit(status);
}

void argument_parser(int argc, char *argv[]){
	// variables
	bool input_lock(false);   // value to make surer -s and -f aren't used together
	int return_status;        // int value that varies depending on function return
	char *file_location = NULL;
	char *stream_location = NULL;
	char *cwd=NULL;
	char *destination;
	int array_size1;
	int array_size2;
	size_t size;
	 
	// function calls
	start_gstreamer();        // Starts gstreamer thread for audio playback
	
	// argument checker
	for(int x = 0;x < argc;x++){
		if(!strcmp(argv[x],"-v" ) || !strcmp(argv[x],"--version")){
			print_version();
			terminate(0);
		}
		if(!strcmp(argv[x],"-h" ) || !strcmp(argv[x],"--help" )){
			print_helpDoc(NULL);
			terminate(0);
		}
		if(!strcmp(argv[x],"-s" ) || !strcmp(argv[x],"--stream")){
			if(input_lock == true)
				terminate(1);    // If a input flag is already declared, exit gracefully
			input_lock = true;
			stream_location = argv[x+1];
		}
		if(!strcmp(argv[x],"-f") || !strcmp(argv[x],"--file")){
			if(input_lock == true)
				terminate(1);    // If a input flag is already declared, exit gracefully
			input_lock=true;
			file_location = argv[x+1];
		}
	}
	
	// At this point we check to see if stream or file are actually there.
	// If files do not exist then we return the proper error codes and terminate
	// cleanly.
	if(file_location != NULL){
		cwd=getcwd(cwd,size);
		if(file_location[0] == '.' && file_location[1] == '/'){
			// Not Implemented
		}
		else if(file_location[0] == '/'){
			strcpy(destination,file_location);
			if (check_file(destination)) {
				// All Good
			}else {
				// Unable to locate file
				printf("Unable to locate file: %s\n",destination);
				terminate(2);
			}
		}
		else{
			array_size1 = strlen(file_location);
			array_size2 = strlen(cwd);
			destination = new char[array_size1+array_size2];
			if(destination == 0){
				terminate(3); // terminate with memory allocation error
			}
			strcpy(destination,cwd);
			strcat(destination,"/");
			strcat(destination,file_location);
			if(check_file(destination)){
				// All Good
			}else{
				// Unable to locate file
				printf("Unable to locate file: %s\n",destination);
				terminate(2);
			}
		}
	}
	else if(stream_location != NULL){
		// Not implemented
	}else{
		// Not implemented
		terminate(2);
	}
}

bool check_file(char *file_loc){
	// if file exists return true
	// We did not use boost which would have been easier but is another dep
	FILE * pfile;
	pfile = fopen(file_loc,"r");
	if (pfile==NULL){
		return false;
	}else{
		fclose(pfile);
		return true;
	}
}

bool check_stream(char *stream_loc){
	// Not Implemented
	return true;
}

/* End of File */
