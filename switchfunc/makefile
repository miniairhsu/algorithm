ARCH=arm
COMPILER=arm-linux-gnueabihf-


incs=-I/home/swlib/gsl/include -I.	
libs=-L/home/swlib/gsl/lib -L.
ldflags=-lgsl -lgslcblas -lm -pthread 
deps := $(wildcard *.h) 
	
AP: main.o 
	gcc main.o $(ldflags) $(libs) $(incs) -o main.exe

main.o:main.c $(deps)
	gcc -c main.c $(ldflags) $(libs) $(incs) -o main.o  
	
clean:
	rm -f *.o .logibone_fifo.ko.cmd .logibone_fifo.mod.o.cmd .logibone_fifo.o.cmd
	rm -f *.ko .tmp_versions/*
	rm -f logibone_fifo.mod.*
	rm -f [mM]odule*
	rm -f *.exe
	rmdir .tmp_versions/