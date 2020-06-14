build: main.o
	g++ main.o -o main

main.o: main.cpp
	g++ -c main.cpp

run: build
	./main

clean: 
	rm -f *.o main test_main

snapshot: clean
	rm -rf snapshot
	mkdir snapshot
	cp *.h *.cpp README Makefile snapshot

docs:
	cat README