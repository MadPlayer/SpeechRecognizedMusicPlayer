#include "control.h"

void init_song(Song* song){
	song -> pid = 0;
	song -> state = Stop;
	strcpy(song -> name, "no name");
}

int play_song(Song* song){
	int fd[2];
	pid_t child;

	switch(song -> state){
		case Play:
			return 1;

		case Pause:
			kill(song -> pid, SIGCONT);
			song -> state = Play;
			return 1;

		case Stop:

			pipe(fd);
			child = fork();

			if(child){//parent
				FILE* streamR;

				close(fd[1]);//close write

				streamR = fdopen(fd[0], "r");
				fscanf(streamR, "%s", song -> name);//read song name
				song -> state = Play;
				song -> pid = child;

				fclose(streamR);
				printf("end play");

				return 1;
			}
			else if(child == 0){//child
				char *const argv[] = { "python3", "SRplay.py", "play", NULL };

				close(fd[0]);//close read
				dup2(fd[1], STDOUT_FILENO);//make executed process have stdout stream as pipe write stream
				
				execv("/usr/bin/python3", argv);
			}
			else{
				printf("int play(struct Song*) ERROR: fork problem\n");
				exit(-1);
			}
		default:
			break;
	}//switch end
}

int pause_song(Song* song){
	if(song -> state == Play){
		kill(song -> pid, SIGSTOP);
		
		return 1;
	}
	else return 0;
}

int stop_song(Song* song){
	if(song -> state != Stop){
		kill(song -> pid, SIGTERM);
		song -> state = Stop;
		
		return 1;
	}
	else return 0;
}
	
int get_command(char cmd[100]){
	int fd[2];
	pid_t child;
	int i;

	pipe(fd);
	child = fork();

	if(child){//parent

		FILE* streamR;

		close(fd[1]);//close write
		
		streamR = fdopen(fd[0], "r");
		fscanf(streamR, "%s", cmd);
		printf("%s\n", cmd);
		
		waitpid(child, NULL, 0);
		fclose(streamR);

		return 1;
	}
	else if(child == 0){//child
		char *const argv[] = { "python3", "SRplay.py", "cmd", NULL };

		close(fd[0]);//close read
		dup2(fd[1], STDOUT_FILENO);//make executed process have stdout stream as pipe write stream

		execv("/usr/bin/python3", argv);
	}
}
