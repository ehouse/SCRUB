#ifndef COMMANDLINE_GUARD_H
#define COMMANDLINE_GUARD_H

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <cstdio>
#include "gstreamer_wrapper.h"
#include "helpDoc.h"

//namespaces

using namespace std;

// functions

void start_gstreamer();             // Calls thread_init and creates thread
void *thread_init(void*);           // Becomes a threaded application
void terminate(int status);         // Terminates the process with proper error code
void argument_parser(int,char**);   // Main Program Logic
bool check_file(char *);            // Checks whether file is valid
bool chcek_stream(char *);          // Checks if stream is valid

#endif
