/* commandline.cpp
 * Written By Ethan House
 *
 * Contains bulk of the program logic. 
*/

#include "commandline.h"

// Global Variables
static int thr_id;
pthread_t p_thread;

void start_gstreamer(){
	// Creates thread for audio playback
	thr_id = pthread_create(&p_thread,NULL,thread_init,NULL);
}

void *thread_init(void*){
	// Gstreamer init function. 
	init_gstreamer();
}

void terminate(int status){
	// status(0) : Exit Cleanly
	// status(1) : incompatible flags
	// status(2) : File or Stream doesn't exist
	
	switch(status){
		case 0:
			exit(0);
		case 1:
			printf("Incompatible Flags\n");
			exit(1);
		case 2:
			printf("File or Stream doesn't exist\n");
			exit(2);
		default:
			exit(status);
	}
}

void argument_parser(int argc, char *argv[]){
	// variables
	bool input_lock(false);   // value to make surer -s and -f aren't used together
	int return_status;        // int value that varies depending on function return
	char *file_location;
	char *stream_location;

	// function calls
	start_gstreamer();        // Starts gstreamer thread for audio playback

	// argument checker
	for(int x = 0;x < argc;x++){
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
	//do stuff with flags
}

/* End of File */
