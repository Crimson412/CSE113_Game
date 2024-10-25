game:game.o rock_paper_scissors.o tic_tac_toe.o number_guessing.o
	gcc -o game game.o rock_paper_scissors.o tic_tac_toe.o number_guessing.o
game.o:game.c game.h struct.h
	gcc -c game.c
rock_paper_scissors.o:rock_paper_scissors.c rock_paper_scissors.h struct.h
	gcc -c rock_paper_scissors.c
tic_tac_toe.o:tic_tac_toe.c tic_tac_toe.h struct.h
	gcc -c tic_tac_toe.c
number_guessing.o: number_guessing.c number_guessing.h struct.h
	gcc -c number_guessing.c

clean:
	rm -f *.o *~ game
