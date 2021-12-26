prog : ticTacToe.cpp
	clang++ -Wall -o prog -std=c++14 -Wno-deprecated -g ticTacToe.cpp -framework OpenGL -framework GLUT -lm

run: prog
	./prog

clean:
	rm -r prog prog.dSYM
