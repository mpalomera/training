all:
	 gcc -c addTwoNumbers.c
	 gcc -c main.c
	 gcc -o main addTwoNumbers.o main.o

test_addTwoNumbers: clean
	 gcc -c addTwoNumbers.c
	 gcc -c test_addTwoNumbers.c
	 gcc -o test_addTwoNumbers addTwoNumbers.o test_addTwoNumbers.o
	 ./test_addTwoNumbers

test:	 test_addTwoNumbers

clean:
	 rm *.out || exit 0

run:
	 gcc -c addTwoNumbers.c
	 gcc -c main.c
	 gcc -o main addTwoNumbers.o main.o
	 ./main
