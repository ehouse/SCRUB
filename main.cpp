#include <gst/gst.h>
#include "commandline.h"

int main(int argc, char *argv[]){
	if(argc == 1) // Exit without program input
		return 1;
	argument_parser(argc,argv);
}
