ARCH=arm
COMPILER=arm-linux-gnueabihf-


incs=-I.	
libs=-L.
ldflags=-lm -lrt -pthread
deps := $(wildcard *.h) 
src := main.c \
       st_util.c \
	   queue_util.c  
	
objs = $(src:.c=.o)
AP:$(objs)
	gcc $(objs) $(ldflags) $(libs) $(incs) -o main.exe 

%.o:%.c
	gcc -c $^ $(ldflags) $(libs) $(incs) -o $@

clean:
	rm -f *.o .logibone_fifo.ko.cmd .logibone_fifo.mod.o.cmd .logibone_fifo.o.cmd
	rm -f *.ko .tmp_versions/*
	rm -f logibone_fifo.mod.*
	rm -f [mM]odule*
	rm -f *.exe
	rmdir .tmp_versions/