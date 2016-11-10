

/* TEST OF Sound Library libaudio by dany*/
// gcc simple.c libaudio.c -I/usr/local/include -L/usr/local/lib -lSDL -o simple -lpthread
// Run with ./simple


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "libaudio.h"

char AudioFile_RED[]="./Sound/red.wav";
char AudioFile_GREEN[]="./Sound/green.wav";
char AudioFile_BLUE[]="./Sound/blue.wav";
char AudioFile_YELLOW[]="./Sound/yellow.wav";

void do_something(void);

void play_color(char * AudioFile); 

#define PLAY_TIME 1			// Change do_something() delay 

void main(void) 
{
	
	printf(GREEN_TEXT "Audio player \n" WHITE_TEXT );
	
	
    init_sound(); // Init sound driver
    
    play_color(AudioFile_RED); 
   	do_something();					  // Waste some time while playing
 	play_color(AudioFile_GREEN); 
 	do_something();					  // Waste some time while playing
 	play_color(AudioFile_BLUE); 
 	do_something();					  // Waste some time while playing
 	play_color(AudioFile_YELLOW); 
 	do_something();					  // Waste some time while playing
 	
}


void play_color(char * AudioFile) // Non blocking Audio File
{
	
 	stop_sound();						  // stop previous audio track (Just in case)
 	
	if(player_status()==READY)
	{
			
		printf(GREEN_TEXT "Playing: %s \n",AudioFile); 	printf(WHITE_TEXT);
	
		set_file_to_play(AudioFile);      // Load file 			
	
		play_sound(); 					  // Play File (Non Blocking)

		return;
	}
	else
	{
			
		printf(RED_TEXT "System not ready did you run init_sound() ? \n" WHITE_TEXT );
				
		exit(-1);		
	}
	
}




void do_something(void)
{
	int i;
				
	for(i=0;i<PLAY_TIME;i++)  // Do someting else for a while (change i)
	{
		
		printf(YELLOW_TEXT "Playing ...\n" WHITE_TEXT ); // show this every 300 ms while playing the sound in background
	    SDL_Delay(300);
	}
	
	
}
