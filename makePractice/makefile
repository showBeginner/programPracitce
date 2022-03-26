hello.out:hello.o 2.o 3.o
	g++ -o hello.out hello.o 2.o 3.o

hello.o:hello.cpp a.h
	g++ -c hello.cpp

2.o:2.cpp b.h
	g++ -c 2.cpp

3.o:3.cpp a.h b.h c.h
	g++ -c 3.cpp

.PHONY:clean
clean:
	rm -f hello.out hello.o 2.o 3.o
