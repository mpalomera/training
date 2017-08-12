all:
	 gcc -c zigzag-conversion.c
	 gcc -c main.c
	 gcc -o main zigzag-conversion.o main.o

test_zigzag-conversion: clean
	 gcc -c zigzag-conversion.c
	 gcc -c test_zigzag-conversion.c
	 gcc -o test_zigzag-conversion.exe zigzag-conversion.o test_zigzag-conversion.o
	 ./test_zigzag-conversion.exe

test:	 test_zigzag-conversion

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c zigzag-conversion.c
	 gcc -c main.c
	 gcc -o main.exe zigzag-conversion.o main.o
	 ./main
