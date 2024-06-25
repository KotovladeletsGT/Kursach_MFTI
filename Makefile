all: report

report : main.o temp_functions.o banner_functions.o
	gcc main.o temp_functions.o banner_functions.o -o report

main.o : main.c
	gcc -c main.c -o main.o -Wall

temp_functions.o : temp_functions.c
	gcc -c temp_functions.c -o temp_functions.o -Wall

banner_functions.o : banner_functions.c
	gcc -c banner_functions.c -o banner_functions.o -Wall