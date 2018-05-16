all: main.o Account.o User.o Transaction.o
	g++ -g main.o Account.o User.o Transaction.o -o ZingHw03
	rm *.o
main.o:
	g++ -c main.cpp 
Account.o:
	g++ -c Account.cpp
User.o:
	g++ -c User.cpp
Transaction.o:
	g++ -c Transaction.cpp

clean:
	rm *.o