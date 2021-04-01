OBJS = main.o heap.o

main: $(OBJS)
	gcc $^ -o $@

main.o:	heap.h test_heap.c
	gcc -c test_heap.c -o main.o

heap.o: heap.h heap.c
	gcc -c heap.c -o heap.o

.PHONY : clean all

all: main clean

clean:
	del *.o