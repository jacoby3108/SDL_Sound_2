

/* TEST OF Sound w/THREADS by dany*/
// gcc thsound.c libdany.c -I/usr/local/include -L/usr/local/lib -lSDL -lpthread -o thsound


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "libaudio.h"


// ============ Colored Text ===========

#define BLACK_TEXT		   "\e[30;1m"
#define RED_TEXT		   "\e[31;1m"
#define GREEN_TEXT 		   "\e[32;1m"
#define YELLOW_TEXT 	   "\e[33;1m"
#define BLUE_TEXT 		   "\e[34;1m"
#define MAGENTA_TEXT 	   "\e[35;1m"
#define CYAN_TEXT 	   	   "\e[36;1m"
#define WHITE_TEXT 		   "\e[37m"

// ============ Colored Text End ===========


void main(void) // The APP

{
	int i;
	init_sound();
		
	
	if(player_status()==READY)
	{
				
		printf(GREEN_TEXT "Playing: Wake Me Up \n" WHITE_TEXT );
					
		set_file_to_play("Avicii - Wake Me Up .wav");		// Load file 	
		//set_file_to_play("./Sound/red.wav");		// Load file 			
		
		play_sound(); // Play File 
		
		
		for(i=0;i<2;i++)  // Do someting else for a while
		{
			sleep(1);
			
			if(player_status()==PLAYING)
			{	
				printf(YELLOW_TEXT "Playing ...\n" WHITE_TEXT ); // show this every second while playing the sound in background
			
			}
			else if (player_status()==FINISHED)							// Do this test always before stop
			{
				printf(YELLOW_TEXT "Sondtrack Finished!! \n" WHITE_TEXT ); 
				stop_sound();		// Stop playing
				
				break;
			}
			
		}
	
		//if (player_status()==FINISHED)
				
		stop_sound();		// Stop playing
		stop_sound();		// Stop playing
	    stop_sound();		// Stop playing
	
		printf(YELLOW_TEXT "Pfin ...\n" WHITE_TEXT );
		
		printf(GREEN_TEXT "Sound was stopped by App\n" WHITE_TEXT );
	
	}
				
	printf(RED_TEXT "The" " App\n" WHITE_TEXT );
				
				
	
}


