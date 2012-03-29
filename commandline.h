#ifndef COMMANDLINE_GAURD_H
#define COMMANDLINE_GAURD_H

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <string>
#include "gstreamer_wrapper.h"

//namespaces
using namespace std;

// functions
void start_gstreamer();
void *thread_init(void*);
void argument_parser(int,char**);

#endif
