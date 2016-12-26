#include "vars.h"
#include "zcore.h"
#include "zresm.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include "SDL/SDL.h"

int main(int argc, char *argv[])
{
	int c;
	while(1) {
		static struct option long_options[]={
			{"geometry",required_argument,0,'g'},
			{"joystick",required_argument,0,'j'},
			{"fullscreen",no_argument,0,'f'},
			{"help",no_argument,0,'h'},
			{0,0,0,0}
		};
		int option_index=0;
		c=getopt_long(argc,argv,"g:x:y:fh",long_options,&option_index);
		if(c==-1) break;

		switch(c) {
			char *end;
			int x, y;
		case 'g':
			x = strtol(optarg,&end,10);
			y = strtol(end,NULL,10);
			if(x>0&&y>0) {screenwidth=x; screenheight=y;}
			break;
		case 'j':
			whichjoystick=strtol(optarg,NULL,10);
			break;
		case 'f':
			fullscreen=SDL_FULLSCREEN;
			break;
		case 'h':
			printf("Valid options:\n-f --fullscreen\t\t\tEnable fullscreen display for -DPCEGL.\n-g --geometry width\\ height\tSet the window geometry in pixels (default 320x240 or 800x600).\n-h --help\t\t\tPrint this help screen.\n-j --joystick number\t\tSet the joystick device to use (default is 0, automatic for -DGCW).\n");
			return 0;
			break;
		}
	}

	zresminit();

	zcoreinit();
	zcoreloop();

	zresmdown();

	zcoredown();

	return 0;
}
