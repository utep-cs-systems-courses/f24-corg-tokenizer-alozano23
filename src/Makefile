OBJS = tokenizer.o history.o  uimain.o



CFLAGS =-g -O3 -g



all: uimain



tokenizer.o: history.h tokenizer.h 



uimain: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)



clean:
	rm -f *.o uimain



run: uimain
	./uimain
