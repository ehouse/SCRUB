#ifndef COMMANDLINE_GAURD_H
#define COMMANDLINE_GAURD_H

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include "gstreamer.h"

//definitions
#define BUFFERSIZE 2048

//functions
void start_gstreamer();
void* thread_init(void*);
void argument_parser(int argc, char *argv[]);
void set_buffer();
void buffer_args();

//global variables
static char buffer[BUFFERSIZE];
static char *bufferp = &buffer[0];
static char command[32];
static char* command_argsp[32];

#endif
