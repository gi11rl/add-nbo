#Makefile
all: add-nbo

add-nbo: add-nbo.c
	gcc -o add-nbo add-nbo.c

clean: 
	rm -f add-nbo
