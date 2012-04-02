#include <stdio.h>

void print_helpDoc(char *arg){
	/* This is to print all of the arguments of the program. As new functions are
		this file will be updated. Help file is printed with -h or --help flags.
	*/
	printf("\n\t-h --help   : prints this help doc");
	printf("\n\t-s --stream : passes the url of a music stream");
	printf("\n\t-f --file   : passes a file location");
}
