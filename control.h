#ifndef MUSIC_CONTROL
#define MUSIC_CONTROL

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

typedef enum State{
	Play, Pause, Stop
}State;

typedef struct Song{
	pid_t pid;
	State state;
	char name[100];
}Song;

void init_song(Song* song);
int play_song(Song* song);
int pause_song(Song* song);
int stop_song(Song* song);
int get_command(char cmd[100]);

#endif
