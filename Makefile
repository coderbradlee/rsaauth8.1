rsaauth:CFLAGS=-std=c99  -g -o0  -L. -lpthread

rsaauth:sync.c
	gcc $(CFLAGS) sync.c  -laceclnt -orsaauth
	

clean:
	rm *.o
