all:
	 gcc -c longest-palindromic.c
	 gcc -c main.c
	 gcc -o main longest-palindromic.o main.o

test_longest-palindromic: clean
	 gcc -c longest-palindromic.c
	 gcc -c test_longest-palindromic.c
	 gcc -o test_longest-palindromic.exe longest-palindromic.o test_longest-palindromic.o
	 ./test_longest-palindromic.exe

test:	 test_longest-palindromic

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c longest-palindromic.c
	 gcc -c main.c
	 gcc -o main.exe longest-palindromic.o main.o
	 ./main
