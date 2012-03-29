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

void argument_parser(int argc, char *argv[]){
	start_gstreamer(); // Starts gstreamer thread for audio playback

	int return_status;
	char *file_location;
	char *stream_location;
	for(int x = 0;x < argc;x++){
		if(strcmp(argv[x],"-s") == 0)
			stream_location = argv[x+1];
		if(strcmp(argv[x],"-f") == 0)
			file_location = argv[x+1];
	printf("%s",file_location);
	}
}
