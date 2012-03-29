#include "commandline.h"
#include <stdio.h>

static int thr_id;
pthread_t p_thread;

void start_gstreamer(){
	//starts thread
	thr_id = pthread_create(&p_thread,NULL,thread_init,NULL);
}

void *thread_init(void*){
	//calls gstreamer startup functions
	//leaves this file at this pointer
	//threading is fun
	init_gstreamer();
}

void argument_parser(int argc, char *argv[]){
	int return_status;
	start_gstreamer();
}
