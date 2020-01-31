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
		printf("%s\n", command);
		
		if(strcmp(command, "play") == 0){
			play_song(&current_song);
			printf("Play Song: %s\n", current_song.name);
		}
		else if(strcmp(command, "pause") == 0){
			pause_song(&current_song);
			printf("Pause Song\n");
		}
		else if(strcmp(command, "stop") == 0){
			stop_song(&current_song);
			printf("Stop Song\n");
		}
		else if(strcmp(command, "shutdown") == 0){
			stop_song(&current_song);
			printf("good bye!\n");
			break;
		}
	}

	return 0;
}
