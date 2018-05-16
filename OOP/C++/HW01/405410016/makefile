all: CPPHw01.o JAVAHw01.class

CPPHw01.o: CPPHw01.c
	g++ CPPHw01.o -o CPPHw01.out

CPPHw01.c:
	g++ -c -g CPPHw01.cpp

JAVAHw01.class: JAVAHw01.java
	javac -g JAVAHw01.java

clean:
	rm *.out
	rm *.o
	rm *.class 