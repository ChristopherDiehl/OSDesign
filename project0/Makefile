CC = gcc
CFLAGS = -g -Wall -o
DEPS = 
OBJECTS =
EXECS = time-syscall time-signal

all:
	$(CC) $(CFLAGS) time-syscall time-syscall.c $(OBJECTS) 
	$(CC) $(CFLAGS) time-signal time-signal.c $(OBJECTS) 

clean:
	rm $(EXECS)