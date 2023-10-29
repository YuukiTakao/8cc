CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

9cc: $(OBJS)
	$(CC) -o 9cc $(OBJS) $(LDFLAGS)

$(OBJS): 9cc.h

.PHONY: test
test: 9cc
	./test.sh

.PHONY: test-debug
test-debug:
	bash -x test.sh

.PHONY: clean
clean:
	rm -f 9cc *.o *~ tmp*

