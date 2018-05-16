all:fib.o

fib.o: touch
	gcc --std=c11 -pg -o0 fib.c -o fib.o
touch:
	touch fib.o fib.c
clean:
	rm fib.o 
	rm gmon.out
