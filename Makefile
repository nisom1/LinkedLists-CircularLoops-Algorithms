CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wunreachable-code -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) $(COVFLAGS)
OBJS = pa07.o answer07.o linkedlist.o 
VALS = valgrind --tool=memcheck --leak-check=full

pa07: $(OBJS)
	$(GCC) $(OBJS) -o $@

pa07.o: pa07.c
	$(GCC) -c $< -o $@ 

answer07.o: answer07.c answer07.h
	$(GCC) -c $< -o $@

linkedlist.o: linkedlist.c linkedlist.h
	$(GCC) -c $< -o $@

memory: pa07
	$(VALS) ./pa07
clean:
	rm -f *.o
	rm -f pa07
	rm -f *.gcda *.gcno *.gcov gmon.out
