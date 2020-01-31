
sr_player: main.o control.o
	gcc -o sr_player main.o control.o

main.o: main.c
	gcc -c main.c

control.o: control.c
	gcc -c control.c

clean:
	rm sr_player *.o -f
	rm __pycache__ -rf
