all:
	 gcc -c merge.c
	 gcc -c main.c
	 gcc -o main merge.o main.o

test_merge: clean
	 gcc -c merge.c
	 gcc -c test_merge.c
	 gcc -o test_merge.exe merge.o test_merge.o
	 ./test_merge.exe

test:	 test_merge

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c merge.c
	 gcc -c main.c
	 gcc -o main.exe merge.o main.o
	 ./main
