#include <cstdio>
#include "helpDoc.h"

void print_helpDoc(char *arg){
	/* This is to print all of the arguments of the program. As new functions are
		this file will be updated. Help file is printed with -h or --help flags.
	*/
	printf("\t-h --help    : prints this help doc");
	printf("\n\t-v --version : prints version information");
	printf("\n\t-s --stream  : passes the url of a music stream");
	printf("\n\t-f --file    : passes a file location");
	printf("\n");
}

void print_version(){
	/* Prints version information */
	printf("SCUM - Soap C Unified Media Back-end (0.01)\n");
	printf("Written by Ethan House\n");
}
