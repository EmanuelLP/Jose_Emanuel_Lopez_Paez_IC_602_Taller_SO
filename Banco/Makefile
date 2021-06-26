all:
	gcc -g -c -Wall main.c -o main.o
	gcc -g -c -Wall banco.c -o banco.o
	gcc -g -Wall main.o banco.o -o application

clean:
	rm *.o
	rm application
