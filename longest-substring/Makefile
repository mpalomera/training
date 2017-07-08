all:
	 gcc -c longest-substring.c
	 gcc -c main.c
	 gcc -o main longest-substring.o main.o

test_longest-substring: clean
	 gcc -c longest-substring.c
	 gcc -c test_longest-substring.c
	 gcc -o test_longest-substring.exe longest-substring.o test_longest-substring.o
	 ./test_longest-substring.exe

test:	 test_longest-substring

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c longest-substring.c
	 gcc -c main.c
	 gcc -o main.exe longest-substring.o main.o
	 ./main
