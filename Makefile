game:game.o rock_paper_scissors.o tic_tac_toe.o
	gcc -o game game.o rock_paper_scissors.o tic_tac_toe.o
game.o:game.c game.h
	gcc -c game.c
rock_paper_scissors.o:rock_paper_scissors.c rock_paper_scissors.h
	gcc -c rock_paper_scissors.c
tic_tac_toe.o:tic_tac_toe.c tic_tac_toe.h
	gcc -c tic_tac_toe.c

clean:
	rm *.o game game.c~ game.h~ rock_paper_scissors.c~ rock_paper_scissors.h~ tic_tac_toe.c~ tic_tac_toe.h~ Makefile~
