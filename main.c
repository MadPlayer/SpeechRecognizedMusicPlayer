#include <stdio.h>
#include <string.h>
#include "control.h"

int main(void){
	char command[100];
	Song current_song;

	init_song(&current_song);

	while(1){

		get_command(command);
		printf("command accepted\n");
		
		if(strcmp(command, "play") == 0){
			play_song(&current_song);
		}
		else if(strcmp(command, "pause") == 0){
			pause_song(&current_song);
		}
		else if(strcmp(command, "stop") == 0){
			stop_song(&current_song);
		}
		else if(strcmp(command, "shutdown") == 0){
			stop_song(&current_song);
			break;
		}
	}

	return 0;
}
