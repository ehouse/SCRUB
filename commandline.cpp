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
	// status(3) : 
	// status(4)
	// status(5)
	
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
	start_gstreamer(); // Starts gstreamer thread for audio playback

	// argument checker
	for(int x = 0;x < argc;x++){
		if(!strcmp(argv[x],"-s" ) || !strcmp(argv[x],"--stream")){
			input_lock = true;
			stream_location = argv[x+1];
		}
		if(!strcmp(argv[x],"-f") || !strcmp(argv[x],"--file")){
			input_lock=true;
			file_location = argv[x+1];
		}
	}
}
