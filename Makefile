CFLAGS = -g -Wall -Wstrict-prototypes
PROGS = test-mpi-read make-2d print-2d
LDFLAGS = -lm
MCC = mpicc
CC = gcc
all: $(PROGS)
driver: MyMPI.o driver.o
	$(MCC) $(LDFLAGS) -o driver MyMPI.o
print-2d: print-2d.o
	$(CC) $(LDFLAGS) -o print-2d print-2d.o
make-2d: make-2d.o
	$(CC) $(LDFLAGS) -o make-2d make-2d.o
test-mpi-read: MyMPI.o test-mpi-read.o
	$(MCC) $(LDFLAGS) -o test-mpi-read  MyMPI.o test-mpi-read.o
print-2d.o: print-2d.c 
	$(CC) $(CFLAGS) -c print-2d.c
make-2d.o: make-2d.c
	$(CC) $(CFLAGS) -c make-2d.c
test-mpi-read.o: test-mpi-read.c MyMPI.h
	$(MCC) $(CFLAGS) -c test-mpi-read.c
MyMPI.o: MyMPI.h MyMPI.c
	$(MCC) $(CFLAGS) -c MyMPI.c
clean:
	rm -f $(PROGS) *.o core* 
clean-windows:
	del -f $(PROGS) *.o core* 