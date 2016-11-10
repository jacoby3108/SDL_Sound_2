/* TEST OF Sound w/THREADS by dany*/
// 
// gcc thsound.c libaudio.c -I/usr/local/include -L/usr/local/lib -lSDL -lpthread -o thsound


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "libaudio.h"

#define  ONE_MS    	1000	   // One mseg
#define  time_delay(x)  (x/100)    // x in ms , minvalue 100mseg


unsigned int TimerTick;


void * thread1()  // Time base Thread
{
    while(1)
    {
               
		usleep(100*ONE_MS); // 100ms * 

		if (TimerTick)
			TimerTick--;
	
    }
}

void * thread2() // Periodic Task Thread

{
	static int r=0;
	
	while (1) 
	{

		if (!TimerTick)			// Wait for Thread1
		{
	   	  
	        TimerTick=time_delay(500);       // 500ms 
	        printf("Thread 2 r=%d\n",r++);  // Call SPI
	                
	    }

	}

}




void * thread3() // The APP

{
	while (1)
	{
	
				if(player_status()==READY)
				{
				
					printf(GREEN_TEXT "Play the Sound \n" WHITE_TEXT );
											
					set_file_to_play("./Sound/red.wav");
					//set_file_to_play("baby.wav");	
			
						
					play_sound();
					sleep(10);
					stop_sound();
				}

				
				sleep(3);

				if(player_status()==READY)
				{
				
					printf(GREEN_TEXT "Play the Sound \n" WHITE_TEXT );
											
					//set_file_to_play("./Sound/red.wav");
					set_file_to_play("baby.wav");	
			
						
					play_sound();
					sleep(10);
					stop_sound();
				}

	
	}
}


int main()
{
        int status;
        pthread_t tid1,tid2,tid3;
        srand(time(NULL));
        
		init_sound();
	    
	
	

        pthread_create(&tid1,NULL,thread1,NULL);
        pthread_create(&tid2,NULL,thread2,NULL);
        pthread_create(&tid3,NULL,thread3,NULL);
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);
        return 0;
}

