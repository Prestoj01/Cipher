compile: Queue Cipher
	g++ Project3.cpp Cipher.o Queue.o -Wall -o project3.out

Queue:
	g++ -c Queue.cpp -o Queue.o

Cipher:
	g++ -c Cipher.cpp -o Cipher.o

run:
	./project3.out

clean:
	rm *.o *.out