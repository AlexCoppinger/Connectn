connectn.out: main.o inputvalidation.o board.o gameplay.o win.o
	gcc -g -Wall -Werror -o connectn.out main.o inputvalidation.o board.o gameplay.o win.o
main.o: main.c inputvalidation.h board.h gameplay.h
	gcc -g -Wall -Werror -c main.c
inputvalidation.o: inputvalidation.c inputvalidation.h
	gcc -g -Wall -Werror -c inputvalidation.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
gameplay.o: gameplay.c gameplay.h board.h
	gcc -g -Wall -Werror -c gameplay.c
win.o: win.c win.h board.h
	gcc -g -Wall -Werror -c win.c


clean:
	rm -f *.o *.out 

run: connectn.out
	./connectn.out

