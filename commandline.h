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

void start_gstreamer();
void *thread_init(void*);
void terminate(int status);
void argument_parser(int,char**);

#endif
